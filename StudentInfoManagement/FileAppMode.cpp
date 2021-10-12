#include "FileAppMode.h"
#include <iostream>
using namespace std;



bool FileAppMode::isWork()
{
	return !quit;
}

void FileAppMode::Quit()
{
	quit = true;
}
