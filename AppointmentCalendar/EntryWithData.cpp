#include "Date.h"
#include "EntryWithData.h"

EntryWithDate::EntryWithDate()
{
}

EntryWithDate::EntryWithDate(Date initDate, TimeOfDay initTime, Name initName) :Entry(initName.GetFirstName(), initName.GetMiddleName(), initName.GetLastName(), initTime.GetHours(), initTime.GetMinutes(), initTime.GetSeconds())
{
	date = initDate;
}

Date EntryWithDate::GetDate() const
{
	return date;
}

bool EntryWithDate::operator<(const EntryWithDate & otherEntry) const
{
	return date < otherEntry.GetDate();
}

bool EntryWithDate::operator>(const EntryWithDate & otherEntry) const
{
	return date > otherEntry.GetDate();
}

bool EntryWithDate::operator==(const EntryWithDate & otherEntry) const
{
	return (date == otherEntry.GetDate() && GetName().ComparedTo(otherEntry.GetName()) == SAME);
}

bool EntryWithDate::operator<=(const EntryWithDate & otherEntry) const
{
	return (date < otherEntry.date || date == otherEntry.date);
}

bool EntryWithDate::operator>=(const EntryWithDate & otherEntry) const
{
	return (date > otherEntry.GetDate() || date == otherEntry.GetDate());
}

bool EntryWithDate::operator!=(const EntryWithDate & otherEntry) const
{
	return !(otherEntry == *this);
}


