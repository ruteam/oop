#include "Date.h"
#include <iostream>


//Date::Date()
//{
//    day = 1;
//    month = 1;
//    year = 1970;
//}

//Date::Date(int d, int m, int y)
//{
//    day = d;
//    month = m;
//    year = y;
//}

Date::~Date()
{

}

void Date::dayP()
{
    Triad::dayP();
    normalizeDate();
}

void Date::dayM()
{
    Triad::dayM();
    normalizeDate();
}

void Date::monthP()
{
    Triad::monthP();
    normalizeDate();
}

void Date::monthM()
{
    Triad::monthM();
    normalizeDate();
}

void Date::yearP()
{
    Triad::yearP();
    normalizeDate();
}

void Date::yearM()
{
    Triad::yearM();
    normalizeDate();
}

void Date::dayChange(int n)
{
    if (n > 0)
        for (int i = 0; i < n; ++i)
            Triad::dayP();
    else
        for (int i = 0; i < -n; ++i)
            Triad::dayM();
    normalizeDate();
}

std::string Date::nameDayWeek()
{
    std::string days[] = { "Понедельник", "Вторник", "Среда", "Четверг",  "Пятница", "Суббота", "Воскресенье" };
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    if (R % 7 == 0)
        return days[6];
    return days[R % 7 - 1];
}

std::string Date::nameMonth()
{
    std::string months[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };

    return months[month - 1];
}

void Date::dateDisplay()
{
    std::cout << day << '.' << month << '.' << year;
}

bool Date::isLeapYear()
{
    return (year % 4 || (year % 100 == 0 && year % 400));
}

void Date::normalizeDate()
{
    int countDays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear())
        countDays[1] = 28;

    int countLeapYears = 0;

    while (day > countDays[month - 1] || day < 1)
    {
        if (day > countDays[month - 1])
        {
            day -= countDays[month - 1];
            if (month < 12)
                ++month;
            else
            {
                month = 1;
                ++year;
                //Если 
                if (isLeapYear())
                    countLeapYears = countLeapYears;
                else
                    countLeapYears += 1;
            }
        }
        if (day < 1)
        {
            if (month > 1)
                --month;
            else
            {
                month = 12;
                --year;
            }
            day += countDays[month - 1];
        }
    }

    while (countLeapYears > 0)
    {
        --day;
        if (day < 1)
        {
            if (month > 1)
                --month;
            else
            {
                month = 12;
                --year;
            }
            day += countDays[month - 1];
        }
        --countLeapYears;
    }
}

std::ostream& operator<<(std::ostream& out, Date date)
{
    out << "*******";
    if (date.day > 9 && date.month > 9)
        out << date.day << '.' << date.month;
    else if (date.day < 10 && date.month > 9)
        out << '0' << date.day << '.' << date.month;
    else if (date.day < 10 && date.month < 10)
        out << '0' << date.day << '.' << '0' << date.month;
    else if (date.day > 9 && date.month < 10)
        out << date.day << '.' << '0' << date.month;

    out << '.' << date.year << "*******\n";
    out << "День: " << date.day << '\n';
    out << "Месяц: " << date.nameMonth() << '\n';
    out << "Год: " << date.year << '\n';
    out << "День недели: " << date.nameDayWeek() << '\n';
    out << "**********************";
    return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
    std::cout << "\nУкажите дату в формате d.m.y\n";

    int d, y, m;
    std::cout << "-->";
    std::cin >> d;
    while (d < 1 || d > 31)
    {
        std::cout << "Неправильно указан день\n";
        std::cout << "--> ";
        std::cin >> d;
    }

    std::cin >> m;
    while (m < 1 || m > 12)
    {
        std::cout << "Неправильно указан месяц\n";
        std::cout << "--> ";
        std::cin >> m;
    }
    std::cin >> y;
    while (y < 0)
    {
        std::cout << "Неправильно указан год\n";
        std::cout << "--> ";
        std::cin >> y;
    }
    date.day = d;
    date.month = m;
    date.year = y;
    return in;
}
