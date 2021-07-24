// program to implememnt simple queue by array
/* 
                                        ALGO
ENQUEUE ::
1. Initialize front=0 rear = –1
2. Input the value to be inserted and assign to variable “data”
3. If (rear >= SIZE)
(a) Display “Queue overflow”
(b) Exit
4. Else
(a) Rear = rear +1
5. Q[rear] = data
6. Exit

DEQUEUE ::
1. If (rear< front)
(a) Front = 0, rear = –1
(b) Display “The queue is empty”
(c) Exit
2. Else
(a) Data = Q[front]
3. Front = front +1
4. Exit
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 10

int q_full();
int q_empty();

void enq();
void deq();
void display();

int q[size];
int F = -1;
int R = -1;

int main()
{
    int ch;
    printf("\n\t\tQUEUE IMPLEMENTATION\n");
    while (1)
    {
        printf("\nMAIN MENU");
        printf("\n1. insert\n2. delete\n3. display\n4. exit");
        printf("\nenter your choice :: ");
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
            printf("\nexiting...\n");
            exit(0);
            break;

        default:
            printf("\ninvalid choice \n");
            break;
        }
    }
    return 0;
}

int q_empty()
{
    if ((F == -1) || (F > R))
        return 1;

    return 0;
}

int q_full()
{
    if (R >= size - 1)
        return 1;

    return 0;
}

void enq()
{
    if (q_full())
        printf("\nQUEUE OVERFLOW \n");
    else
    {
        int ele;
        printf("\nenter the element you want to insert in the queue :: ");
        scanf("%d", &ele);

        if (F == -1)
            F++;
        q[++R] = ele;
        printf("\n%d inserted into the queue succesfully !\n", ele);
    }
}

void deq()
{
    if (q_empty())
        printf("\nQUEUE UNDERFLOW \n");
    else
    {
        //moving F pointer
        // int ele;
        // ele = q[F++];

        // moving only R pointer
        printf("\n%d deleted from the queue succesfully !\n", q[F]);
        for (int i = F; i < R; i++)
            q[i] = q[i + 1];
        R--;

        if (F > R)
            F = R = -1;
    }
}

void display()
{
    printf("\n");
    if (q_empty())
        printf("\nQUEUE is empty \n");
    else
    {
        for (int i = F; i <= R; i++)
        {
            if (i == F)
                printf("F");
            else
                printf("    ");
        }
        printf("\n");

        for (int i = F; i <= R; i++)
            printf("%d  ", q[i]);
        printf("\n");

        for (int i = F; i <= R; i++)
        {
            if (i == R)
                printf("R");
            else
                printf("    ");
        }
        printf("\n");
    }
}