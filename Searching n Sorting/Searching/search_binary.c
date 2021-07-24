// program to demonstrate the binary search
#include <stdio.h>
#include <conio.h>
#define size 50

// void binary_search(int *, int, int);      // function for performing the binary search , for iteration
int binary_search(int *, int, int, int); // function for performing the binary search , for recursion

int main()
{
    int arr[size], n;
    printf("\nenter the size of array :: ");
    scanf("%d", &n); // taking the size of the array

    for (int i = 0; i < n; i++)
    {
        printf("enter element : ");
        scanf("%d", &arr[i]);
    }

    int key;
    printf("\nEnter the element you want to search in the array :: ");
    scanf("%d", &key);

    // binary_search(arr, n, key); // passig the array , size and element which user want ot search
    int ans = binary_search(arr, 0, n - 1, key);

    if (ans == -1)
        printf("key is not present in the array :(");
    else
        printf("key present in the array at postion :: %d", ans + 1);

    return 0;
}

// using the iteration
// void binary_search(int a[size], int n, int key)
// {
//     // we will always compare the key with mid only
//     int mid, low = 0, high = n - 1, found = 0;

//     while ((low <= high) && !found)
//     {
//         mid = (low + high) / 2; // allocating the middle position to the mid variable

//         if (a[mid] == key) // comparing the mid with the key
//             found = 1;
//         else if (key > a[mid]) // if key is greater than the middle element of the array then simply
//             low = mid + 1;     // make low as mid + 1 because if element is grater than no need of left part of the array
//         else
//             high = mid - 1; // if key is smaller then the middle element of the array then no need of right part of array
//     }

//     if (found)
//         printf("\n%d present at location %d\n", key, mid + 1);
//     else
//         printf("\n%d not present :(\n", key);
// }

// using recursion
int binary_search(int arr[], int low, int high, int key)
{
    if (low <= high) // if no element present then return
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (key > arr[mid])
            return binary_search(arr, mid + 1, high, key);
        else
            return binary_search(arr, low, mid - 1, key);
    }
    return -1;
}
