#include <iostream>
#include "TimeOfDay.h"

using namespace std;

TimeOfDay::TimeOfDay()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

TimeOfDay::TimeOfDay(int initHours, int initMinutes, int initSeconds)
{
	hours = initHours;
	minutes = initMinutes;
	seconds = initSeconds;
}

TimeOfDay TimeOfDay::Increment() const
{
	TimeOfDay result(hours, minutes, seconds);
	result.seconds++;
	if (result.seconds > 59)
	{
		result.seconds = 0;
		result.minutes++;
		if (result.minutes > 59)
		{
			result.minutes = 0;
			result.hours++;
			if (result.hours > 23)
			{
				result.hours = 0;
			}
		}
	}
	return result;
}

void TimeOfDay::Write() const
{
	if (hours < 10)
		cout << '0';
	cout << hours << ':';
	if (minutes < 10)
		cout << '0';
	cout << minutes << ':';
	if (seconds < 10)
		cout << '0';
	cout << seconds;
}

bool TimeOfDay::Equal(TimeOfDay otherTime) const
{
	return (hours == otherTime.hours && minutes == otherTime.minutes && seconds == otherTime.seconds);
}

bool TimeOfDay::LessThan(TimeOfDay otherTime) const
{
	if (hours < otherTime.hours)
		return true;
	else if (hours > otherTime.hours)
		return false;
	else if (minutes < otherTime.minutes)
		return true;
	else if (minutes < otherTime.minutes)
		return false;
	else if (seconds < otherTime.seconds)
		return true;
	else if (seconds > otherTime.seconds)
		return false;
	else
		return true;
}

int TimeOfDay::GetHours() const
{
	return hours;
}

int TimeOfDay::GetMinutes() const
{
	return minutes;
}

int TimeOfDay::GetSeconds() const
{
	return seconds;
}
