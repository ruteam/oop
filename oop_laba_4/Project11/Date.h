#include "Triad.h"
#include <string>

class Date : public Triad
{
public:

    //����������� �� ���������
    //Date();
    Date() : Triad(){}

    //����������� � ����������
    //Date(int d, int m, int y);
    Date(int d, int m, int y) : Triad(d, m, y){}

    //����������
    ~Date();

    //��������� �� 1
    void dayP();
    void dayM();
    void monthP();
    void monthM();
    void yearP();
    void yearM();

    //��������� ��� �� n
    void dayChange(int n);

    //����������� ��� �y�����
    std::string nameDayWeek();

    //����������� �������� ������
    std::string nameMonth();

    //����������� ����
    void dateDisplay();

    //�������� �� ���������� ���
    bool isLeapYear();

    //������������ ����
    void normalizeDate();

    friend std::ostream& operator<<(std::ostream& out, Date f);
    friend std::istream& operator>>(std::istream& in, Date& f);
};