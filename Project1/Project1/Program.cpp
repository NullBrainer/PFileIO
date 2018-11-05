#include "Program.h"
#include <vector>
#include <stdio.h>
Program::Program()
{
}

Program::~Program()
{
}

void Program::Run()
{
	std::string filename;
	std::cout << "Enter name of new file to make\n";
	std::cin >> filename;

	std::unique_ptr<FileController>fc(new FileController(filename));
	std::cout << "Write stuff into the file: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string content;
	std::getline(std::cin, content);
	fc->Write(content);

	std::cout << "The File says: ";
	std::vector<char> fileinfo = fc->Read();
	std::vector<int> filenumbers = fc->GetBinary();

	for (int i = 0; i < fileinfo.size(); i++)
	{
		std::cout << fileinfo[i];
	}
	std::cout << "\nFile in numbers: ";
	for (int i = 0; i < filenumbers.size(); i++)
	{
		std::cout << filenumbers[i];
	}

	char c;
	std::cin >> c;

}