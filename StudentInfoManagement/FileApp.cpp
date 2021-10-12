#include "FileApp.h"

FileApp::FileApp(std::string fileName)
{
	sf = new StudentFile(fileName);
	setStartMode();
}

void FileApp::run()
{

	nowMode->showMenu();
	while (nowMode->isWork())
	{
		nextMode = nowMode->work(sf);
		changeMode();
	}
}

void FileApp::setStartMode()
{
	nowMode = new HomeMode();
}

void FileApp::changeMode()
{
	if (nextMode != nullptr)
	{
		delete nowMode;
		nowMode = nextMode;
		cout << endl;
		nowMode->showMenu();
	}
}
