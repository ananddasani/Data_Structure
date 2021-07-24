// program to reverse a string using stack
/*              ALGO
 1) Create an empty stack.
2) One by one push all characters of string to stack.
3) One by one pop all characters from stack and put 
   them back to string.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define size 10

void push(char);
char pop();
void reverse(char s[]);

char stack[size];
int top = -1;

int main()
{
    char s[size];
    printf("\nenter the string to reverse: ");
    gets(s);
    printf("\nyou entered: %s", s);
    printf("\nreverse is: ");
    reverse(s);
    return 0;
}

int is_empty()
{
    if (top == -1)
        return 1;

    return 0;
}

int is_full()
{
    if (top == size - 1)
        return 1;

    return 0;
}

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    char ch = stack[top--];
    return ch;
}

void reverse(char s[])
{
    int i = 0, j = 0;
    char arr[20], ch;

    for (i = 0; s[i] != '\0'; i++)
        push(s[i]);

    for (j = 0; !is_empty(); j++)
    {
        ch = pop();
        printf("%c", ch);
    }
}