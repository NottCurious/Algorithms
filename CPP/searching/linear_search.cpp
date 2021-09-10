#include <iostream>

namespace searching
{
namespace linear_search
{
int linearSearch(int *array, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}
} // namespace linear_search
} // namespace searching

int main()
{
    int size;
    std::cout << "\nEnter the size of the Array : ";
    std::cin >> size;

    int *array = new int[size];
    int key;

    // Input array
    std::cout << "\nEnter the Array of " << size << " numbers : ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    std::cout << "\nEnter the number to be searched : ";
    std::cin >> key;

    int index = searching::linear_search::linearSearch(array, size, key);
    if (index != -1)
    {
        std::cout << "\nNumber found at index : " << index;
    }
    else
    {
        std::cout << "\nNot found";
    }

    delete[] array;
    return 0;
}