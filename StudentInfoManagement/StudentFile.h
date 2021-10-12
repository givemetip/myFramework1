#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "StudentInfo.h"

enum StudentFormat{
	NAME=1,
	ID,
	ADMISSION,
	DEPARTMENT
};

class StudentFile
{
public:
	StudentFile(std::string fileName);
	~StudentFile();
	void insertStudent(Student_Info newInfo);
	void search(int mode, const std::string &keyword);
	void setSortMode(int mode);

private:
	std::fstream studentFile;

	bool isInserted(Student_Info s);
private:
	int compareMode;
	bool hasKeyword(int mode, Student_Info& s,const string& keyword);
	void sortStudent(vector<Student_Info> &vs);
	void displayStudent(vector<Student_Info> vs);
};

