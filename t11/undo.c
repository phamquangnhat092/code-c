#include "stack_list_int.h"
#include "stack_list_strings.h"

int_stack *s1 = NULL;
strings_stack *s2 = NULL;

void menu();

void add2Stack()
{
    printf("Input number: ");
    int x;
    scanf("%d", &x);
    push(x, &s1);
    char task[20];
    sprintf(task, "push %d", x);
    push_op(task, &s2);
    printf("\nInteger %d has been pushed to stack\n", x);
    menu();
}

void viewTop()
{
    printf("Integer on top of the stack: %d", Top(&s1));
    menu();
}

void removeFromStack()
{
    int tmp = Top(&s1);
    pop(&s1);
    printf("Integer %d has been removed from stack\n", tmp);
    char task[20];
    sprintf(task, "pop %d", tmp);
    push_op(task, &s2);
    menu();
}

void undo()
{
    char *task = Top_op(&s2);
    printf("Previous task: %s\n", task);
    printf("Undo the previous task (Y/n) ?");
    fgetc(stdin);
    char c = getchar();
    if (c == 'n') {
        exit(0);
    }
    char *data = strtok(task, " ");
    data = strtok(NULL, " ");
    int value = atoi(data);
    if (task[1] == 'u')
    {
        pop(&s1);
        pop_op(&s2);
    }
    else
    {
        pop_op(&s2);
        push(value, &s1);
    }
    menu();
}

void menu()
{
    printf("\n----------------------------------------------------------------\n");
    printf("Menu\n");
    printf("1. Add 1 integer to the stack\n");
    printf("2. View top\n");
    printf("3. Remove from the stack contains integers 1\n");
    printf("4. Undo\n");
    printf("Your selection: ");
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        add2Stack();
        break;
    case 2:
        viewTop();
        break;
    case 3:
        removeFromStack();
        break;
    case 4:
        undo();
        break;
    default:
        exit(0);
    }
}
int main()
{
    menu();
    return 0;
}