#pragma once
#include "StudentInfo.h"
int compareName(const void* a, const void* b)
{
	Student_Info* s1 = (Student_Info*)a;
	Student_Info* s2 = (Student_Info*)b;
	string name1 = s1->getName();
	string name2 = s2->getName();
	return name1.compare(name2);
}

int compareID(const void* a, const void* b)
{
	Student_Info* s1 = (Student_Info*)a;
	Student_Info* s2 = (Student_Info*)b;
	string id1 = s1->getStudentID();
	string id2 = s2->getStudentID();
	return id1.compare(id2);
}

int compareAdmission(const void* a, const void* b)
{
	Student_Info* s1 = (Student_Info*)a;
	Student_Info* s2 = (Student_Info*)b;
	string ad1 = s1->getAdmission();
	string ad2 = s2->getAdmission();
	return ad1.compare(ad2);
}

int compareDepartment(const void* a, const void* b)
{
	Student_Info* s1 = (Student_Info*)a;
	Student_Info* s2 = (Student_Info*)b;
	string dep1 = s1->getDepartment();
	string dep2 = s2->getDepartment();
	return dep1.compare(dep2);
}