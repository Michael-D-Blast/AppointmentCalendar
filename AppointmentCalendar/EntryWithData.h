#pragma once

#include "Date.h"
#include "TimeOfDay.h"
#include "Name.h"
#include "Entry.h"

class EntryWithDate : public Entry
{
public:
	EntryWithDate();
	EntryWithDate(Date initDate, TimeOfDay initTime, Name initName);
	Date GetDate() const;
	bool operator<(const EntryWithDate& otherEntry) const;
	bool operator>(const EntryWithDate& otherEntry) const;
	bool operator==(const EntryWithDate& otherEntry) const;
	bool operator<=(const EntryWithDate& otherEntry) const;
	bool operator>=(const EntryWithDate& otherEntry) const;
	bool operator!=(const EntryWithDate& otherEntry) const;
private:
	Date date;
};