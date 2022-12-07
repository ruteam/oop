#include "FazzyNumber.h"
#include <iostream>
using namespace std;

//Конструктор без параметров
FazzyNumber::FazzyNumber()
{
	e1 = new double();
	x = new double();
	e2 = new double();
}

//Конструктор с параметрами
FazzyNumber::FazzyNumber(const double& _e1, const double& _x, const double& _e2)
{
	e1 = new double(_e1);
	x = new double(_x);
	e2 = new double(_e2);
}

//Деструктор
FazzyNumber::~FazzyNumber()
{
	delete e1;
	delete x;
	delete e2;
}

//Конструктор копирования
FazzyNumber::FazzyNumber(const FazzyNumber& number)
{
	e1 = new double(*number.e1);
	x = new double(*number.x);
	e2 = new double(*number.e2);
}

FazzyNumber FazzyNumber::operator+(FazzyNumber& number)
{
	FazzyNumber _number;
	*_number.x = *x + *number.x;
	*_number.e1 = *e1 + *number.e1;
	*_number.e2 = *e2 + *number.e2;
	return _number;
}

FazzyNumber FazzyNumber::operator-(FazzyNumber& number)
{
	FazzyNumber _number;
	*_number.x = *x - *number.x;
	*_number.e1 = *e1 + *number.e1;
	*_number.e2 = *e2 + *number.e2;
	return _number;
}

FazzyNumber FazzyNumber::operator*(FazzyNumber& number)
{
	FazzyNumber _number;
	*_number.x = *x * *number.x;
	*_number.e1 = (-1 * *number.x * *e1) - *x * *number.e1 + *e1 * *number.e1;
	*_number.e2 = *number.x * *e2 + *x * *number.e2 + *e2 * *number.e2;
	return _number;
}

FazzyNumber& FazzyNumber::operator=(const FazzyNumber& number)
{
	*x = *number.x;
	*e1 = *number.e1;
	*e2 = *number.e2;
	return *this;
}

ostream& operator<<(ostream& out, const FazzyNumber& number)
{
	if (*number.e1 > 0)
		out << "(" << *number.x << "-" << * number.e1 << ", " << *number.x << ", " << *number.x << "+" << *number.e2 << ")";
	else
		out << "(" << *number.x << * number.e1 << ", " << *number.x << ", " << *number.x << "+" << *number.e2 << ")";
	return out;
}

istream& operator>>(istream& in, FazzyNumber& number)
{
	cout << "Введите e1, x, e2: ";
	in >> *number.e1;
	in >> *number.x;
	in >> *number.e2;
	return in;
}


































//FazzyNumber FazzyNumber::operator/(FazzyNumber& number)
//{
//	FazzyNumber _number;
//	if (*number.x <= 0)
//		cout << "ДЕЛЕНИЕ НА 0" << endl;
//	if ((*number.x + *number.e2 < 0.0001) && (*number.x+*number.e2 > -0.0001))
//		cout << "ДЕЛЕНИЕ НА 0" << endl;
//	*_number.x = *x / *number.x;
//	if ((*number.x - *number.e1 < 0.0001) && (*number.x - *number.e1) > -0.0001)
//		cout << "ДЕЛЕНИЕ НА 0" << endl;
//	*_number.e1 = *_number.x - (*x - *e1) / (*number.x + *number.e2);
//	*_number.e2 = (*x + *e2) / (*number.x - *number.e1) - *_number.x;
//	return _number;
//} 
