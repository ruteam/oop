#include "Fraction.h"
class Calculator
{
    Fraction number1, number2;
    char op;
public:

    ///Конструктор без параметров
    Calculator();

    ///Конструктор с параметрами
    Calculator(Fraction& n1, Fraction& n2);

    ///Конструктор с параметрами
    Calculator(Fraction& n1, Fraction& n2, char z);

    ///Деструктор
    ~Calculator();

    ///Конструктор копирования
    Calculator(const Calculator& n);

    ///Геты
    Fraction getNumberOne();
    Fraction getNumberSecond();

    Fraction result();

    friend std::ostream& operator<<(std::ostream& out, Calculator c);
    friend std::istream& operator>>(std::istream& in, Calculator& c);
};
