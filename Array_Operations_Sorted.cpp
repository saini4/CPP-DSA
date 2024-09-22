#include <iostream>

class MyArray
{
public:
    int search(int arr[], int low, int high, int key)
    {
        if (high >= low)
        {
            int mid = (low + high) / 2;
            if (key == arr[mid])
            {
                return mid;
            }
            if (key < arr[mid])
            {
                return search(arr, low, mid - 1, key);
            }
            return search(arr, mid + 1, high, key);
        }
        return -1;
    }

    void deleteAt(int arr[], int &size, int element)
    {
        int index = 0;
        while (index < size && arr[index] < element)
        {
            index++;
        }
        if (index < size && arr[index] == element)
        {
            for (int i = index; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
        }
        else
        {
            std::cout << "Element not found for deletion." << std::endl;
        }
    }

    void insertAt(int arr[], int element, int &size)
    {
        if (size >= 15)
        {
            std::cout << "Array is full, cannot insert." << std::endl;
            return;
        }

        int index = 0;
        while (index < size && arr[index] < element)
        {
            index++;
        }
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        size++;
    }

    void printArr(const int arr[], int size)
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
    int arr[15] = {1, 12, 23, 34, 45, 56, 67, 78, 89, 100};
    int size = 10;
    MyArray myArr;

    myArr.printArr(arr, size);

    int element;
    std::cout << "Enter the element you want to insert:" << std::endl;
    std::cin >> element;

    myArr.insertAt(arr, element, size);
    myArr.printArr(arr, size);

    std::cout << "Enter the element for deletion:" << std::endl;
    std::cin >> element;
    myArr.deleteAt(arr, size, element);
    myArr.printArr(arr, size);

    int key;
    std::cout << "Enter the key you need the index for:" << std::endl;
    std::cin >> key;
    int low = 0;
    int high = size - 1;
    int searchedIndex = myArr.search(arr, low, high, key);
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
