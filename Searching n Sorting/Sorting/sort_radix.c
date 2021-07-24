// program to sort the array using radix / bin / bucket sort algorithm
/*
Let A be a linear array of n elements A [1], A [2], A [3],...... A [n]. Digit is the total
number of digits in the largest element in array A.
1. Input n number of elements in an array A.
2. Find the total number of Digits in the largest element in the array.
3. Initialise i = 1 and repeat the steps 4 and 5 until (i <= Digit).
4. Initialise the buckets j = 0 and repeat the steps (a) until ( j < n)
(a) Compare ith position of each element of the array with bucket number and
place it in the corresponding bucket.
5. Read the element(s) of the bucket from 0th bucket to 9th bucket and from first
position to higher one to generate new array A.
6. Display the sorted array A.
7. Exit.

                                            TIME COMPLEXITY 
Time Complexity: O(nd) ≈ O(n), if d is small.

Time requirement for the radix sorting method depends on the number of digits and the elements in the array.
Suppose A is an array of n elements A1, A2………..An and let r
denote the radix (for example r = 10 for decimal digits, r = 26 for English letters and r = 2 for bits). 

WORST CASE
In the worst case s = n so
f (n) = O(n2)

BEST CASE
In the best case s = logd n
So f (n) = O(n logn)

AVERAGE CASE
In the average case, it is very hard to define the time complexity. 
Because it will depend on the choice of the radix r and also the number of digits on the largest element
(i.e., number of passes) But on an average (logd n) comparison is required. So
f (n) = O(n log n)
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 10

void radix_sort(int *, int);
void count_sort(int *, int, int);
void printArray(int *, int);
int maxInArray(int *, int);

int main()
{
    int arr[size], n;
    printf("\nEnter the size of the array ::  ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element :: ");
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);
    radix_sort(arr, n);
    printArray(arr, n);

    return 0;
}

void radix_sort(int arr[size], int n)
{
    int max = maxInArray(arr, n); // finding the max element from the main array

    // pos variable shows the postition of the digit in the number (pos = 1 means unit , pos = 10 means tens , pos = 100 = hundred)
    for (int pos = 1; max / pos > 0; pos *= 10)
        count_sort(arr, n, pos); // calling count function for pos = 1 , pos = 10 , pos = 100
}

void count_sort(int arr[], int n, int pos)
{
    int count[10] = {0}; // because base of interger is 10
    int *brr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        ++count[(arr[i] / pos) % 10];

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        brr[--count[(arr[i] / pos) % 10]] = arr[i];

    for (int i = 0; i < n; i++) // copying all element from brr to original array
        arr[i] = brr[i];
}

int maxInArray(int arr[], int n)
{
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void printArray(int arr[size], int n)
{ // function to print the array
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    printf("\n");
}