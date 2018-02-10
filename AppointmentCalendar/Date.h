#pragma once

#include "RelationType.h"

class Date
{
public:
	Date();
	Date(int initMonth, int initDay, int initYear);
	int GetMonth() const;
	int GetDay() const;
	int GetYear() const;
	RelationType ComparedTo(Date otherDay) const;
	bool operator <(const Date& otherDate) const;
	bool operator >(const Date& otherDate) const;
	bool operator ==(const Date& otherDate) const;

private:
	int month;
	int day;
	int year;
};