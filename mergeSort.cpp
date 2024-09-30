/*
This C++ program implements the Merge Sort algorithm.

Merge Sort:
- Time Complexity: O(n log n) in all cases (best, average, worst) due to the divide-and-conquer approach.
- Space Complexity: O(n) for the auxiliary space used to merge the sorted halves.
- Merge Sort is a stable and comparison-based sorting algorithm.

Explanation:
- The array is recursively divided into two halves until single elements remain.
- These halves are merged in sorted order to produce the final sorted array.
*/

#include <iostream>
using namespace std;

#define SIZE 10

void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[20];

    // Merge two sorted subarrays
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the first half
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from the second half
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the sorted elements back into the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Recursively divide the array into halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

void printArray(int *arr)
{
    cout << "Array after sorting is: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr[SIZE] = {12, 45, 8, 22, 17, 39, 7, 14, 56, 31};
    int low = 0;
    int high = SIZE - 1;

    // Perform merge sort
    mergeSort(arr, low, high);

    // Print the sorted array
    printArray(arr);

    return 0;
}
