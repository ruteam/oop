#include "SortArray.h"
#include "XorArray.h"
using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(0));

	Array* arr1 = new SortArray(6);
	Array* arr2 = new SortArray(8);

	arr1->forEach();
	cout << "Arr_1 Sort: ";
	arr1->print();

	arr2->forEach();
	cout << "Arr_2 Sort: ";
	arr2->print();

	arr1->add(*arr2);
	cout << "Arr_1 add:  ";
	arr1->print();

	Array* arr3 = new XorArray(7);
	Array* arr4 = new XorArray(10);

	cout << "\nArr_3:     ";
	arr3->print();
	
	cout << "Arr_4:     ";
	arr4->print();
	
	arr3->add(*arr4);
	cout << "Arr_3 add: ";
	arr3->print();

	cout << "Корни:      ";
	arr3->forEach();
	cout << '\n';

	delete arr1;
	delete arr2;
	delete arr3;
	delete arr4;

	char isContinue;
	cout << "\nПродолжить?";
	cout << "\n--> ";
	cin >> isContinue;
	
	if (isContinue == 'y')
		main();
	return 0;
}