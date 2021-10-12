#pragma once
#include "FileAppMode.h"
#include "InsertMode.h"
#include "SearchMode.h"
#include "SortMode.h"
#include "StudentFile.h"
class HomeMode :
    public FileAppMode
{
public:
    virtual FileAppMode* work(StudentFile* sf);
    virtual void showMenu();
private:
    FileAppMode* doAboutSelection();
    
    enum Menu {
        insert=1,
        search,
        Sort,
        Quit
    };
};

