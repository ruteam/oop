#include <iostream>
using namespace std;
class FazzyNumber
{
	double* e1;
	double* x;
	double* e2;
public:
	//Конструктор без параметров
	FazzyNumber();
	//Конструктор с параметрами
	FazzyNumber(const double& _e1, const double& _x, const double& _e2);
	//Деструктор
	~FazzyNumber();
	//Конструктор копирования
	FazzyNumber(const FazzyNumber& number);
	//Перегруженные арифметические операции 
	FazzyNumber operator +(FazzyNumber& number);
	FazzyNumber operator -(FazzyNumber& number);
	FazzyNumber operator *(FazzyNumber& number);
	FazzyNumber& operator =(const FazzyNumber& number);
	//Перегруженные << и >>
	friend ostream& operator<<(ostream& out, const FazzyNumber &number);
	friend istream& operator>> (istream& in, FazzyNumber& number);
};
