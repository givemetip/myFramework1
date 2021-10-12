#pragma once
#include "FileAppMode.h"
#include "HomeMode.h"
#include <string>
#include "StudentFile.h"

class FileApp
{
public:
	FileApp(std::string fileName);
	void run();
private:
	FileAppMode *nowMode;
	FileAppMode *nextMode;
	StudentFile *sf;
	void setStartMode();
	void changeMode();
	static int a;
};

