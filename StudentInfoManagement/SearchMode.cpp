#include "SearchMode.h"
using namespace std;
FileAppMode* SearchMode::work(StudentFile* sf)
{
	selectMode();
	getKeyword();
	sf->search(selectedMenu, keyword);

	return new HomeMode();
}

void SearchMode::showMenu()
{
	cout << "- Search -"<<endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10number)" << endl;
	cout << "3. Search by admission year (4 numbers)" << endl;
	cout << "4. Search by department name" << endl;
	cout << "5. List All" << endl;
}

void SearchMode::selectMode()
{
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

	} while (!checkSelected());

}

void SearchMode::getKeyword()
{
	switch (selectedMenu)
	{
	case Menu::NAME:
		cout << "Name Keyword? ";
		break;
	case Menu::ID:
		cout << "ID Keyword? ";
		break;
	case Menu::ADMISSION:
		cout << "ADMISSION Keyword? ";
		break;
	case Menu::DEPARTMENT:
		cout << "DEPARTMENT Keyword? ";
		break;
	case Menu::ALL:
		return;
		break;
	}

	getline(cin, keyword);
}

bool SearchMode::checkSelected()
{
	if (selectedMenu <= 5 && selectedMenu >= 1) return true;
	else cout << "Input 1 to 5" << endl;
	return false;
}

