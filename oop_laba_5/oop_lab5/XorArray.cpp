#include "XorArray.h"

XorArray::~XorArray()
{
    std::cout << "Virtual Destructor (xorarray)" << '\n';
}

void XorArray::add(Array& arr)
{
    size_t tmpSize = size;
    for (int j = 0; j < arr.get_size(); ++j)
    {
        bool isDelete = false;
        for (int i = 0; i < tmpSize; ++i)
        {
            if (array[i] == arr[j])
            {
                del_element(i);
                isDelete = true;
            }
        }
        if (!isDelete)
        {
            resize();
            array[size - 1] = arr[j];
        }
    }
}

void XorArray::forEach()
{
    for (int i = 0; i < size; ++i)
        if (array[i] > -1)
            std::cout << sqrt(array[i]) << "   ";
}
//ф-ция, которая будучи описанной в потомках замещает собой соответствующую функцию везде (даже в предках), если она вызывается для потомков