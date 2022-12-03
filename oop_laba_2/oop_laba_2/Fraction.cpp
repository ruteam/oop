#include <iostream>
#include <string>
#include "Fraction.h"

Fraction::Fraction() :num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den(d) {}

Fraction::~Fraction()
{
    num = 0;
    den = 0;
}

Fraction::Fraction(const Fraction& f)
{
    num = f.num;
    den = f.den;
}

void Fraction::setNum(int n)
{
    num = n;
}

void Fraction::setDen(int d)
{
    den = d;
}

int Fraction::getNum() const
{
    return num;
}

int Fraction::getDen() const
{
    return den;
}

//Сокращение дроби
void Fraction::reduce()
{
    //8/4 4/8
    int n = num;
    int d = den;

    int nabs = n > 0 ? n : -n;
    int min = nabs > d ? d : nabs;
    for (int divider = 2; divider <= min || divider == 2; ++divider)
    {
        while ((n % divider == 0) && (d % divider == 0))
        {
            n /= divider;
            d /= divider;
        }
    }
    num = n;
    den = d;
}

//Поиск общего знаменателя
int Fraction::getCommonDen(Fraction& f) {
    int d1 = den;
    int d2 = f.den;
    int tmp;

    while (d2)
    {
        tmp = d1 % d2;
        d1 = d2;
        d2 = tmp;
    }

    return (den * f.den) / d1;
}

Fraction Fraction::operator+(Fraction f)
{
    int d = getCommonDen(f);
    int n = f.num;
    int _d = d / f.den;
    Fraction tmp(num * d / den + n * _d, d);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator-(Fraction f)
{
    int d = getCommonDen(f);
    int n = f.num;
    int _d = d / f.den;
    Fraction tmp(num * d / den - n * _d, d);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator*(const Fraction& f)
{
    Fraction tmp(num * f.num, den * f.den);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator/(const Fraction& f)
{
    Fraction tmp;
    if ((den * f.num) > 0)
    {
        tmp.setNum(num * f.den);
        tmp.setDen(den * f.num);
    }
    else
    {
        tmp.setNum(-1 * num * f.den);
        tmp.setDen(-1 * den * f.num);
    }
    tmp.reduce();
    return tmp;
}

bool Fraction::operator == (Fraction f)
{
    getCommonDen(f);
    return num == f.num;
}

bool Fraction::operator != (Fraction f)
{
    getCommonDen(f);
    return num != f.num;
}

bool Fraction::operator > (Fraction f)
{
    getCommonDen(f);
    return num > f.num;
}

bool Fraction::operator < (Fraction f)
{
    getCommonDen(f);
    return num < f.num;
}

bool Fraction::operator >= (Fraction f)
{
    getCommonDen(f);
    return num >= f.num;
}

bool Fraction::operator <= (Fraction f)
{
    getCommonDen(f);
    return num <= f.num;
}

std::ostream& operator<<(std::ostream& out, const Fraction f)
{
    
    if (f.num % f.den != 0)
        out << f.num << '/' << f.den << '\n';
    else
        out << f.num / f.den << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    std::cout << "--> ";
    int n;
    int d;
    in >> n;

    bool flag = false;
    while (!flag)
    {
        std::cout << "--> ";
        in >> d;
        if (d > 0)
            flag = true;
        else
            std::cout << "\nЗнаменатель не > 0\n";
    }

    f = Fraction(n, d);
    return in;
}

std::string Fraction::toString()
{
    return (std::to_string(num) + '/' + std::to_string(den) + '\n');
}