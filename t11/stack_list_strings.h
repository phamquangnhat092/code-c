#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strings_stack_t
{
    char *element;
    struct strings_stack_t *next;
} strings_stack;

void push_op(char *element, strings_stack **top);
char *pop_op(strings_stack **top);
char *Top_op(strings_stack **top);

char *copyString(char *str)
{
    char *tmp = (char*)malloc(strlen(str) + 1);
    if (tmp)
        strcpy(tmp, str);
    return tmp;
}

void push_op(char *element, strings_stack **top)
{
    strings_stack *temp;
    temp = (strings_stack *)malloc(sizeof(strings_stack));
    if (!temp)
    {
        printf("\nHeap Overflow");
        exit(1);
    }
    temp->element = copyString(element);
    temp->next = *top;
    *top = temp;
}

int isEmpty_op(strings_stack *top)
{
    return (top == NULL);
}

char *Top_op(strings_stack **top)
{
    if (!isEmpty_op(*top))
        return (*top)->element;
    else
    {
        printf("Empty stack!");
        exit(1);
    }
}

char *pop_op(strings_stack **top)
{
    char *tmp;
    strings_stack *p;
    if (isEmpty_op(*top))
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
