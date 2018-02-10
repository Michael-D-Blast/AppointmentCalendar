#pragma once

class TimeOfDay
{
public:
	TimeOfDay();
	TimeOfDay(int initHours, int initMinutes, int initSeconds);
	TimeOfDay Increment() const;
	void Write() const;
	bool Equal(TimeOfDay otherTime) const;
	bool LessThan(TimeOfDay otherTime) const;
	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;
private:
	int hours;
	int minutes;
	int seconds;
};