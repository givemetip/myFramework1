#include "SortMode.h"
using namespace std;
FileAppMode* SortMode::work(StudentFile* sf)
{
	selectMenu();
	sf->setSortMode(selectedMenu);
	return new HomeMode();
}

void SortMode::showMenu()
{
	cout << "- Sorting Option -" << endl;
	cout << "1. Sort by Name" << endl;
	cout << "2. Sort by Student ID" << endl;
	cout << "3. Sort by Admission Year" << endl;
	cout << "4. Sort by Department name" << endl;
}

void SortMode::selectMenu()
{
	do
	{
		cout << "> ";
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

	} while (!checkSelected());
}

bool SortMode::checkSelected()
{
	if (selectedMenu <= 4 && selectedMenu >= 1)
	{
		cout << "Input 1 to 4" << endl;
		return true;
	}
	return false;
}
