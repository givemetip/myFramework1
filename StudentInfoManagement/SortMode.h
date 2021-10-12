#pragma once
#include "FileAppMode.h"
#include "HomeMode.h"
class SortMode :
    public FileAppMode
{
public:
    virtual FileAppMode* work(StudentFile* sf);
    virtual void showMenu();
private:
    void selectMenu();
private:
    int selectedMenu;
    bool checkSelected();
};

