#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct int_stack_t{
    int element;
    struct int_stack_t *next;
} int_stack;
 
void push(int element, int_stack **top);
int pop(int_stack **top);
int Top(int_stack **top);
void freeStack(int_stack **top);

void initialize(int_stack **p) {
    *p = NULL;
}

void push(int element, int_stack **top)
{
    int_stack* temp;
    temp =(int_stack*)malloc(sizeof(int_stack));
    if (!temp)
    {
        printf("\nHeap Overflow");
        exit(1);
    }
    temp->element = element;
    temp->next = *top;
    *top = temp;
}
 
int isEmpty(int_stack *top)
{
    return (top == NULL);
}
 
int Top(int_stack **top)
{
    if (!isEmpty(*top))
        return (*top)->element;
    else
    {
        printf("Empty stack!");
        exit(1);
    }
    
}
 
int pop(int_stack **top)
{   
    int tmp;
    int_stack* p;
    if (isEmpty(*top))
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    else
    {
        tmp = (*top)->element;
        p = *top;
        *top = (*top)->next;
        free(p);
        return tmp;
    }
}

// giải phóng list
void freeStack(int_stack **top){
    int_stack *to_free = *top;
    while(to_free!=NULL){
        *top = (*top)->next;
        free(to_free);
        to_free = *top;
    }
}

