// program to convert infix expression to prefix expression
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define size 10

int push(char);
char pop();

int is_operator(char);
int precendency(char);

char *pre_fix(char *);
char prefix[size];

struct stack
{
    int top;
    char st[size];
} s;

int main()
{
    char infix[size];
    printf("\neneter infix expression: ");
    gets(infix);
    printf("\nINFIX EXPRESSION: %s", infix);
    printf("\nPREFIX EXPRESSION: %s", pre_fix(strrev(infix)));
    return 0;
}

int precendency(char ch)
{
    switch (ch)
    {
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

    case '$':
        return -1;
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

char *pre_fix(char infix[size])
{
    // printf("\nRECIEVED: %s",infix);
    char ch;
    int i = 0, j = 0;

    push('$');
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            prefix[j++] = infix[i];
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
                prefix[j++] = pop();
        }
    }
    do
    {
        ch = pop();
        if (ch == '$')
            break;
        prefix[j++] = ch;
    } while (ch != '$');
    prefix[j] = '\0';

    return strrev(prefix);
}