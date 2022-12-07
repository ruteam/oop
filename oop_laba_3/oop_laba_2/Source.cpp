#include <iostream>
#include "Calculator.h"
using namespace std;

char chooseOperation(char z)
{
	while (z != '+' && z != '-' && z != '*' && z != '/')
	{
		cout << "\n��������:\n";
		cout << "+ - ��������\n";
		cout << "- - ��������\n";
		cout << "* - ������������\n";
		cout << "/ - �������\n";
		cout << "-->";
		cin >> z;
	}
	return z;
}
bool isContinue(char z)
{
	bool flag = false;
	while (z != 'y' && z != 'Y' && z != 'n' && z != 'N')
	{
		cout << "\n����������? (y/n)\n";
		cin >> z;
	}
	if (z == 'y' || z == 'Y') flag = true;

	return flag;
}

int main()
{
	setlocale(0, "");
	while (true)
	{
		Fraction A(2, 6), B(3, 18);
		cout << '\n';
		cout << "A = " << A;
		cout << "B = " << B;

		char z = '0';
		z = chooseOperation(z);
		
		Calculator D(A, B, z);
		cout << D;
		
		if (!isContinue(z))
			return 0;
	}
	//cin >> D;
	/*A = A + B;
	cout << "A = A + B = " << A;

	A = A - B;
	cout << "A = A - B = " << A;

	A = A * B;
	cout << "A = A * B = " << A.toString();

	A = A / B;
	cout << "A = A / B = " << A;

	if (C > B)
		cout << "C < B\n";
	else if (C == B)
		cout << "C == B\n";
	else
		cout << "C > B\n";

	if (A != B)
		cout << "A != B\n";

	if (A > B)
		cout << "A > B\n";
	else if (A < B)
		cout << "A < B\n";

	Fraction H;
	cin >> H;
	cout << "H = " << H;*/
	//return 0;
}