// program to perform sort  using bubble short technique
/* 
                            ALGO
ALGORITHM
Let A be a linear array of n numbers. Swap is a temporary variable for swapping (or
interchange) the position of the numbers.
1. Input n numbers of an array A
2. Initialise i = 0 and repeat through step 4 if (i < n)
3. Initialize j = 0 and repeat through step 4 if (j < n – i – 1)
4. If (A[j] > A[j + 1])
(a) Swap = A[j]
(b) A[j] = A[j + 1]
(c) A[j + 1] = Swap
5. Display the sorted numbers of array A
6. Exit.

                    time complexity
Worst case complexity : O(n2)
Best case complexity (Improved version) : O(n)
Average case complexity (Basic version) : O(n2)
Worst case space complexity : O(1) auxiliary
 */

#include <stdio.h>
#include <conio.h>
#define size 10

void bubble(int *, int);
void printArray(int *, int);
void bubbleAdaptive(int *, int);

int main()
{
    int arr[size], n;
    printf("\nenter the size of the array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter the element : ");
        scanf("%d", &arr[i]);
    }

    printf("\n\tUNSORTED ARRAY\n");
    printArray(arr, n); // printing array before sort

    bubble(arr, n); // calling the sorting function
    // bubbleAdaptive(arr, n); // calling the optimized sorting function

    printf("\n\tSORTED ARRAY \n");
    printArray(arr, n); // printing the array after sorting

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    printf("\n");
}

// NONADAPTIVE WAY (if array is already sorted then also loop will run until the last pass)
void bubble(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // running loop for passes
    {
        printf("\n\t\tpass -> %d\n", i);
        for (int j = 0; j < n - 1 - i; j++) // running loop for the comparision
        {
            if (arr[j] > arr[j + 1]) // swaping two element of array if it is not at appropriate position
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ADAPTIVE WAY (loop will ternimate as the array will sorted or array will already sorted)
void bubbleAdaptive(int arr[], int n)
{
    int temp, swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0; // if track on wether the array is sorted , if yes then termnate and return
        printf("\n\t\tpass -> %d\n", i);

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) // swaping two element of array if it is not at appropriate position
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1; // changing the value of swapped if array element has to be sorted / swapped
            }
        }
        if (!swapped)
            return; // if not swapped any of the array element it means array is sorted and no need to continue rest of iteration
    }
}