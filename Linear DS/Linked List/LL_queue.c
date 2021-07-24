// program to implement QUEUE using linked list
/* 
                                                ALGO
        . ALGORITHM FOR PUSHING AN ELEMENT TO A QUEUE
1. Input the DATA element to be pushed
2. Create a New Node
3. NewNode → DATA = DATA
4. NewNode → Next = NULL
5. If(REAR not equal to NULL)
(a) REAR → next = NewNode;
6. REAR =NewNode;
7. Exit

        ALGORITHM FOR POPPING AN ELEMENT FROM A QUEUE
1. If (FRONT is equal to NULL)
(a) Display “The Queue is empty”
2. Else
(a) Display “The popped element is FRONT → DATA”
(b) If(FRONT is not equal to REAR)
 (i) FRONT = FRONT → Next
(c) Else
(d) FRONT = NULL;
3. Exit
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * F, *R;
typedef struct node QUEUE;

void enq();
void deq();
void display();
QUEUE *get_node();

int main()
{
    int ch;
    printf("\n\t\tQUEUE IMPLEMENTION uSING LINKED LIST\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enq();
            break;

        case 2:
            deq();
            break;

        case 3:
            display();
            break;

        case 4:
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

QUEUE *get_node()
{
    QUEUE *temp = (QUEUE *)malloc(sizeof(QUEUE));
    temp->next = NULL;

    return temp;
}

void enq()
{
    QUEUE *ptr = get_node();
    ptr->next = NULL;

    printf("\nenter data: ");
    scanf("%d", &ptr->data);

    if (F == NULL && R == NULL)
        F = R = ptr;
    else
    {
        R->next = ptr;
        R = R->next;
    }
    display();
}

void deq()
{
    if (F == NULL)
        printf("\nQUEUE UNDERFLOW\n");
    else
    {
        QUEUE *temp = F;

        F = F->next;
        temp->next = NULL;
        free(temp);
        display();

        if (F == R)
            F == NULL;
    }
}

void display()
{
    if (F == NULL)
        printf("\nQUEUE is empty\n");
    else
    {
        printf("\n");
        QUEUE *temp = F;
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}