// program to sort array using selection sort algorithm
/*
                                                ALGO
1. Input n numbers of an array A
2. Initialize i = 0 and repeat through step5 if (i < n – 1)
(a) min = a[i]
(b) loc = i
3. Initialize j = i + 1 and repeat through step 4 if (j < n – 1)
4. if (a[j] < min)
(a) min = a[j]
(b) loc = j
5. if (loc ! = i)
(a) swap = a[i]
(b) a[i] = a[loc]
(c) a[loc] = swap
6. display “the sorted numbers of array A”
7. Exit

                                    TIME COMPLEXITY 
Best case   n – 1 = O(n)
Worst case   n (n − 1) / 2  = O(n2)
Average case  O(n)
*/
#include <stdio.h>
#include <conio.h>
#define size 10

void selection(int *, int);
void printArray(int *, int);
void swap(int *, int *);

int main()
{
    int arr[size], n;
    printf("\nEnter the size of array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element :: ");
        scanf("%d", &arr[i]);
    }
    printf("\n");

    printArray(arr, n); // printing array before sort
    selection(arr, n);  // calling sort function
    printArray(arr, n); // printing array after sort

    return 0;
}

void selection(int arr[size], int n)
{
    int temp, min, j;
    for (int i = 0; i < n - 1; i++) // loop for passes
    {
        min = i;                    // assuming the index element as a minumum value in the array
        for (j = i + 1; j < n; j++) // loop for comparision
        {
            if (arr[j] < arr[min]) // getting the minimum element for swapping
                min = j;
        } // don't swap here , either it become bubble sort .......

        if (min != i) // swapping after checking for min. element in whole array
        {             // no need to swap if we didn't find any smaller element
            swap(&arr[i], &arr[min]);
            // temp = arr[i];
            // arr[i] = arr[min]; // swapping the assumed min. value with actual min. value
            // arr[min] = temp;
        }
    }
}

void swap(int *a, int *b)
{ // swapping two value by reference
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{ // printing the array
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    printf("\n");
}