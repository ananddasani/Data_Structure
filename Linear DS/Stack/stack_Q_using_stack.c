// program to implement the queue using two stacks by singly linked list.
/* 
                                        ALGO
A queue can be implemented using two stacks. 
Suppose STACK1 and STACK2 are the two stacks. 
When an element is pushed on to the queue, push the same on STACK1.
When an element is popped from the queue, pop all elements of STACK1 and push the same on STACK2. 
Then pop the topmost element of STACK2; which is the first (front) element to be popped from the queue. 
Then pop all elements of STACK2 and push the same on STACK1 for next operation (i.e., push or pop). 

Let queue to be implemented be q and stacks used to implement q be stack1 and stack2. q can be implemented in two ways:

Method 1 (By making enQueue operation costly) This method makes sure that oldest entered element is always at the top of stack 1, 
so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used.

enQueue(q, x):

While stack1 is not empty, push everything from stack1 to stack2.
Push x to stack1 (assuming size of stacks is unlimited).
Push everything back to stack1.
Here time complexity will be O(n)

deQueue(q):

If stack1 is empty then error
Pop an item from stack1 and return it
Here time complexity will be O(1)

Complexity Analysis:

Time Complexity:
Push operation: O(N).
In the worst case we have empty whole of stack 1 into stack 2.
Pop operation: O(1).
Same as pop operation in stack.
Auxiliary Space: O(N).
Use of stack for storing values.

Method 2 (By making deQueue operation costly)In this method, in en-queue operation, the new element is entered at the top of stack1. 
In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).
Here time complexity will be O(1)

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Here time complexity will be O(n)

Method 2 is definitely better than method 1.
Method 1 moves all the elements twice in enQueue operation,
while method 2 (in deQueue operation) moves the elements once and moves elements only if stack2 empty. 
So, the amortized complexity of the dequeue operation becomes  \Theta (1) .
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5

int s1[size];
int s1top = -1;
int s2[size];
int s2top = -1;

int is_empty(int *, int);
int is_full(int *, int);
void push(int *, int, int);
char pop(int *, int);
void display();
void enq();
void deq();

int main()
{
    int ch;
    printf("\n\tQ IMPLEMENTION BY STACKS\n\n");
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
            printf("\nexiting...\n");
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
        return 0;
    }
}

int is_empty(int *s, int top)
{
    if (top == -1)
        return 1;

    return 0;
}

int is_full(int *s, int top)
{
    if (top == size - 1)
        return 1;

    return 0;
}

void push(int *s, int ele, int top)
{
    s[++top] = ele;
}

char pop(int *s, int top)
{
    return s[top--];
}

void enq()
{
    if (is_full(s1, s1top))
        printf("\nQ OVERFLOW\n");
    else
    { // When an element is to be enqueued on to the queue, pushing the same on STACK1.
        int ele;
        printf("\nenter element: ");
        scanf("%d", &ele);

        push(s1, ele, s1top);
        printf("\n%d enqueued successfully !", ele);
    }
}

void deq()
{
    if (is_empty(s1, s1top))
        printf("\nQ UNDERFLOW\n");
    else
    { // When an element is to be dequeued from the queue, poping all elements of STACK1 and pushing on to the STACK2.
        int ele, del_val;

        while (!is_empty(s1, s1top))
        {
            ele = pop(s1, s1top);
            push(s2, ele, s2top);
        } // Then poping the topmost element of STACK2; which is the first (front) element to be deleted from the queue.
        del_val = pop(s2, s2top);
        printf("\n%d dequeued successfully !", del_val);

        while (!is_empty(s2, s2top))
        { // Then poping all elements of STACK2 and pushing them on STACK1 for next operation (i.e., push or pop).
            ele = pop(s2, s2top);
            push(s1, ele, s1top);
        }
    }
}

void display()
{
    if (is_empty(s1, s1top))
        printf("\n\tSTACK IS EMPTY !\n");
    else
    {
        printf("\n");
        for (int i = 0; i <= s1top; i++)
            printf("%d  ", s1[i]);
    }
}