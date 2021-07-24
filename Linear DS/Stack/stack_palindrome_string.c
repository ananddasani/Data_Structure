/*
Q.    check whwther the string is palindrome or not

 A.                               APPROCH
-->  Find the length of the string say len. Now, find the mid as mid = len / 2.
--> Push all the elements till mid into the stack i.e. str[0…mid-1].
--> If the length of the string is odd then neglect the middle character.
--> Till the end of the string, keep popping elements from the stack and compare it with the current character i.e. string[i].
--> If there is mismatch then the string is not a palindrome. If all the elements match then the string is a palindrome. 
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define size 10

char *stack;
int top = -1;

void push(char);
char pop();

int palindrome(char s[]);

int main()
{
    char str[size];
    printf("\nenter the string to check it is palindrome or not: ");
    gets(str);

    if (palindrome(str))
        printf("\nSTRING IS PALINDROME\n");
    else
        printf("\nSTRING NOT IS PALINDROME\n");
    return 0;
}

int palindrome(char s[])
{
    char character;
    int flag = 1, i, j, mid, len;

    len = strlen(s);
    stack = (char *)malloc(len * sizeof(char));
    mid = len / 2;

    for (i = 0; i < mid; i++)
        push(s[i]); // Pushing all the elements till mid into the stack

    if (len % 2 != 0)
        i++; // If the length of the string is odd then neglecting the middle character.

    while (s[i] != '\0')
    { // Till the end of the string, popping elements from the stack and comparing it with the current character i.e. s[i].
        character = pop();
        if (character != s[i]) // If there is mismatch then the string is not a palindrome.
            return 0;
        i++;
    }
    // If all the elements match then the string is a palindrome.
    return 1;
}

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}