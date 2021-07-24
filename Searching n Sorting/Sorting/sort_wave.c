// program to sort array using wave sort
#include <stdio.h>
#include <conio.h>
#define size 10

void printArray(int *, int);
void wave_sort(int *, int);
void swap(int *, int *);

int main()
{
    int arr[size], n;
    printf("\nEnter the size of array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter data : ");
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);
    wave_sort(arr, n);
    printArray(arr, n);

    return 0;
}

// wave (sine wave graph) should be made (like second element will always smaller than it's previous and next element)
void wave_sort(int arr[], int n)
{
    for (int i = 1; i < n; i += 2) // jumping to second number every time (to compare the adjectent numbers)
    {
        if (arr[i] > arr[i - 1]) // comparing with previous number (current should be smaller then previous and next )
            swap(&arr[i], &arr[i - 1]);

        if (arr[i] > arr[i + 1] && i <= n - 2) // comparing with next number (current should be smaller than next number)
            swap(&arr[i], &arr[i + 1]);        // if i reach to n - 1 (last index than error will occur when comparing with arr[i + 1]) so stop i at n - 2
    }
}

void swap(int *a, int *b)
{ // function to swap two number (call by reference)
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    printf("\n");
}