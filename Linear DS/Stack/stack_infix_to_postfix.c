// program to convert infix to postfix
#include <stdio.h>
#include <conio.h>
#define size 100

int push(char);
char pop();

int is_operator(char);
int precendency(char);
char *post_fix(char infix[]);

struct stack
{
    int top;
    char st[size];
} s;
char postfix[size];

int main()
{
    char infix[size];
    printf("\nenter the infix string to convert it to postfix: ");
    gets(infix);
    printf("\nINFIX EXPRESSION: %s\n", infix);
    printf("\nPOSTFIX EXPRESSION: %s\n", post_fix(infix));
    return 0;
}

int precendency(char ch)
{
    switch (ch)
    {
    case '$':
        return -1;
        break;

    case '+':
    case '-':
        return 1;
        break;

    case '*':
    case '/':
    case '%':
        return 2;
        break;

    case '^':
        return 3;
        break;

    default:
        return 0;
        break;
    }
}

int is_operator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '%':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

int push(char ch)
{
    return s.st[++s.top] = ch;
}

char pop()
{
    return s.st[s.top--];
}

char *post_fix(char infix[])
{
    char ch;
    int i = 0, j = 0;

    push('$');
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j++] = infix[i];
            i++;
        }
        else
        {
            if (precendency(s.st[s.top]) < precendency(infix[i]))
            {
                push(infix[i]);
                i++;
            }
            else
                postfix[j++] = pop();
        }
    }
    do
    {
        ch = pop();
        if (ch == '$')
            break;
        postfix[j++] = ch;
    } while (ch != '$');
    postfix[j] = '\0';

    return postfix;
}