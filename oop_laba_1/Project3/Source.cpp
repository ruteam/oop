#include "Angle.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
    setlocale(0, "");
    Angle a(380, 150), b(21, 91), c;

    cout << "== A ==" << endl;
    cout << a.get();
    cout << "Радианы: " << a.getRadians() << endl;
    cout << "Синус: " << a.getSin() << endl;

    cout << "\n== B ==" << endl;
    cout << b.get();
    cout << "Радианы: " << b.getRadians() << endl;
    cout << "Синус: " << b.getSin() << endl;

    cout << "\n== C ==" << endl;
    c = a.add(b);
    cout << c.get();
    cout << "Радианы: " << c.getRadians() << endl;
    cout << "Синус: " << c.getSin() << endl;

    //Сравнение
    if (a.sravnenie(b) == 1)
        cout << "\nA больше B";
    else if (a.sravnenie(b) == 2)
        cout << "\nB больше A";
    else
        cout << "\nA == B";
}