#include "Angle.h"
#include <cmath>
#include <string>
#include <iostream>

const double PI = 3.141592653589793;

void Angle::getDiapozon()
{
    if (min >= 60)
    {
        deg += min / 60;
        min %= 60;
    }
    deg %= 360;
}

double Angle::getRadians()
{
    return (deg * PI / 180.0);
}

double Angle::getSin()
{
    return sin(getRadians());
}

Angle Angle::add(Angle _angle)
{
    Angle temp;
    temp.deg = deg + _angle.deg;
    temp.min = min + _angle.min;
    temp.getDiapozon();
    return temp;
}

int Angle::sravnenie(Angle _angle)
{
    if ((deg*60 + min) > (_angle.deg*60 + _angle.min))
        return 1;
    else if ((deg*60 + min) < (_angle.deg*60 + _angle.min))
        return 2;
    else
        return 3;
}

Angle:: Angle(int _deg, int _min)
{
    deg = _deg;
    min = _min;
    getDiapozon();
}

Angle::Angle()
{
    deg = 0;
    min = 0;
}

std::string Angle::get()
{
    std::string a;
    a = std::to_string(deg) + '°' + std::to_string(min) + "'" + "\n";
    return a;
}



