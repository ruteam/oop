#include <iostream>
#include "Calculator.h"

///����������� ��� ����������
Calculator::Calculator()
{
    number1.setNum(0);
    number1.setDen(1);
    number2.setNum(0);
    number2.setDen(1);
    op = '\n';
}

///����������� � �����������
Calculator::Calculator(Fraction& n1, Fraction& n2)
{
    number1 = n1;
    number2 = n2;
    std::cout << "������� ��������:";
    std::cout << "\n--> ";
    std::cin >> op;
}

///����������� � �����������
Calculator::Calculator(Fraction& n1, Fraction& n2, char _op)
{
    number1 = n1;
    number2 = n2;
    op = _op;
}


///����������
Calculator::~Calculator()
{
    number1.setNum(0);
    number1.setDen(0);
    number2.setNum(0);
    number2.setDen(0);
    op = '\n';
}

///����������� �����������
Calculator::Calculator(const Calculator& c)
{
    number1 = c.number1;
    number2 = c.number2;
    op = c.op;
}

Fraction Calculator::getNumberOne()
{
    return number1;
}

Fraction Calculator::getNumberSecond()
{
    return number2;
}

Fraction Calculator::result()
{
   switch (op)
   {
       case('+'):
           return (number1 + number2);
           break;
       case('-'):
           return (number1 - number2);
           break;
       case('*'):
           return (number1 * number2);
           break;
       case('/'):
           return (number1 / number2);
           break;
       default:
           break;
   }
}

std::ostream& operator<<(std::ostream& out, Calculator c)
{
    out << "\n������ �����: ";
    out << c.number1;
    out << "������ �����: ";
    out << c.number2;
    out << "��������: ";
    out << c.op;
    out << "\n���������: ";
    out << c.result();
    return out;
}

std::istream& operator>>(std::istream& in, Calculator& c)
{
    std::cout << "\n������� ������ �����:\n";
    in >> c.number1;
    std::cout << "������� ������ �����:\n";
    in >> c.number2;
    std::cout << "������� ��������:";
    std::cout << "\n--> ";
    in >> c.op;
    //switch (z)
    //{
    //case('+'):
    //    //������� �-��� + � fraction
    ////    break;
    ////case('-'):
    ////    //������� �-��� - � fraction
    ////    break;
    ////case('*'):
    ////    //������� �-��� * � fraction
    ////    break;
    ////case('/'):
    ////    //������� �-��� / � fraction
    ////    break;
    ////default:
    ////    std::cout << "Error!";
    ////    break;
    ////}
    return in;
}