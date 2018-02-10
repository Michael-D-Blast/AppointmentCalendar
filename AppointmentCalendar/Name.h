#pragma once

#include <iostream>
#include <string>
#include "RelationType.h"
using namespace std;

class Name
{
public:
	Name();
	Name(string firstName, string middleName, string lastName);

	string GetFirstName() const;
	string GetMiddleName() const;
	string GetLastName() const;
	char GetMiddleInitial() const;
	RelationType ComparedTo(Name otherName) const;

private:
	string first;
	string middle;
	string last;
};