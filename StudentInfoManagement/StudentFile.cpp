#include "StudentFile.h"
#include "compare.h"
using namespace std;

StudentFile::StudentFile(std::string fileName)
{
	studentFile.open(fileName,ios::in|ios::out|ios::app);
	compareMode = 1;
}

StudentFile::~StudentFile()
{
	studentFile.close();
}


void StudentFile::insertStudent(Student_Info newInfo)
{
	if (isInserted(newInfo))
	{
		cout << "Error : Already Inserted" << endl;
		return;
	}

	studentFile << newInfo.toString() << endl;
}


bool StudentFile::isInserted(Student_Info s)
{
	string str;
	studentFile.seekg(ios::beg);
	while (getline(studentFile, str))
	{
		if (s.toString() == str) return true;
	}
	studentFile.clear();
	return false;
}

void StudentFile::search(int mode, const std::string& keyword)
{
	string str;
	vector<Student_Info> vStudent;
	studentFile.seekg(ios::beg);
	while (getline(studentFile, str))
	{
		Student_Info s(str);
		if (hasKeyword(mode, s, keyword))
		{
			vStudent.push_back(s);
		}
	}
	studentFile.clear();
	if (vStudent.empty())
	{
		cout << "There is no student" << endl;
	}
	else
	{
		sortStudent(vStudent);
		displayStudent(vStudent);
	}

}

void StudentFile::setSortMode(int mode)
{
	compareMode = mode;
}

void StudentFile::sortStudent(vector<Student_Info> &vs)
{
	switch (compareMode)
	{
	case StudentFormat::NAME:
		qsort(&vs[0], vs.size(), sizeof(vs[0]), compareName);
		break;
	case StudentFormat::ID:
		qsort(&vs[0], vs.size(), sizeof(vs[0]), compareID);
		break;
	case StudentFormat::ADMISSION:
		qsort(&vs[0], vs.size(), sizeof(vs[0]), compareAdmission);
		break;
	case StudentFormat::DEPARTMENT:
		qsort(&vs[0], vs.size(), sizeof(vs[0]), compareDepartment);
		break;
	default:
		cout << "Invalid Menu" << endl;
		break;
	}

}


bool StudentFile::hasKeyword(int mode, Student_Info& s,const string &keyword)
{
	switch (mode)
	{
	case StudentFormat::NAME:
		if (s.getName() == keyword) return true;
		break;
	case StudentFormat::ID:
		if (s.getStudentID() == keyword) return true;
		break;
	case StudentFormat::ADMISSION:
		if (s.getAdmission() == keyword) return true;
		break;
	case StudentFormat::DEPARTMENT:
		if (s.getDepartment() == keyword) return true;
		break;
	case 5:
		return true;
		break;
	default:
		cout << "Invalid Menu" << endl;
		break;
	}
	return false;
}

void StudentFile::displayStudent(vector<Student_Info> vs)
{
	for (Student_Info s : vs)
	{
		cout << s.toString() << endl;
	}
}
