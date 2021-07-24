// program to sort the array using quick sort algorithm
/*
                                            ALGO

Let A be a linear array of n elements A (1), A (2), A (3)......A (n), low represents the
lower bound pointer and up represents the upper bound pointer. Key represents the first
element of the array, which is going to become the middle element of the sub-arrays.
1. Input n number of elements in an array A
2. Initialize low = 2, up = n , key = A[(low + up)/2]
3. Repeat through step 8 while (low < = up)
4. Repeat step 5 while(A [low] > key)
5. low = low + 1
6. Repeat step 7 while(A [up] < key)
7. up = up–1
8. If (low < = up)
(a) Swap = A [low]
(b) A [low] = A [up]
(c) A [up] = swap
(d) low=low+1
(e) up=up–1
9. If (1 < up) Quick sort (A, 1, up)
10. If (low < n) Quick sort (A, low, n)
11. Exit
                                        TIME COMPLEXITY

WORST CASE 
The worst case occurs when the list is already sorted. In this case the given array is
partitioned into two sub arrays. One of them is an empty array and another one is an
array. After partition, when the first element is checked with other element, it will take n
comparison to recognize that it remain in the position so as (n – 1) comparisons for the
second position
f (n) = n + (n – 1) + ...... + 2 + 1
= (n (n + 1))/2
= O(n2)

AVG. CASE
AVERAGE CASE
In this case each reduction step of the algorithm produces two sub arrays. Accordingly :
(a) Reducing the array by placing one element and produces two sub arrays.
(b) Reducing the two sub-arrays by placing two elements and produces four subarrays.
(c) Reducing the four sub-arrays by placing four elements and produces eight subarrays.
And so on. Reduction step in the kth level finds the location at 2k–1 elements; however there will be approximately log2 n levels at reduction steps. Furthermore each level
uses at most n comparisons,
so f (n) = O(n log n)

BEST CASE
The base case analysis occurs when the array is always partitioned in half, That key
= A [(low+up)/2]
f (n) = Cn +f (n/2) + f (n/2)
= Cn + 2f (n/2)
= O(n) where C is a constant.
*/
#include <stdio.h>
#include <conio.h>
#define size 10

int partion(int *, int, int);
void quickSort(int *, int, int);
void printArray(int *, int);

int main()
{
    int arr[size], n;
    printf("\nEnter the size of the array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element :: ");
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);       // printing the array before sorting
    quickSort(arr, 0, n - 1); // calling the sorting function , passing low as 0 and high as n - 1
    printArray(arr, n);       // printing the array after sorting

    return 0;
}

int partion(int arr[], int low, int high)
{
    int pivot = arr[low];            // pivot is the element which we will kept at it's right position everytime
    int start = low + 1, end = high; // initilazing the start and end variable to the start and end of the array

    do // atleast one time we have to run the loop
    {
        while (arr[start] <= pivot)
            start++; // finding the only large element then pivot (equal element not needed)

        while (arr[end] > pivot)
            end--; // finding the smaller or equal to element than pivot

        if (start < end)
        { // if start doesn't exceed the end pointer then swap the start and end
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    } while (start < end);

    // if start exceed the end pointer than swap the pivot with end (keep pivot at it's right postion)
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;

    return end; // returning the right postion of the pivot (means dividing the array into to subarray , right to pivot and left to pivot)
}

void quickSort(int arr[], int low, int high)
{
    int partionIndex;

    if (low < high) // base condition of the recursion ,if low exceed the high then array is sorted
    {
        partionIndex = partion(arr, low, high); // getting the left unsorted array and right unsorted array
        quickSort(arr, low, partionIndex - 1);  // will sort left
        quickSort(arr, partionIndex + 1, high); // will sort right
    }
}

void printArray(int arr[size], int n)
{ // function to print the array
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    printf("\n");
}