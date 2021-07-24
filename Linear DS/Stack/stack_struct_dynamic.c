// program to implement stack dynamically alocating memory by structure

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *st;
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

    printf("\nenter the size of stack you want: ");
    scanf("%d", &sp->size);

    sp->st = (int *)malloc(sp->size * sizeof(int));

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
    if (fu->top == fu->size - 1)
        return 1;

    return 0;
}

void push(STACK *pu)
{
    if (is_full(pu))
    {
        printf("\nSTACK OVERFLOW !\n\n");
        return;
    }
    printf("\neneter the element you want to push into the stack: ");
    scanf("%d", &pu->st[++pu->top]);
    display(pu);
}

void pop(STACK *po)
{
    if (is_empty(po))
    {
        printf("\nSTACK UNDERFLOW !\n\n");
        return;
    }
    po->st[po->top--];
    display(po);
}

void peek(STACK *pe)
{
    if (is_empty(pe))
    {
        printf("\nSTACK IS EMPTY !\n\n");
        return;
    }
    printf("%d is the peek element !\n", pe->st[pe->top]);
}

void display(STACK *di)
{
    if (is_empty(di))
    {
        printf("\nSTACK IS EMPTY !\n\n");
        return;
    }
    for (int i = di->top; i >= 0; i--)
        printf("%d\n", di->st[i]);
}