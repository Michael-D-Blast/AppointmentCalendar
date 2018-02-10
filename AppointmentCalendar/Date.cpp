#include "Date.h"

Date::Date()
{
	month = 1;
	day = 1;
	year = 1;
}

Date::Date(int initMonth, int initDay, int initYear)
{
	month = initMonth;
	day = initDay;
	year = initYear;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetDay() const
{
	return day;
}

int Date::GetYear() const
{
	return year;
}

RelationType Date::ComparedTo(Date otherDay) const
{
	if (year < otherDay.year)
		return BEFORE;
	else if (year > otherDay.year)
		return AFTER;
	else if (month < otherDay.month)
		return BEFORE;
	else if (month > otherDay.month)
		return AFTER;
	else if (day < otherDay.day)
		return BEFORE;
	else if (day > otherDay.day)
		return AFTER;
	else
		return SAME;
}

bool Date::operator <(const Date & otherDate) const
{
	if (year < otherDate.year)
		return true;
	else if (year > otherDate.year)
		return false;
	else if (month < otherDate.month)
		return true;
	else if (month > otherDate.month)
		return false;
	else if (day < otherDate.day)
		return true;
	else
		return false;

}

bool Date::operator >(const Date & otherDate) const
{
	if (year > otherDate.year)
		return true;
	else if (year < otherDate.year)
		return false;
	else if (month > otherDate.month)
		return true;
	else if (month < otherDate.month)
		return false;
	else if (day > otherDate.day)
		return true;
	else
		return false;
}

bool Date::operator ==(const Date & otherDate) const
{
	return (day == otherDate.day && month == otherDate.month && year == otherDate.year);
}
