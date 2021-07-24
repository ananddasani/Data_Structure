// program to convert infix exp. to postfix exp. with parenthesis using stack
/*
                      ALGO
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty           or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
*/
#include <stdio.h>
#include <conio.h>
#define size 10

int push(char);
char pop();

int is_operator(char);
int precendency(char);

char postfix[size];
char *post_fix(char *);

struct stack
{
      int top;
      char st[size];
} s;

int main()
{
      char infix[size];
      printf("\nenter infix expression to convert in to the postfix: ");
      gets(infix);
      printf("\nINFIX EXPRESSION: %s\n", infix);
      printf("POSTFIX EXPRESSION: %s\n", post_fix(infix));
      return 0;
}

int precendency(char ch)
{
      switch (ch)
      {
      case '(':
            return 0;
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
      case '(':
      case ')':
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

char *post_fix(char infix[size])
{
      s.top = -1;
      int i = 0, j = 0;
      char ch;

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
                  if (infix[i] == ')')
                  {
                        do
                        {
                              ch = pop();
                              if (ch == '(')
                                    break;
                              postfix[j++] = ch;
                        } while (ch != '(');
                        i++;
                  }
                  else if ((infix[i] == '(') || (precendency(s.st[s.top]) < precendency(infix[i])))
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

      return postfix;
}