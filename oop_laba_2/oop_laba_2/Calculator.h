#include "Fraction.h"
class Calculator
{
    Fraction number1, number2;
    char op;
public:

    ///����������� ��� ����������
    Calculator();

    ///����������� � �����������
    Calculator(Fraction& n1, Fraction& n2);

    ///����������� � �����������
    Calculator(Fraction& n1, Fraction& n2, char z);

    ///����������
    ~Calculator();

    ///����������� �����������
    Calculator(const Calculator& n);

    ///����
    Fraction getNumberOne();
    Fraction getNumberSecond();

    Fraction result();

    friend std::ostream& operator<<(std::ostream& out, Calculator c);
    friend std::istream& operator>>(std::istream& in, Calculator& c);
};
