// program to sort array using merge sort algorithm
/*
                                            ALGO

Let A be a linear array of size n, A [1], A [2], A [3] ...... A [n], l1 and u1 represent lower
and upper bounds of the first sub-array and l2 and u2 represent the lower and upper
bound of the second sub-array. Aux is an auxiliary array of size n. Size is the sizes of
merge files.
1. Input an array of n elements to be sorted
2. Size = 1
3. Repeat through the step 13 while (Size < n)
(a) set l1 = 0; k = 0
4. Repeat through step 10 while ((l1+Size) < n)
(a) l2 = l1+Size
(b) u1 = l2–1
5. If ((l2+Size–1) < n)
(i) u2 = l2+Size–1
(b) Else
 (i) u2 = n-1
6. Initialize i = l1; j = l2 and repeat through step 7 if (i <= u1) and ( j < = u2)
7. If (A [i] < = A[j])
(i) Aux [k] = A [i++]
(b) Else
 (i) Aux [k] = A [j++]
8. Repeat the step 8 by incrementing the value of k until (i < = u1)
(a) Aux [k] = A [I++]
9. Repeat the step 9 by incrementing the value of k until ( j < = u2)
(a) Aux [k] = A [ j++]
10. L1=u2+1
11. Initialize I = l1 and repeat the step 11 if (k < n) by incrementing I by one
(a) Aux [k++] = A[I]
12. Initialize I=0 and repeat the step 12 if (I < n) by incrementing I by one
(a) A [i] = A [I]
13. Size = Size*2
14. Exit

                                    TIME COMPLEXITY 
Let f (n) denote the number of comparisons needed to sort an n element array A
using the merge sort algorithm. The algorithm requires almost log n passes, each involving
n or fewer comparisons.
In average and worst case the merge sort requires O(n log n ) comparisons.
The main drawback of merge sort is that it requires O(n) additional space for the
auxiliary array
*/
#include <stdio.h>
#include <conio.h>
#define size 50

void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void printArr(int *, int);

int main()
{
    int arr[size], n;
    printf("\nEnter the size of array :: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter element : ");
        scanf("%d", &arr[i]);
    }

    printArr(arr, n);
    merge_sort(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}

// function to divide the array
void merge_sort(int arr[], int low, int high)
{
    int mid = (low + high) / 2; // calculating mid to divide array in equal part everytime

    if (low < high) // there must be two element in the array
    {
        merge_sort(arr, low, mid);      // sorting left subarray
        merge_sort(arr, mid + 1, high); // sorting right subarray

        merge(arr, low, mid, high); // merging the sorted arrays
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;     // assigning i to the start of array 1 which is passed
    int j = mid + 1; // assigning j to the start of array 2 which is passed
    int k = low;     // k for index of new array
    int brr[size];   // making new array to making two sotred array in to 1

    while (i <= mid && j <= high) // running loop till one of the array's element is successfully inserted
    {                             // if one of the array is fully inserted in brr then we can simply insert rest of the element without checking any condition
        if (arr[i] <= arr[j])     // comparing element of both array and inserting the smaller one element in the new array (brr)
        {                         // if arr[i] is smaller then inserting i and incrementing it
            brr[k] = arr[i];
            i++;
            k++;
        }
        else
        { // same of j
            brr[k] = arr[j];
            j++;
            k++;
        }
    }

    // checking if any element remaining to insert on brr
    if (i > mid)
    { // i reached the end of arr1 then check for j and if any element is there than simply put in brr
        while (j <= high)
        {
            brr[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    { // if j is at the end than check i and if any element remaining than simply put in brr
        while (i <= mid)
        {
            brr[k] = arr[i];
            i++;
            k++;
        }
    }
    // now copying all the element of the brr to the original array (arr)
    for (int i = 0; i <= high; i++) // starting form low to high (high - 1 was passed from main so i <= high)
        arr[i] = brr[i];
}

void printArr(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
