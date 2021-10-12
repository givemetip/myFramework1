#pragma once
#include <string>
#define delimeter '/'
using namespace std;
class Student_Info
{
public:
	Student_Info();
	Student_Info(string info);

	bool setName(const string &name);
	bool setStudent_ID(const string &student_ID);
	bool setBirthYear(const string& birth_year);
	bool setDepartment(const std::string &department);
	bool setTelephone(const string& tel);

	string getName();
	string getStudentID();
	string getAdmission();
	string getDepartment();

	std::string toString();
private:
	string name;
	string student_ID;
	string birth_year;
	string department;
	string tel;

	const int max_namelen = 15;
	bool isTooLong(const std::string &name);
	bool hasBlank(const std::string& name);

	const int validDigit = 10;
	bool isValidID(const string& student_ID);

	bool isValidBirth(const string& birth);
	bool isValidTel(const string& tel);

private:
	enum Format
	{
		NAME,
		STUDENT_ID,
		BIRTH_YEAR,
		DEPARTMENT,
		TEL
	};
};