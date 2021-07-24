// program to convert decimal to OCTAL
#include <stdio.h>
#include <conio.h>
#define size 50

int st[size];
int top = -1;

void push(int);
int pop();
int isempty();
int isfull();

int main()
{
    int num, n, r;
    printf("\nenter decimal number: ");
    scanf("%d", &num);

    n = num;
    while (n >= 1)
    {
        r = n % 8;
        push(r);
        n = n / 8;
    }

    printf("\nDECIMAL :: %d\n", num);
    printf("OCTAL     :: ");

    while (!isempty())
        printf("%d", pop());

    return 0;
}

int isempty()
{
    if (top == -1)
        return 1;

    return 0;
}

int isfull()
{
    if (top == size - 1)
        return 1;

    return 0;
}

void push(int r)
{
    if (isfull())
        printf("\nSTACK OVERFLOW\n");
    else
        st[++top] = r;
}

int pop()
{
    if (isempty())
        printf("\nSTACK UNDERFLOW\n");
    else
        return st[top--];
}