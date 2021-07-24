// program to solve the problem of tower of hanoi
/* 
                                            ALGO

Take an example for 2 disks :
Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

Step 1 : Shift first disk from 'A' to 'B'.
Step 2 : Shift second disk from 'A' to 'C'.
Step 3 : Shift first disk from 'B' to 'C'.

The pattern here is :
Shift 'n-1' disks from 'A' to 'B'.
Shift last disk from 'A' to 'C'.
Shift 'n-1' disks from 'B' to 'C'.

*/
#include <stdio.h>
#include <conio.h>

void TOH(int, char, char, char);

int main()
{
    int n;
    char A, B, C;
    printf("\nenter the number of disk: ");
    scanf("%d", &n);

    TOH(n, 'A', 'C', 'B');
    return 0;
}

void TOH(int n, char s, char d, char aux)
{
    if (n == 1)
    { // if there is only one disk , move directly from A TO C
        printf("\nmove disk %d from peg %c to peg %c", n, s, d);
        return;
    }
    // else if there is n > 1 , then move top n - 1 disk from A to B using c
    TOH(n - 1, s, aux, d);

    // so at this point of time there is only one disk in peg s rest  of n - 1 disk we have moved so manually move that
    printf("\nmove disk %d from peg %c to peg %c", n, s, d);

    // moving remaining disk from B to C using A
    TOH(n - 1, aux, d, s);
}
