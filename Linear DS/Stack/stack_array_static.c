// program to implement stack by simple array
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
#define size 5

int is_empty();
int is_full();

void push();
void pop();
void peek();
void change();
void display();

int stack[size];
int top = -1;

int main()
{
    int ch;
    printf("\n\t\tSTACK IMPLEMENTATION\n");
    while (1)
    {
        printf("\nMAIN MENU:\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. CHANGE\n6. EXIT");
        printf("\nenter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            change();
            break;

        case 6:
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

int is_full()
{
    if (top == size - 1)
        return 1;

    return 0;
}

void push()
{
    int item;
    if (is_full())
        printf("\n\tSTACK OVERFLOW !\n");
    else
    {
        printf("\nenter element you want to push: ");
        scanf("%d", &item);

        stack[++top] = item;
        // printf("\n%d pushed into the stack successfully !\n", item);
        display();
    }
}

void pop()
{
    int item;
    if (is_empty())
        printf("\n\tSTACK UNDERFLOW !\n");
    else
    {
        item = stack[top--];
        // printf("\n%d popped successfully !\n", item);
        display();
    }
}

void peek()
{
    int item;
    if (is_empty())
        printf("\n\tSTACK UNDERFLOW !\n");
    else
    {
        item = stack[top];
        printf("\n%d is peek element !\n", item);
    }
}

void change()
{
    if (is_empty())
        printf("\nstack is empty can't perform exancge operation :(\n\n");
    else
    {
        int ele, found = 0, val;
        printf("\nenter the element you want to change: ");
        scanf("%d", &ele);

        for (int i = top; i >= 0; i--)
        {
            if (ele == stack[i])
            {
                printf("\neneter the new value: ");
                scanf("%d", &val);
                stack[i] = val;
                display();

                found = 1;
                break;
            }
        }
        if (!found)
            printf("\n%d not present in stack :(\n", ele);
    }
}

void display()
{
    if (is_empty())
        printf("\n\tSTACK IS EMPTY !\n");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}