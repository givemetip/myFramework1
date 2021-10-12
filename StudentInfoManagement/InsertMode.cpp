#include "InsertMode.h"
#include <iostream>
using namespace std;
FileAppMode* InsertMode::work(StudentFile* sf)
{
	getStudentInfo();
	insertToFile(sf);
	return new HomeMode();
}

void InsertMode::showMenu()
{
	std::cout << "Input Information of Student" << std::endl;
}

void InsertMode::getStudentInfo()
{
	string name;
	do {
		std::cout << "Name ? ";
		getline(cin, name);
		if (std::cin.fail())
		{
			std::cout << "unvalid input" << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
	} while (!student.setName(name));

	string id; 
	do {
		std::cout << "Student ID (10 digits)? ";
		getline(cin, id);
		if (!isNumber(id))
		{
			std::cout << "input number" << std::endl;
			continue;
		}
	} while (!student.setStudent_ID(id));

	string birth;
	do {
		std::cout << "Birth Year (4 digits)? ";
		getline(cin, birth);
		if (!isNumber(birth))
		{
			std::cout << "input number" << std::endl;
			continue;
		}
	} while (!student.setBirthYear(birth));
	
	std::string depart;
	do {
		std::cout << "Department ? ";
		getline(cin, depart);
	} while (!student.setDepartment(depart));

	string tel;
	do {
		std::cout << "Tel ? ";
		getline(cin, tel);
		if (!isNumber(tel))
		{
			std::cout << "input number" << std::endl;
			continue;
		}
	} while (!student.setTelephone(tel));

	cout << student.toString()<<endl;

}

void InsertMode::insertToFile(StudentFile* sf)
{
	sf->insertStudent(student);
}

bool InsertMode::isNumber(const std::string& input)
{
	for (char const &c :input)
	{
		if (isdigit(c) == 0)return false;
	}
	return true;
}
