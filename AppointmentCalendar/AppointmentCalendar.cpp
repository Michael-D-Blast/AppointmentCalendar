#include "AppointmentCalendar.h"

AppoinmentCalendar::AppoinmentCalendar(ifstream & inFile)
{
	int hours, minutes, seconds;
	int month, day, year;
	string first, middle, last;
	int numberEntries;
	/* 数据在文件中的组织格式如下：
	   总数目
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
	// 定义迭代器的同时就可以对其赋值
	list<EntryWithDate>::iterator location = find(entryList.begin(), entryList.end(), searchEntry);
	// 如果这里没有通过find找到，那么下面使用entry = *location的话，entry的值会是什么？函数执行会不会出错，还是返回一个非法值？包括下面调用erase函数也是一样
	// 要通过迭代器指向成员时，需要在迭代器前面加*号，此时迭代器有点像C语言里的指针
	EntryWithDate entry = *location;
	// erase算法的参数是迭代器，而不是容器的成员
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
	// 文件是在哪里打开的？
	// 在主程序里面打开的，所有还是要显示的打开
	outFile.close();
}
