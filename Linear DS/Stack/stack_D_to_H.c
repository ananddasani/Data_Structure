// program to convert decimal to binary
#include <stdio.h>
#include <conio.h>
#define size 50

char st[size];
int top = -1;

void push(char);
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
        r = n % 16;
        if (r < 10)
            push(r + 48);
        else
            push(r + 55);
        n = n / 16;
    }

    printf("\nDECIMAL        :: %d\n", num);
    printf("HEXADECIMAL    :: ");

    while (!isempty())
        printf("%c", pop());

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

void push(char r)
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