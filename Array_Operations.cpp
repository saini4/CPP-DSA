
#include <iostream>

class MyArray
{
public:
    void deleteAt(int arr[], int &size, int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Index out of bounds!" << std::endl;
            return;
        }
        for (int i = index; i <= size; i++)
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
        for (int i = size; i >= index; i--)
        {
            arr[i + 1] = arr[i];
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

    return 0;
}