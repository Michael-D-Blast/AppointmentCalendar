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
	EntryWithDate GetEntry(Name name, Date date); /* Get֮��ͬʱ��������Ŀ��������ɾ���� */
	void InsertEntry(EntryWithDate entry);	/* �ڲ���һ����Ŀ��ʱ��ֻ��ע���ڣ�����ע�����ʱ��� */
	void WriteListToFile(ofstream& outFile);
	
private:
	list<EntryWithDate> entryList;
};