// program to convert postfix expression to infix expression
/* 
                                                Algo
1.While there are input symbol left
…1.1 Read the next symbol from the input.
2.If the symbol is an operand
…2.1 Push it onto the stack.
3.Otherwise,
…3.1 the symbol is an operator.
…3.2 Pop the top 2 values from the stack.
…3.3 Put the operator, with the values as arguments and form a string.
…3.4 Push the resulted string back to stack.
4.If there is only one value in the stack
…4.1 That value in the stack is the desired infix string.

                                                OR

1. Scan the Postfix String from Left to Right.
2. If the character is an Operand, then Push it on to the Stack.
3. If the character is an Operator, then Pop Operator 1 and Operand 2 and concatenate them using Infix notation where the Operator is in between the Two Operands.
4. The resultant expression is then pushed on the Stack
5. Repeat the above steps till the Postfix string is not scanned completely.
6. Use parantheses properly to ensure correct order for evaluating the final expression.
 */

#include <stdio.h>
#include <conio.h>
#define size 50

char infix[size];
int stack[size];
top = -1;

void INFIX(char *);
char pop();
void push(char ch);

int main()
{
    char postfix[size];
    printf("\nenter the postfix expression: ");
    gets(postfix);

    printf("\nPOSTFIX :: %s\n", postfix);
    INFIX(postfix);
    // printf("\nINFIX :: %s\n", postfix);
    return 0;
}

void INFIX(char postfix[size])
{
    int i = 0;
    char op1, op2, result[size];

    while (postfix[i] != '\0')
    {
        if (isoperand(postfix[i]))
            push(infix[i]);
        else
        {
            op2 = pop();
            op1 = pop();
        }
        i++;
    }
}

char pop()
{
    return stack[top--];
}

void push(char ch)
{
    stack[++top] = ch;
}