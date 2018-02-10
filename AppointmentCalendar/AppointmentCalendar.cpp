#include "AppointmentCalendar.h"

AppoinmentCalendar::AppoinmentCalendar(ifstream & inFile)
{
	int hours, minutes, seconds;
	int month, day, year;
	string first, middle, last;
	int numberEntries;
	/* �������ļ��е���֯��ʽ���£�
	   ����Ŀ
	   hours, minutes, seconds
	   month, day, year
	   first, middle, last
	*/
	inFile >> numberEntries;
	for (int counter = 0; counter < numberEntries; counter++)
	{
		inFile >> hours >> minutes >> seconds;
		TimeOfDay time(hours, minutes, seconds);
		inFile >> month >> day >> year;
		Date date(month, day, year);
		inFile >> first >> middle >> last;
		Name name(first, middle, last);
		EntryWithDate entry(date, time, name);
		entryList.push_back(entry);
	}
}

bool AppoinmentCalendar::IsThere(Name name, Date date)
{
	TimeOfDay time;
	EntryWithDate entry(date, time, name);
	return find(entryList.begin(), entryList.end(), entry) != entryList.end();
}

EntryWithDate AppoinmentCalendar::GetEntry(Name name, Date date)
{
	TimeOfDay time;
	EntryWithDate searchEntry(date, time, name);
	// �����������ͬʱ�Ϳ��Զ��丳ֵ
	list<EntryWithDate>::iterator location = find(entryList.begin(), entryList.end(), searchEntry);
	// �������û��ͨ��find�ҵ�����ô����ʹ��entry = *location�Ļ���entry��ֵ����ʲô������ִ�л᲻��������Ƿ���һ���Ƿ�ֵ�������������erase����Ҳ��һ��
	// Ҫͨ��������ָ���Աʱ����Ҫ�ڵ�����ǰ���*�ţ���ʱ�������е���C�������ָ��
	EntryWithDate entry = *location;
	// erase�㷨�Ĳ����ǵ������������������ĳ�Ա
	entryList.erase(location);
	return entry;
}

void AppoinmentCalendar::InsertEntry(EntryWithDate entry)
{
	entryList.push_back(entry);
}

void AppoinmentCalendar::WriteListToFile(ofstream & outFile)
{
	EntryWithDate entry;
	TimeOfDay time;
	Date date;
	Name name;
	outFile << entryList.size() << endl;
	list<EntryWithDate>::iterator location;
	for (location = entryList.begin(); location != entryList.end(); location++)
	{
		entry = *location;
		time = entry.GetTime();
		outFile << time.GetHours() << time.GetMinutes() << time.GetSeconds();
		date = entry.GetDate();
		outFile << date.GetMonth() << date.GetDay() << date.GetYear();
		name = entry.GetName();
		outFile << name.GetFirstName() << name.GetMiddleName() << name.GetLastName();
	}
	// �ļ���������򿪵ģ�
	// ������������򿪵ģ����л���Ҫ��ʾ�Ĵ�
	outFile.close();
}
