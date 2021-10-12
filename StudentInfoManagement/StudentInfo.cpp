#include "StudentInfo.h"
#include <iostream>
#include <vector>
#include <sstream>
Student_Info::Student_Info()
{
}

Student_Info::Student_Info(string info)
{

	istringstream infostream(info);
	string str;
	vector<string> infovector;

	while (getline(infostream, str, delimeter))
	{
		infovector.push_back(str);
	}
	setName(infovector[Format::NAME]);
	setStudent_ID(infovector[Format::STUDENT_ID]);
	setBirthYear(infovector[Format::BIRTH_YEAR]);
	setDepartment(infovector[Format::DEPARTMENT]);
	setTelephone(infovector[Format::TEL]);
}

bool Student_Info::setName(const std::string& name)
{
	bool valid = false;
	if (isTooLong(name))
	{
		cout << "name has up to 15 characters" << endl;
		return valid;
	}
	if (hasBlank(name))
	{
		cout << "name should not be blank" << endl;
		return valid;

	}
	else 
	{
		this->name = name;
		valid = true;
	}
	return valid;
}

bool Student_Info::setStudent_ID(const string& student_ID)
{
	if (isValidID(student_ID))
	{
		this->student_ID = student_ID;
		return true;
	}
	else
		cout << "Student_ID must have 10 digits" << endl;
	return false;
}

bool Student_Info::setBirthYear(const string& birth_year)
{
	if (isValidBirth(birth_year))
	{
		this->birth_year = birth_year;
		return true;
	}
	else
		cout << "Birth_Year must have 4 digits" << endl;
	return false;
}

bool Student_Info::setDepartment(const std::string& department)
{
	this->department = department;
	return true;
}

bool Student_Info::setTelephone(const string& tel)
{
	if (isValidTel(tel))
	{
		this->tel = tel;
		return true;
	}
	else cout << "Tel has up to 12" << endl;
	return false;
}

string Student_Info::getName()
{
	return name;
}

string Student_Info::getStudentID()
{
	return student_ID;
}

string Student_Info::getAdmission()
{
	return student_ID.substr(0,4);
}

string Student_Info::getDepartment()
{
	return department;
}

std::string Student_Info::toString()
{
	string str;
	str = name + delimeter +
		student_ID+ delimeter +
		birth_year+ delimeter +
		department+ delimeter +
		tel;
	return str;
}

bool Student_Info::isTooLong(const std::string& name)
{
	bool namelong;
	name.length() > max_namelen ? namelong = true : namelong = false;
	return namelong;
}

bool Student_Info::hasBlank(const std::string& name)
{
	string::const_iterator iter = name.begin();
	for (iter; iter != name.end(); ++iter)
	{
		if (*iter == ' ')
		{
			return true;
		}

	}
	return false;
}

bool Student_Info::isValidID(const string& student_ID)
{
	if (student_ID.length() != validDigit) return false;
	return true;
}



bool Student_Info::isValidBirth(const string& birth)
{
	if (birth.length() == 4) return true;
	return false;
}

bool Student_Info::isValidTel(const string& tel)
{
	if (tel.length() <= 12) return true;
	return false;
}
