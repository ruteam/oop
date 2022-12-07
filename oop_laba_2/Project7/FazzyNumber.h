#include <iostream>
using namespace std;
class FazzyNumber
{
	double* e1;
	double* x;
	double* e2;
public:
	//����������� ��� ����������
	FazzyNumber();
	//����������� � �����������
	FazzyNumber(const double& _e1, const double& _x, const double& _e2);
	//����������
	~FazzyNumber();
	//����������� �����������
	FazzyNumber(const FazzyNumber& number);
	//������������� �������������� �������� 
	FazzyNumber operator +(FazzyNumber& number);
	FazzyNumber operator -(FazzyNumber& number);
	FazzyNumber operator *(FazzyNumber& number);
	FazzyNumber& operator =(const FazzyNumber& number);
	//������������� << � >>
	friend ostream& operator<<(ostream& out, const FazzyNumber &number);
	friend istream& operator>> (istream& in, FazzyNumber& number);
};
