//program to demonstrate static variable
#include <stdio.h>
#include <conio.h>

void call();

int main()
{
    for (int i = 0; i < 10; i++)
        call();

    return 0;
}

void call()
{
    static int n = 1;
    printf("%d\n", n);
    n++;
}