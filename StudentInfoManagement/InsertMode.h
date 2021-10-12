#pragma once
#include "FileAppMode.h"
#include "StudentInfo.h"
#include "HomeMode.h"
class InsertMode :
    public FileAppMode
{
public:
    virtual FileAppMode* work(StudentFile* sf);
    virtual void showMenu();
private:
    void getStudentInfo();
    void insertToFile(StudentFile* sf);

    bool isNumber(const std::string& input);
    Student_Info student;

};

