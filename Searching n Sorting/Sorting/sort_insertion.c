// program to sort the array using unsetion short algorithm
/* 
Time Complexity: O(n*2)

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order.
 And it takes minimum time (Order of n) when elements are already sorted.

Algorithmic Paradigm: Incremental Approach
Sorting In Place: Yes
Stable: Yes
Online: Yes

Uses: Insertion sort is used when number of elements is small. 
It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.


                                                        ALGO
To sort an array of size n in ascending order:
1: Iterate from arr[1] to arr[n] over the array.
2: Compare the current element (key) to its predecessor.
3: If the key element is smaller than its predecessor, compare it to the elements before.
 Move the greater elements one position up to make space for the swapped element.

                                                    OR
                                                    
 1. Input an array A of n numbers
2. Initialize i = 1 and repeat through steps 4 by incrementing i by one.
(a) If (i < = n – 1)
(b) Swap = A [I],
(c) Pos = i – 1
3. Repeat the step 3 if (Swap < A[Pos] and (Pos >= 0))
(a) A [Pos+1] = A [Pos]
(b) Pos = Pos-1
4. A [Pos +1] = Swap
5. Exit

 */
#include <stdio.h>
#include <conio.h>
#define size 10

void printArray(int *, int);
void insertion(int *, int);

int main()
{
    int arr[size], n;
    printf("\nEnter the size of the array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the element : ");
        scanf("%d", &arr[i]);
    }

    printArray(arr, n); // printing array before sorting
    insertion(arr, n);  // calling the sorting function
    printArray(arr, n); // printing array after sorting

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    printf("\n");
}

void insertion(int arr[], int n)
{
    // key for the targeted element
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i]; // assigning the second element of the array assuming the first element is sorted
        j = i - 1;    // assigning the fist element of the array to compare it with the key

        while (j >= 0 && key < arr[j]) // not simply swaping but checking the previous element also
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // placing the key to it's correct position in sorted array by first increment j by 1 (because is j is decremented by 1 and then condition is checked)
    }
}