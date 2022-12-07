#ifndef _ARRAY_
#define _ARRAY_

#include <iostream>

class Array
{
protected:
	int* array;
	size_t size;
public:
	Array(size_t s = 1);
	virtual ~Array();
	virtual void add(Array& arr) = 0;
	virtual void forEach() = 0;
	void print();
	void resize(int s = 1);
	int operator[](int i);
	void del_element(int i);
	size_t get_size();
};

#endif