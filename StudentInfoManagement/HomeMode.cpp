#include "HomeMode.h"
#include <iostream>
using namespace std;
FileAppMode* HomeMode::work(StudentFile* sf)
{
	return doAboutSelection();
}

void HomeMode::showMenu()
{
	std::cout << "Main Menu" << std::endl;
	std::cout << "1. Insertion" << std::endl;
	std::cout << "2. Search" << std::endl;
	std::cout << "3. Sorting Option" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

FileAppMode* HomeMode::doAboutSelection()
{
	int selectedMenu;
	do
	{
		std::cout << "select menu : ";
		cin >> selectedMenu;
		if (std::cin.fail())
		{
			std::cout << "invalid Input" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			continue;
		}
		else
		{
			std::cin.ignore(256, '\n');
		}
	} while (false);
	FileAppMode* selectedMode = nullptr;
	switch (selectedMenu)
	{
	case Menu::insert:
		selectedMode = new InsertMode();
		break;
	case Menu::search:
		selectedMode = new SearchMode();
		break;
	case Menu::Sort:
		selectedMode = new SortMode();
		break;
	case Menu::Quit:
		selectedMode = new HomeMode();
		selectedMode->Quit();
		break;
	default:
		std::cout << "Select Menu (1 ~4)"<< std::endl;
		break;
	}
	return selectedMode;
}
