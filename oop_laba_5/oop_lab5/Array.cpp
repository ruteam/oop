#include "Array.h"
using namespace std;

Array::Array(size_t s)
{
	auto isRemoveEqual = [](int* arr, size_t size)
	{
		bool flag = false;
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i+1; j < size; ++j)
			{
				if (arr[i] == arr[j])
				{
					flag = true;
					arr[j] += 1;
				}
			}
		}
		return flag;
	};

	size = s;
	array = new int[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = rand() % 10;
	
	while (isRemoveEqual(array, size)){}
}

Array::~Array()
{
	cout << "Virtual Destructor (array)\n";
	delete[]  array;
}

void Array::print()
{
	for (size_t i = 0; i < size; ++i)
		cout << array[i] << ' ';
	cout << '\n';
}

void Array::resize(int s)
{
	int* temp = new int[size];
	for (size_t i = 0; i < size; i++)
		temp[i] = array[i];

	size += s;

	delete[] array;

	array = new int[size];

	for (size_t i = 0; i < size; i++)
		array[i] = temp[i];
}

int Array::operator[](int i)
{
	return array[i];
}

void Array::del_element(int i)
{
	for (size_t j = i; j < size; ++j)
			array[j] = array[j + 1];
	resize(-1);
}

size_t Array::get_size()
{
	return size;
}