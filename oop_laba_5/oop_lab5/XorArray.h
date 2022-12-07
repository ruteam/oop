#include "Array.h"

class XorArray : public Array
{
public:
	XorArray(int s) : Array(s) {}
	~XorArray();
	void add(Array& arr);
	void forEach();
};