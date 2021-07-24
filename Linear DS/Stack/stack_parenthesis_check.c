// program to check wether the inputed string is balanced or not
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 10

int check_exp(char *);
int match(char, char);

int is_empty();
char push(char);
char pop();

struct STACK
{
    int top;
    char st[size];
} s;

int main()
{
    char exp[size];
    printf("\nenter the expression to check it is balanced or not: ");
    gets(exp);

    check_exp(exp);
    return 0;
}

int check_exp(char exp[size])
{
    s.top = -1;
    char ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
            push(exp[i]); //if any opening parentheses push on to the stack
        else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
        { //if any closing parentheses pop one parentheses from stack and it should match then fine read next
            if (!is_empty())
            {
                ch = pop();
                if (!match(ch, exp[i]))
                {
                    printf("\nmismatched parentheses are %c and %c\n", ch, exp[i]);
                    return 0;
                }
            }
            else
            { // top is -1 means no opening parentheses is pushed till now and we read closing parentheses
                printf("\nclosing parentheses for no opening parentheses :(");
                printf("\nUNBALANCED EXPRESSION\n\n");
                return 0;
            }
        }
    }

    if (!is_empty())
    { //check if any opening parentheses remaining in the stack
        printf("\nopening parentheses is more than closing :(");
        printf("\nEXPRESSION UNBALANCED\n");
        return 0;
    }
    else // if all above condition is satisfied then exp. is balanced
        printf("\nEXPRESSION IS BALANCED\n\n");
}

int is_empty()
{
    if (s.top == -1)
        return 1;

    return 0;
}

char push(char ch)
{
    return s.st[++s.top] = ch;
}

char pop()
{
    return s.st[s.top--];
}

int match(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '(' && b == ')')
        return 1;

    return 0;
}