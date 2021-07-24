// program to evaluate the string using stack
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define size 100

int push(int);
int pop();
int is_operator(char);
int evaluate(char *);

struct stack
{
    int top;
    int st[size];
} s;

int main()
{
    char exp[size];
    printf("\nenter the expression to evaluate: ");
    gets(exp);
    printf("\nEVALUATION: %s = %d", exp, evaluate(exp));
    return 0;
}

int push(int n)
{
    return s.st[++s.top] = n;
}

int pop()
{
    return s.st[s.top--];
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

int evaluate(char exp[size])
{
    s.top = -1;
    int i = 0, op1, op2;

    while (exp[i] != '\0')
    {

        if (!is_operator(exp[i]))
            push(exp[i] - 48); // char will converted into perticular number
        else
        {
            op1 = pop();
            op2 = pop();
            switch (exp[i])
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                push(op1 / op2);
                break;

            case '%':
                push(op1 % op2);
                break;

            case '^':
                push(pow(op1, op2));
                break;
            }
        }
        i++;
    }
    return pop();
}