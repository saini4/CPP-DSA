/*
Program Description:
--------------------
This program implements the **Counting Sort** algorithm to sort an array of integers.
Counting sort is a non-comparative sorting algorithm that works by counting the occurrences of each unique value in the input array. These counts are then used to place the elements in the correct position in the output array.

Time Complexity:
----------------
- Best, Average, Worst Case Time Complexity: O(n + k), where:
    - `n` is the number of elements in the input array.
    - `k` is the range of input values (i.e., the maximum value in the array).

Space Complexity:
-----------------
- Space Complexity: O(n + k), due to the need for an additional counting array to store the counts of each element.
*/

#include <iostream>
using namespace std;

#define SIZE 6

void countSort(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    int j = 0;
    int k = 0;
    while (j <= max)
    {
        if (count[j] > 0)
        {
            arr[k] = j;
            k++;
            count[j]--;
        }
        else
        {
            j++;
        }
    }

    free(count);
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
    int arr[SIZE] = {6, 4, 8, 2, 2, 7};

    countSort(arr, SIZE);

    printArray(arr);

    return 0;
}
