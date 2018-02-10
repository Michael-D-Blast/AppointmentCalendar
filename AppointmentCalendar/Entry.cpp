#include "Entry.h"

Entry::Entry()
{
}

Entry::Entry(string firstName, string middleName, string lastName, int initHours, int initMinutes, int initSeconds) :name(firstName, middleName, lastName), time(initHours, initMinutes, initSeconds)
{

}

string Entry::GetNameStr() const
{
	return (name.GetFirstName() + ' ' + name.GetLastName());
}

string Entry::GetTimeStr() const
{
	string outStr;
	ostringstream tempOut;
	if (time.GetHours() < 10)
		tempOut << '0';
	tempOut << time.GetHours() << ':';
	if (time.GetMinutes() < 10)
		tempOut << '0';
	tempOut << time.GetMinutes() << ':';
	if (time.GetSeconds() < 10)
		tempOut << '0';
	tempOut << time.GetSeconds();
	outStr = tempOut.str();

	return outStr;
}

Name Entry::GetName() const
{
	return name;
}

TimeOfDay Entry::GetTime() const
{
	return time;
}
