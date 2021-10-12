#pragma once
#include "FileAppMode.h"
#include "HomeMode.h"
class SearchMode :
    public FileAppMode
{
public:
    virtual FileAppMode* work(StudentFile* sf);
    virtual void showMenu();

private:
    void selectMode();
    void getKeyword();

private:
    int selectedMenu;
    std::string keyword;

    bool checkSelected();

    enum Menu
    {
        NAME=1,
        ID,
        ADMISSION,
        DEPARTMENT,
        ALL
    };
};

