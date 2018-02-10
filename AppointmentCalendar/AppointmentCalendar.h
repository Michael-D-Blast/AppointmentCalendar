#pragma once

#include <list>
#include <fstream>
#include "EntryWithData.h"

using namespace std;

class AppoinmentCalendar
{
public:
	AppoinmentCalendar(ifstream& inFile);
	bool IsThere(Name name, Date date);
	EntryWithDate GetEntry(Name name, Date date); /* Get之后，同时会把这个条目从容器里删除掉 */
	void InsertEntry(EntryWithDate entry);	/* 在插入一个条目的时候，只关注日期，不关注具体的时间点 */
	void WriteListToFile(ofstream& outFile);
	
private:
	list<EntryWithDate> entryList;
};