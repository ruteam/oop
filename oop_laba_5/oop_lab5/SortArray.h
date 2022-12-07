#include "Array.h"

class SortArray : public Array
{
public:
	SortArray(int s): Array(s) {}
	~SortArray();
	void add(Array& arr);
	void forEach();
};
