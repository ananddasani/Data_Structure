// program to implement stack dynamically allocating memory
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
(a) Display "The Stack is empty"
(b) Exit
2. Else remove the Top most element
3. DATA = STACK[TOP]
4. TOP = TOP - 1
5. Exit
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int is_empty();
int is_full(int);

void push(int size, int *stack);
void pop(int *stack);
void peek(int *stack);
void display(int *stack);

int top = -1;

int main()
{
    int *stack, size, ch;
    printf("\nenter the size of stack you want: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));
    if (stack == NULL)
    {
        printf("\nunable to allocate memory :(\n\n");
        return 0;
    }

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
            push(size, stack);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            peek(stack);
            break;

        case 4:
            display(stack);
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

int is_empty()
{
    if (top == -1)
        return 1;

    return 0;
}

int is_full(int size)
{
    if (top == size - 1)
        return 1;

    return 0;
}

void push(int size, int *stack)
{
    int item;
    if (is_full(size))
    {
        printf("\n\tSTACK OVERFLOW !\n");
        return;
    }
    else
    {
        printf("\nenter element you want to push: ");
        scanf("%d", &item);

        stack[++top] = item;
        display(stack);
    }
}

void pop(int *stack)
{
    int item;
    if (is_empty())
    {
        printf("\n\tSTACK UNDERFLOW !\n");
        return;
    }
    else
    {
        item = stack[top--];
        display(stack);
    }
}

void peek(int *stack)
{
    int item;
    if (is_empty())
    {
        printf("\n\tSTACK UNDERFLOW !\n");
        return;
    }
    else
    {
        item = stack[top];
        printf("\n%d is peek element !\n", item);
    }
}

void display(int *stack)
{
    if (is_empty())
    {
        printf("\n\tSTACK IS EMPTY !\n");
        return;
    }
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}