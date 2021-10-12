#pragma once
#include <iostream>
#include "StudentFile.h"
class FileAppMode
{
public:
	virtual FileAppMode* work(StudentFile *sf)=0;
	virtual void showMenu() = 0;
	bool isWork();
	void Quit();
private:
	bool quit=false;
};

