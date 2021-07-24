// program to implement ascending priority queue
//in ascending P_Q only smaller elements can be deleted so we have to insert it at their respective place only at the rime of insertion only
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
    printf("\n\n\tPRIORITY QUEUE IMPLEMENTION\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT");
        printf("\nenter your choice: ");
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
    if (R == size - 1)
        return 1;

    return 0;
}

int q_empty()
{
    if (F == -1 || F > R)
        return 1;

    return 0;
}

void enq()
{
    if (q_full())
        printf("\nQUEUE OVERFLOW");
    else
    {
        int ele, i;
        printf("\nenter the element: ");
        scanf("%d", &ele);

        if (F == -1)
            F++;

        for (i = R; i >= 0 && ele < Q[i]; i--)
            Q[i + 1] = Q[i];
        Q[i + 1] = ele;
        R++;
        display();
    }
}

void deq()
{
    if (q_empty())
        printf("\nQUEUE UNDERFLOW\n");
    else
    {
        int ele = Q[F];
        if (F == R)
            F = R = -1;
        else
            F++;
        display();
    }
}

void display()
{
    if (q_empty())
        printf("\nqueue is empty\n");
    else
    {
        printf("\n");
        for (int i = F; i <= R; i++)
            printf("%d  ", Q[i]);
        printf("\n");
    }
}
