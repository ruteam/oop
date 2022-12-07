#include "SortArray.h"
#include <functional>

SortArray::~SortArray()
{
    std::cout << "Virtual Destructor (sortarray)" << '\n';
}

void SortArray::add(Array& arr)
{
    auto isFind = [](int* arr, size_t size, int elem)
    {
        for (size_t i = 0; i < size; ++i)
            if (arr[i] == elem)
               return true;
        return false;
    };

    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < arr.get_size(); ++j)
        {
            if (!isFind(array, size, arr[j]))
            {
                resize();
                array[size - 1] = arr[j];
            }
        }
    }
}

void SortArray::forEach()
{
    for (size_t i = 0; i < size; i++)
    {
        bool flag = true;
        for (size_t j = 0; j < size-(i+1); j++)
        {
            if (array[j] > array[j + 1])
            {
                flag = false;
                std::swap(array[j], array[j + 1]);
            }
        }
        if (flag)
            break;
    }
}
