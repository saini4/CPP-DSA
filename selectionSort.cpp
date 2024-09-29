/*
Function to perform Selection Sort.
Selection Sort repeatedly selects the smallest element from the unsorted portion
and places it at the beginning of the sorted portion.
Time Complexity:
- Worst and Average Case: O(n^2)
- Best Case: O(n^2)
Space Complexity: O(1) (in-place sorting)
*/

#include <iostream>
using namespace std;

#define SIZE 10

void selectionSort(int *arr)
{
    for (int j = 0; j < SIZE - 1; j++)
    {
        int index = j;
        for (int i = j + 1; i < SIZE; i++)
        {
            if (arr[i] < arr[index])
            {
                index = i;
            }
        }
        if (index != j)
        {
            int temp = arr[index];
            arr[index] = arr[j];
            arr[j] = temp;
        }
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

    selectionSort(arr);

    printArray(arr);

    return 0;
}
