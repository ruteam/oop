#include "Triad.h"
#include <string>

class Date : public Triad
{
public:

    //Конструктор по умолчанию
    //Date();
    Date() : Triad(){}

    //Конструктор с параметром
    //Date(int d, int m, int y);
    Date(int d, int m, int y) : Triad(d, m, y){}

    //Деструктор
    ~Date();

    //Изменение на 1
    void dayP();
    void dayM();
    void monthP();
    void monthM();
    void yearP();
    void yearM();

    //Изменение дня на n
    void dayChange(int n);

    //Определение дня нyедели
    std::string nameDayWeek();

    //Определение названия месяца
    std::string nameMonth();

    //Отображение даты
    void dateDisplay();

    //Проверка на високосный год
    bool isLeapYear();

    //Нормализация даты
    void normalizeDate();

    friend std::ostream& operator<<(std::ostream& out, Date f);
    friend std::istream& operator>>(std::istream& in, Date& f);
};