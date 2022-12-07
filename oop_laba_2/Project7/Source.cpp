#include <iostream>
#include "FazzyNumber.h"

using namespace std;

int main()
{
	setlocale(0, "");
	FazzyNumber A(0.1, 8, 0.2), D(0.1, 1, 0.2), C(D), E, F, G(A);

	cout << "========= A =========" << endl;
	cout << "A" << A << endl;
	cout << endl;
	
	cout << "========= D =========" << endl;
	cout << "D" << D << endl;
	cout << endl;

	C = A + D;

	cout << "========= C =========" << endl;
	cout << "C" << C << endl;
	cout << endl;

	E = A - D;

	cout << "========= A - D =========" << endl;
	cout << "E" << E << endl;
	cout << endl;

	F = A * D;

	cout << "========= A * D =========" << endl;
	cout << "F" << F << endl;
	cout << endl;

	G = A;
	cout << "========= G = A =========" << endl;
	cout << "G" << G << endl;
	return 0;
}