#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define FULL 10

struct node
{
    int id;
    int mem;
    struct node *next;
};
typedef struct node node;

struct queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

void initialize(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q)
{
    return (q->front == NULL);
}

void enqueue(queue *q, int value, int mem)
{
    if (q->count < FULL)
    {
        node *tmp;
        tmp = (node*)malloc(sizeof(node));
        tmp->id = value;
        tmp->mem = mem;
        tmp->next = NULL;
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("List is full\n");
    }
}

int dequeue(queue *q)
{
    node *tmp;
    int n = q->front->id;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}

void display(node *head)
{
    while (head != NULL) {
        printf("%-20d%-20s%-20d\n", head->id, "", head->mem);
        head = head->next;
    }
}
int get_mem(node *head)
{
    return (head -> mem);
}
int get_id(node *head)
{
    return (head -> id);
}

typedef struct {
    int id;
    int mem;
} process;

queue *q;
process *p;
int n, max_mem;
int time = 0;

void menu();
void createProcess() {
    if (time == n) {
        printf("Number of process is maximum!\n");
        menu();
    }
    printf("Create new program run %d time\n", time+1);
    printf("- the memory of program: ");
    int tmp_mem, tmp_id;
    scanf("%d", &tmp_mem);
    printf("- program id: ");  
    scanf("%d", &tmp_id);
    if (tmp_mem <= max_mem) {
        p[time].id = tmp_id;
        p[time].mem = tmp_mem;
        max_mem -= tmp_mem;
        time++;
        printf("Success! Process created!\n");
    }
    else {
        enqueue(q, tmp_id, tmp_mem);
        printf("In queue! There is not enough memory (%d vs %d)\n", tmp_mem, max_mem);
    }
    menu();
}

void showStatus() {
    if (isempty(q) != 1) {
        printf("%-20s%-20s%-20s\n", "ID", "Memory", "Queue");
    }
    else {
        printf("%-20s%-20s%-20s\n", "ID", "Memory", "");
    }
    for (int i=0; i < time; i++) {
        printf("%-20d%-20d%-20s\n", p[i].id, p[i].mem, "");
    }
    display(q->front);
    menu();
}

void killProcess() {
    printf("Process ID: ");
    int tmp_id, i;
    scanf("%d", &tmp_id);
    node *head = q->front;
    for (i=0; i <= time; i++) {
        if (p[i].id == tmp_id) {
            max_mem += p[i].mem;
            for (int j=i; j < time; j++) {
                p[j].id = p[j+1].id;
                p[j].mem = p[j+1].mem;
            }
            time--;
        }
    }
    while ((head = q->front) != NULL && time < n) {
        if (get_mem(head) <= max_mem) {
            max_mem -= get_mem(head);
            p[time].id = get_id(head);
            p[time].mem = get_mem(head);
            dequeue(q);
            time++;
        }
        else break;
    }
    printf("Success\n");
    menu();
}
void menu() {
    printf("\nMenu\n");
    printf("1. Create new program run %d time\n", time+1);
    printf("2. Show the status\n");
    printf("3. Kill process\n");
    printf("4. Exit program\n");
    printf("Your choice: ");
    int x; scanf("%d", &x);
    switch(x) {
        case 1:
            createProcess();
            break;
        case 2:
            showStatus();
            break;
        case 3:
            killProcess();
            break;
        default:
            exit(0);
    }
}

int main()
{
    q = (queue*)malloc(sizeof(queue));
    initialize(q);
    printf("\nNumber of parallel processes: ");
    scanf("%d", &n);
    printf("\nMemory capacity: ");
    scanf("%d", &max_mem);
    p = (process*)malloc(sizeof(process) * n);
    menu();
    free(q);
    free(p);
    return 0;
}
