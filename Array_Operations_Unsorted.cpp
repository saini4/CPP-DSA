/*
 * Basic Array Manipulation Program (Unsorted Array)
 *
 * This program demonstrates basic array manipulation in C++ with functionalities to:
 * 1. Insert an element at a specified index in the array.
 * 2. Delete an element from a specified index in the array.
 * 3. Print the current elements of the array.
 * 4. Search for an element in the array and return its index.
 *
 * The program uses a class `MyArray` that contains methods for:
 * - `insertAt`: Inserts a new element, shifting subsequent elements.
 * - `deleteAt`: Removes an element, shifting remaining elements.
 * - `printArr`: Displays the elements of the array.
 * - `search`: Searches for an element and returns its index.
 *
 * Time Complexities:
 * - Insertion: O(n)
 * - Deletion: O(n)
 * - Searching: O(n) (linear search)
 * - Printing: O(n)
 *
 * Space Complexity:
 * - O(1) (excluding the input array).
 */

#include <iostream>

class MyArray
{
public:
    int search(int arr[], int size, int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    void deleteAt(int arr[], int &size, int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void insertAt(int arr[], int element, int &size, int index)
    {
        if (index < 0 || index > size)
        {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        size++;
    }

    void printArr(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << "\t";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int arr[15] = {44, 10, 20, 15, 40, 50, 45, 70, 21, 3};
    int size = 10;
    MyArray myArr;

    myArr.printArr(arr, size);

    int element = 37;
    int index;

    std::cout << "Enter the index for insertion:" << std::endl;
    std::cin >> index;
    myArr.insertAt(arr, element, size, index);
    myArr.printArr(arr, size);

    std::cout << "Enter the index for deletion:" << std::endl;
    std::cin >> index;
    myArr.deleteAt(arr, size, index);
    myArr.printArr(arr, size);

    int key;
    std::cout << "Enter the key you need the index for:" << std::endl;
    std::cin >> key;
    int searchedIndex = myArr.search(arr, size, key);
    if (searchedIndex == -1)
    {
        std::cout << "Element not found" << std::endl;
    }
    else
    {
        std::cout << "Element found at index: " << searchedIndex << std::endl;
    }

    return 0;
}
