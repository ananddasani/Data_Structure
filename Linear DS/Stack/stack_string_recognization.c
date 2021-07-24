// program to read a or b until c and then recognize the string (aca , abcba , abbcbba ....)
#include <stdio.h>
#include <conio.h>
#define size 10

char stack[size];
int top = -1;

int is_full();
int is_empty();
int push(char);
char pop();

int main()
{
    char ch, c, rec;
    printf("\n\t\tSTRING RECOGNIZATION\n");
    while (ch != 'c')
    {
        printf("enter 'a' or 'b' (c for start recognize): ");
        ch = getche();

        switch (ch)
        {
        case 'a':
        case 'b':
            push(ch);
            break;

        case 'c':
            printf("\n\tRECOGNIZATION STARTED...");
            while (1)
            {
                if (is_empty())
                { // checking if all the character poped from stacked and checked succefully
                    printf("\n\tSTRING RECOGNIZED :)\n\n");
                    break;
                    return 0; // end program
                }
                else
                {
                    printf("\neneter character: ");
                    c = getche(); // getting character for comparing wiith pevious character present in the stack
                    rec = pop();  // getting previous character present in the stack

                    switch (rec)
                    {
                    case 'a':
                        if (c != 'a')
                        {
                            printf("\nCAN'T RECOGNIZ STRING :(\n");
                            return 0;
                        }
                        break;

                    case 'b':
                        if (c != 'b')
                        {
                            printf("\nCAN'T RECOGNIZ STRING :(\n");
                            return 0;
                        }
                        break;

                    default:
                        printf("\nplease enter character 'a' or 'b' only!");
                        break;
                    } // nested switch end here
                }     // else end here
            }         // while loop end here
            break;    // case c breaks here

        default: // default of first switch
            printf("\nplease enter character 'a' or 'b' !");
            break;
        }
    }
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

int push(char ch)
{
    if (is_full())
        return 0;

    stack[++top] = ch;
    printf("\n%c pushed successfully !\n", ch);
    return 1;
}

char pop()
{
    if (is_empty())
        return 0;

    char item = stack[top--];
    return item;
}