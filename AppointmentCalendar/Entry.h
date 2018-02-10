#pragma once

#include "TimeOfDay.h"
#include "TimeOfDay.h"
#include "Name.h"
#include <string>
#include <sstream>

class Entry
{
public:
	Entry();
	Entry(string firstName, string middleName, string lastName, int initHours, int initMinutes, int initSeconds);

	string GetNameStr() const;
	string GetTimeStr() const;
	Name GetName() const;
	TimeOfDay GetTime() const;
	
private:
	Name name;
	TimeOfDay time;
};