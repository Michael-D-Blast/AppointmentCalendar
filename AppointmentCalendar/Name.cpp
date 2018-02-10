#include "Name.h"

Name::Name()
{
	first = " ";
	middle = " ";
	last = " ";
}

Name::Name(string firstName, string middleName, string lastName)
{
	first = firstName;
	middle = middleName;
	last = lastName;
}

string Name::GetFirstName() const
{
	return first;
}

string Name::GetMiddleName() const
{
	return middle;
}

string Name::GetLastName() const
{
	return last;
}

char Name::GetMiddleInitial() const
{
	return middle[0];
}

RelationType Name::ComparedTo(Name otherName) const
{
	if (last < otherName.last)
		return BEFORE;
	else if (last > otherName.last)
		return AFTER;
	else if (first < otherName.first)
		return BEFORE;
	else if (first > otherName.first)
		return AFTER;
	else if (middle < otherName.middle)
		return BEFORE;
	else if (middle > otherName.middle)
		return AFTER;
	else
		return SAME;
}
