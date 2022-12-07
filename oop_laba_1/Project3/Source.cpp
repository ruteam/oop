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
    cout << "�������: " << a.getRadians() << endl;
    cout << "�����: " << a.getSin() << endl;

    cout << "\n== B ==" << endl;
    cout << b.get();
    cout << "�������: " << b.getRadians() << endl;
    cout << "�����: " << b.getSin() << endl;

    cout << "\n== C ==" << endl;
    c = a.add(b);
    cout << c.get();
    cout << "�������: " << c.getRadians() << endl;
    cout << "�����: " << c.getSin() << endl;

    //���������
    if (a.sravnenie(b) == 1)
        cout << "\nA ������ B";
    else if (a.sravnenie(b) == 2)
        cout << "\nB ������ A";
    else
        cout << "\nA == B";
}