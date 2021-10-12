#include "FileApp.h"
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	std::string fileName(argv[1]);
	FileApp app(fileName);
	app.run();
	return 0;
}


