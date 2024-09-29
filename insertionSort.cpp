/*
This C++ program implements the Insertion Sort algorithm.

Insertion Sort:
- Time Complexity: O(n^2) in the worst and average cases, O(n) in the best case (already sorted array).
- Space Complexity: O(1) as it is an in-place sorting algorithm.

Explanation:
- The array is divided into a sorted and an unsorted part.
- Elements from the unsorted part are picked and placed in their correct position within the sorted part.
*/

#include <iostream>
using namespace std;

#define SIZE 10

void insertionSort(int *arr)
{
    for (int i = 1; i < SIZE; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
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

    insertionSort(arr);
    printArray(arr);

    return 0;
}
