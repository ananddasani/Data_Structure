// program to sort array using count sort algorithm
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 100

void printArray(int *, int);
void count_sort(int *, int);
int maxInArray(int *, int);

int main()
{
    int arr[size], n;
    printf("\nEnter the size of the array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter element : ");
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);
    count_sort(arr, n);
    printArray(arr, n);

    return 0;
}

void count_sort(int arr[], int n)
{
    int maxElement = maxInArray(arr, n); // getting maximum element form the main array

    int *count = (int *)calloc((maxElement + 1), sizeof(int)); // creating second array of size maximum element we found from the main array
    int *brr = (int *)calloc(n, sizeof(int));                  // making the second array to sort the element and store in that

    // initiallizing the newly made array (count) with 0 (if we use malloc)
    // for (int i = 0; i <= maxElement; i++)
    //     count[i] = 0;

    for (int i = 0; i < n; i++)
        ++count[arr[i]]; // increment the index(element) from 0 to 1 and if the number repeat then 1 to 2 and so on...

    for (int i = 1; i <= maxElement; i++)
        count[i] += count[i - 1]; // arranging the count array in order

    for (int i = n - 1; i >= 0; i--)
        brr[--count[arr[i]]] = arr[i]; // inserting the element from main array(arr) into brr by decrementing by one first

    for (int i = 0; i < n; i++)
        arr[i] = brr[i]; // copying array brr to array arr
}

int maxInArray(int arr[], int n)
{
    int max = arr[0]; // assuming the first element of the array to be minimun element

    // finding max form the main array
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max; // returning max to make array dynamically of size of the max element
}

void printArray(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}