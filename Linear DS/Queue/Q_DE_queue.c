// program to implement doubly ended queue by circular queue
/* 
                                    types of de_queue
There are two types of dequeue depending upon the restriction to perform insertion or
deletion operations at the two ends. They are
1. Input restricted deque
2. Output restricted deque

An input restricted deque is a deque, which allows insertion at only 1 end, rear end,
but allows deletion at both ends, rear and front end of the lists.
An output-restricted deque is a deque, which allows deletion at only one end, front
end, but allows insertion at both ends, rear and front ends, of the lists.

The possible operation performed on deque is
1. Add an element at the rear end
2. Add an element at the front end
3. Delete an element from the front end
4. Delete an element from the rear end
Only 1st, 3rd and 4th operations are performed by input-restricted deque and 1st, 2nd
and 3rd operations are performed by output-restricted deque.
 */
/* 
                                            ALGO
 INSERT AN ELEMENT AT THE RIGHT SIDE OF THE DE-QUEUE ::
 1. Input the DATA to be inserted
2. If ((left == 0 && right == MAX–1) || (left == right + 1))
(a) Display “Queue Overflow”
(b) Exit
3. If (left == –1)
(a) left = 0
(b) right = 0
4. Else
(a) if (right == MAX –1)
 (i) left = 0
(b) else
 (i) right = right+1
5. Q[right] = DATA
6. Exit
 
 INSERT AN ELEMENT AT THE LEFT SIDE OF THE DE-QUEUE
 1. Input the DATA to be inserted
2. If ((left == 0 && right == MAX–1) || (left == right+1))
(a) Display “Queue Overflow”
(b) Exit
3. If (left == – 1)
(a) Left = 0
(b) Right = 0
4. Else
(a) if (left == 0)
 (i) left = MAX – 1
(b) else
(i) left = left – 1
5. Q[left] = DATA
6. Exit

DELETE AN ELEMENT FROM THE RIGHT SIDE OF THE DE-QUEUE ::
1. If (left == – 1)
(a) Display “Queue Underflow”
(b) Exit
2. DATA = Q [right]
3. If (left == right)
(a) left = – 1
(b) right = – 1
4. Else
(a) if(right == 0)
 (i) right = MAX-1
(b) else
 (i) right = right-1
5. Exit

DELETE AN ELEMENT FROM THE LEFT SIDE OF THE DE-QUEUE ::
1. If (left == – 1)
(a) Display “Queue Underflow”
(b) Exit
2. DATA = Q [left]
3. If(left == right)
(a) left = – 1
(b) right = – 1
4. Else
(a) if (left == MAX-1)
 (i) left = 0
(b) Else
 (i) left = left +1
5. Exit
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 10

int q_full();
int q_empty();

void enq_f();
void enq_r();
void deq_f();
void deq_r();
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
        printf("\n1. ENQUEUE (FRONT)\n2. ENQUEUE (REAR)\n3. DEQUEUE (FRONT)\n4. DEQUEUE (REAR)\n5. display\n6. exit");
        printf("\nenter your choice :: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enq_f();
            break;

        case 2:
            enq_r();
            break;

        case 3:
            deq_f();
            break;

        case 4:
            deq_r();
            break;

        case 5:
            display();
            break;

        case 6:
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
    if (F == -1 && R == -1)
        return 1;

    return 0;
}

int q_full()
{
    if ((F == 0 && R == size - 1) || (F == R + 1))
        return 1;

    return 0;
}

void enq_f()
{
    if (q_full())
        printf("\nQUEUE OVERFLOW\n");
    else
    {
        int ele, i;
        printf("eneter element you want to insert from front: ");
        scanf("%d", &ele);

        if (F == -1 && R == -1)
            F = R = 0;
        else if (F == 0)
            F = size - 1;
        else
            F--;
        q[F] = ele;
        printf("\n%d enqueued successfully from front side\n", ele);
        display();
    }
}

void enq_r()
{
    if (q_full())
        printf("\nQUEUE OVERFLOW\n");
    else
    {
        int ele;
        printf("\neneter element you want to insert from front: ");
        scanf("%d", &ele);

        if (F == -1 && R == -1)
            F = R = 0;
        else if (R == size - 1)
            R = 0;
        else
            R++;
        q[R] = ele;
        printf("\n%d enqueued successfully from rear end\n", ele);
        display();
    }
}

void deq_f()
{
    if (q_empty())
        printf("\nQUEUE UNDERFLOW\n");
    else
    {
        int ele = q[F];
        printf("\n%d dequeued successfully from front side\n", ele);

        if (F == R)
            F = R = -1;
        else if (F == size - 1)
            F = 0;
        else
            F++;
        display();
    }
}

void deq_r()
{
    if (q_empty())
        printf("\nQUEUE UNDERFLOW\n");
    else
    {
        int ele = q[R];
        printf("\n%d dequeued successfully from rear end\n", ele);

        if (F == R)
            F = R = -1;
        else if (R == 0)
            R = size - 1;
        else
            R--;
        display();
    }
}

void display()
{
    if (q_empty())
        printf("\nqueue is empty\n");
    else
    {
        int i = F;
        do
        {
            printf("%d  ", q[i]);
            i = (i + 1) % size;
        } while (i <= R);
    }
}