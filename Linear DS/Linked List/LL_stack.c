// program to implement stack using linked list
/* 
                                                    ALGO
        ALGORITHM FOR PUSH OPERATION
1. Input the DATA to be pushed
2. Creat a New Node
3. NewNode → DATA = DATA
4. NewNode → Next = TOP
5. TOP = NewNode
6. Exit

        ALGORITHM FOR POP OPERATION
1. if (TOP is equal to NULL)
(a) Display “The stack is empty”
2. Else
(a) TEMP = TOP
(b) Display “The popped element TOP → DATA”
(c) TOP = TOP → Next
(d) TEMP → Next = NULL
(e) Free the TEMP node
3. Exit
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * top;
typedef struct node STACK;

void push();
void pop();
void peek();
void display();
STACK *get_node();

int main()
{
    int ch;
    printf("\n\t\tSTACK IMPLEMENTION uSING LINKED LIST\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("enter your choice: ");
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
            printf("\nexiting...\n\n");
            exit(0);
            break;

        default:
            printf("\ninvalid choice :(\n");
            break;
        }
    }
    return 0;
}

STACK *get_node()
{
    STACK *temp = (STACK *)malloc(sizeof(STACK));
    temp->next = NULL;

    return temp;
}

void push()
{
    STACK *ptr = get_node();
    ptr->next = NULL;

    printf("\nenter data: ");
    scanf("%d", &ptr->data);
    ptr->next = top;
    top = ptr;

    // printf("\n%d pushed into the stack successfully !\n", ptr->data);
    display();
}

void pop()
{
    if (top == NULL)
        printf("\nSTACK UNDERFLOW\n");
    else
    {
        STACK *temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
        display();
    }
}

void peek()
{
    if (top == NULL)
        printf("\nSTACK is empty\n");
    else
        printf("\n%d is peek most element \n", top->data);
}

void display()
{
    if (top == NULL)
        printf("\nSTACK is empty\n");
    else
    {
        printf("\n");
        STACK *temp = top;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}