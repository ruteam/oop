#include "Triad.h"

Triad::Triad()
{
	day = 1;
	month = 1;
	year = 1970;
}

Triad::Triad(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Triad::setDay(int d)
{
	day = d;
}

void Triad::setMonth(int m)
{
	month = m;
}

void Triad::setYear(int y)
{
	year = y;
}

int Triad::getDay()
{
	return day;
}

int Triad::getMonth()
{
	return month;
}

int Triad::getYear()
{
	return year;
}


void Triad::dayP()
{
	++day;
}

void Triad::dayM()
{
	--day;
}

void Triad::monthP()
{
	++month;
}

void Triad::monthM()
{
	--month;
}

void Triad::yearP()
{
	++year;
}

void Triad::yearM()
{
	--year;
}