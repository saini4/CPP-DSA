/*
This C++ program implements the Quick Sort algorithm.

Quick Sort:
- Time Complexity: O(n log n) on average, O(n^2) in the worst case (when the pivot divides the array unevenly).
- Space Complexity: O(log n) due to recursive stack usage.
- Quick Sort is a divide-and-conquer algorithm that selects a pivot and partitions the array around the pivot.

Explanation:
- The array is partitioned such that all elements smaller than the pivot are on its left, and all larger elements are on its right.
- Recursively applies the same partitioning process to the subarrays until sorted.
*/

#include <iostream>
using namespace std;

#define SIZE 10

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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

    quickSort(arr, low, high);
    printArray(arr);

    return 0;
}
