#include "Program.h"

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
	fc->Read();
	char c;
	std::cin >> c;

}