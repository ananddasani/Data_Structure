// program to implement queue by struct
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 10

int q_full();
int q_empty();

void enq();
void deq();
void display();

struct QUEUE
{
    int q[size];
    int F;
    int R;
} Q;

int main()
{
    Q.F = Q.R = -1;
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
    if ((Q.F == -1) || (Q.F > Q.R))
        return 1;

    return 0;
}

int q_full()
{
    if (Q.R >= size - 1)
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

        if (Q.F == -1)
            Q.F++;
        Q.q[++Q.R] = ele;
        display();
    }
}

void deq()
{
    if (q_empty())
        printf("\nQUEUE UNDERFLOW \n");
    else
    {
        // moving front pointer
        // int ele;
        // ele = Q.q[Q.F++];

        // moving only R pointer
        for (int i = 0; i < Q.R; i++)
            Q.q[i] = Q.q[i + 1];
            Q.R--;
        display();

        if (Q.F > Q.R)
            Q.F = Q.R = -1;
    }
}

void display()
{
    printf("\n");
    if (q_empty())
        printf("\nQUEUE is empty \n");
    else
    {
        for (int i = Q.F; i <= Q.R; i++)
        {
            if (i == Q.F)
                printf("F");
            else
                printf("    ");
        }
        printf("\n");

        for (int i = Q.F; i <= Q.R; i++)
            printf("%d  ", Q.q[i]);
        printf("\n");

        for (int i = Q.F; i <= Q.R; i++)
        {
            if (i == Q.R)
                printf("R");
            else
                printf("    ");
        }
        printf("\n");
    }
}