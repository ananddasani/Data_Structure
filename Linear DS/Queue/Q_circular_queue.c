// program to implement circular queue
/* 
                                            ALGO 
ENQUEUE :: 
1. Initialize FRONT = – 1; REAR = 1
2. REAR = (REAR + 1) % SIZE
3. If (FRONT is equal to REAR)
(a) Display “Queue is full”
(b) Exit
4. Else
(a) Input the value to be inserted and assign to variable “DATA”
5. If (FRONT is equal to – 1)
(a) FRONT = 0
(b) REAR = 0
6. Q[REAR] = DATA
7. Repeat steps 2 to 5 if we want to insert more elements
8. Exit

DEQUEUE ::
1. If (FRONT is equal to – 1)
(a) Display “Queue is empty”
(b) Exit
2. Else
(a) DATA = Q[FRONT]
3. If (REAR is equal to FRONT)
(a) FRONT = –1
(b) REAR = –1
4. Else
(a) FRONT = (FRONT +1) % SIZE
5. Repeat the steps 1, 2 and 3 if we want to delete more elements
6. Exit
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5

int q_full();
int q_empty();

void enq();
void deq();
void display();

int F = -1;
int R = -1;
int Q[size];

int main()
{
    int ch;
    printf("\n\t\tCIRCULAR QUEUE IMPLEMEMTION\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. enq\n2. deq\n3. display\n4. exit\n");
        printf("enter yor choice :: ");
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

int q_full()
{
    if (F == (R + 1) % size)
        return 1;

    return 0;
}

int q_empty()
{
    if (F == -1)
        return 1;

    return 0;
}

void enq()
{
    if (q_full())
        printf("\nQUEUE OVERFLOW\n");
    else
    {
        int ele;
        printf("\nenter element: ");
        scanf("%d", &ele);

        if (F == -1 && R == -1)
            F = R = 0;
        else
            R = (R + 1) % size;
        Q[R] = ele;
        display();
    }
}

void deq()
{
    if (q_empty())
        printf("\nQUEUE UNDERFLOW\n");
    else
    {
        if (F == R) // if there was one element and we want to delete it then simply reset the F & R pointer
            F = R = -1;
        else
            F = (F + 1) % size;
        display();
    }
}

void display()
{
    if (q_empty())
        printf("\nqueue is empty\n");
    else
    {
        int i;
        for (i = F; i != R; i = (i + 1) % size)
            printf("%d  ", Q[i]);
        printf("%d  ", Q[i]);
    }
}