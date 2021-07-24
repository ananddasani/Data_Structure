// program to implement srtack using structure
/*
                      ALGO
PUSH::
1. If TOP = SIZE – 1, then:
(a) Display “The stack is in overflow condition”
(b) Exit
2. TOP = TOP + 1
3. STACK [TOP] = ITEM
4. Exit

POP::
1. If TOP < 0, then
(a) Display “The Stack is empty”
(b) Exit
2. Else remove the Top most element
3. DATA = STACK[TOP]
4. TOP = TOP – 1
5. Exit
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 10

struct stack
{
    int top;
    int st[size];
};
typedef struct stack STACK;

int is_empty(STACK *);
int is_full(STACK *);
void push(STACK *);
void pop(STACK *);
void peek(STACK *);
void display(STACK *);

int main()
{
    int ch;
    STACK *sp = (STACK *)malloc(sizeof(STACK));
    sp->top = -1;

    printf("\n\t\tSTACK IMPLEMENTATION\n");
    while (1)
    {
        printf("\nMAIN MENU:\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("\nenter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(sp);
            break;

        case 2:
            pop(sp);
            break;

        case 3:
            peek(sp);
            break;

        case 4:
            display(sp);
            break;

        case 5:
            printf("\nexiting...");
            exit(0);
            break;

        default:
            printf("\ninvalid choice !\n\n");
            break;
        }
    }
    return 0;
}

int is_empty(STACK *em)
{
    if (em->top == -1)
        return 1;

    return 0;
}

int is_full(STACK *fu)
{
    if (fu->top == size - 1)
        return 1;

    return 0;
}

void push(STACK *pu)
{
    if (is_full(pu))
        printf("\n\tSTACK OVERFLOW !\n");
    else
    {
        int item;
        printf("\nenter element you want to push: ");
        scanf("%d", &item);

        pu->st[++pu->top] = item;
        // printf("\n%d pushed into the stack successfully !\n", item);
        display(pu);
    }
}

void pop(STACK *po)
{
    if (is_empty(po))
        printf("\n\tSTACK UNDERFLOW !\n");
    else
    {
        int item = po->st[po->top--];
        // printf("\n%d popped successfully !\n", item);
        display(po);
    }
}

void peek(STACK *pe)
{
    if (is_empty(pe))
        printf("\n\tSTACK UNDERFLOW !\n");
    else
    {
        int item = pe->st[pe->top];
        printf("\n%d is peek element !\n", item);
    }
}

void display(STACK *di)
{
    if (is_empty(di))
        printf("\n\tSTACK IS EMPTY !\n");
    else
    {
        for (int i = di->top; i >= 0; i--)
            printf("%d\n", di->st[i]);
    }
}