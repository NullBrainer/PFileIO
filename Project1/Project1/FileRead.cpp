#include "FileRead.h"

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

void FileReader::ReadFile(std::string filename)
{

	std::ifstream File;
	try {
		File.open(filename);
		char c;
		File >> c;
		while (!File.eof()) {
			std::cout << c;//should not print out, must only return information
			File >> c;
		}		


		File.close();
	}
	catch (std::ifstream::failure e) {
		std::cerr << "File Error";
	}

}

