/*
Function to perform Bubble Sort.
Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.
Time Complexity:
- Worst and Average Case: O(n^2)
- Best Case: O(n) (with an optimized version)
Space Complexity: O(1) (in-place sorting)
*/

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#define SIZE 10

void bubbleSort(int *arr)
{
    int temp;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
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
    int arr[10] = {12, 45, 8, 22, 17, 39, 7, 14, 56, 31};
    bubbleSort(arr);
    printArray(arr);

    return 0;
}
