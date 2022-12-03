#include <iostream>
#include "Calculator.h"

///Конструктор без параметров
Calculator::Calculator()
{
    number1.setNum(0);
    number1.setDen(1);
    number2.setNum(0);
    number2.setDen(1);
    op = '\n';
}

///Конструктор с параметрами
Calculator::Calculator(Fraction& n1, Fraction& n2)
{
    number1 = n1;
    number2 = n2;
    std::cout << "Введите операцию:";
    std::cout << "\n--> ";
    std::cin >> op;
}

///Конструктор с параметрами
Calculator::Calculator(Fraction& n1, Fraction& n2, char _op)
{
    number1 = n1;
    number2 = n2;
    op = _op;
}


///Деструктор
Calculator::~Calculator()
{
    number1.setNum(0);
    number1.setDen(0);
    number2.setNum(0);
    number2.setDen(0);
    op = '\n';
}

///Конструктор копирования
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
    out << "\nПервая дробь: ";
    out << c.number1;
    out << "Вторая дробь: ";
    out << c.number2;
    out << "Операция: ";
    out << c.op;
    out << "\nРезультат: ";
    out << c.result();
    return out;
}

std::istream& operator>>(std::istream& in, Calculator& c)
{
    std::cout << "\nВведите первую дробь:\n";
    in >> c.number1;
    std::cout << "Введите вторую дробь:\n";
    in >> c.number2;
    std::cout << "Введите операцию:";
    std::cout << "\n--> ";
    in >> c.op;
    //switch (z)
    //{
    //case('+'):
    //    //Вызвать ф-цию + с fraction
    ////    break;
    ////case('-'):
    ////    //Вызвать ф-цию - с fraction
    ////    break;
    ////case('*'):
    ////    //Вызвать ф-цию * с fraction
    ////    break;
    ////case('/'):
    ////    //Вызвать ф-цию / с fraction
    ////    break;
    ////default:
    ////    std::cout << "Error!";
    ////    break;
    ////}
    return in;
}