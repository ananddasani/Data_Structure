// program to sort the array using all the sorting the algorithm
#include <stdio.h>
#include <conio.h>
#define size 10

// prototype
void swap(int *a, int *b);
void printArr(int *, int);

// sorting functions
/*
// AIM :- REPEATEDLY SWAP 2 ADJECTENT ELEMENT IF THEY ARE IN WRONG ORDER
void bubble(int arr[], int n)
{
    int swapped; // will keep track on the array is sorted or not
    for (int i = 0; i < n - 1; i++)
    { // doing n - 1 passes because remaining one element will be automatically sorted to it's right position
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {                            // n - 1 - " i " because the largest elment is already sorted to the last of the array
            if (arr[j] > arr[j + 1]) // comparing the first and next element if first is greater then swapping them
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1; // if swapping occurred then array is not sortred
            }
        }
        if (!swapped) // if swapping not occurred , means array is sorted successfully no need to iterate further
            break;
    }
}

// AIM :- INSERT AN ELEMENT FROM UNSORTED ARRAY TO IT'S CORRECT POSITION IN SORTED ARRAY
void insertion(int arr[], int n)
{
    int j, key; // storing the value which we want to locate to right place
    for (int i = 1; i < n; i++)
    {
        key = arr[i]; // every time key will be the first element of the unsorted array
        j = i - 1;    // and j is the last of element of the unsorted array (i - 1)

        while (j >= 0 && key < arr[j])
        {                        // running loop till key is at we found the right place for the key to insert in the sorted arrray
            arr[j + 1] = arr[j]; // PUSHING ELEMENT TO THE RIGHT SIDE (because to insert the key in sorted array)
            j--;
        }
        arr[j + 1] = key; // j is decremented and then condition is checked so we have to increment the j first and insert the key in the sorted array
    }
}

// AIM :- FINDING THE SMALLEST ELEMENT FORM THE FULL ARRAY AND THEN SWAPPING
void selection(int arr[], int n)
{
    int min, swapped;
    for (int i = 0; i < n - 1; i++)
    {
        min = i, swapped = 0;           // assuming the index element everytime is minimun
        for (int j = i + 1; j < n; j++) // loop for passes
        {
            if (arr[min] > arr[j]) // if assumed minumum element is greater , means we found actual small element
                min = j;           // assigning actual min. element's index to min variable
        }
        if (min != i)
        {                             // if we didn't found any other min. value than the assumed , then no need to swap unnecessarily
            swap(&arr[i], &arr[min]); // locating actual min value to it's right position
            swapped = 1;
        }
        if (!swapped) // making adaptive
            break;
    }
}
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // the lowest element of the array will be pivot all time
    int start = low + 1;  // assinging start to the next of the pivot element
    int end = high;       // and high to the last of the array

    do
    {
        while (arr[start] <= pivot) // finding the greater element form pivot
            start++;

        while (arr[end] > pivot) // finding smallest or equal element from pivot
            end--;

        if (start < end) // swapping them to their right position
            swap(&arr[start], &arr[end]);

    } while (start < end); // do until start exceed the end

    swap(&arr[low], &arr[end]); // if start exceed end then swap pivot and end

    return end; // returning the end (index) which is located at it's right place in the array
}

// AIM :-
void quick(int arr[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quick(arr, low, partitionIndex - 1);  // sorting left unsorted array
        quick(arr, partitionIndex + 1, high); // sorting right unsorted array
    }
}

int main()
{
    int arr[size], n;
    printf("\nEnter the size of the array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter the element : ");
        scanf("%d", &arr[i]);
    }

    printArr(arr, n);
    // bubble(arr, n);
    // insertion(arr, n);
    // selection(arr, n);
    quick(arr, 0, n - 1); // passing low and high with arrary
    printArr(arr, n);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
