#include "FileRead.h"

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

std::vector<char> FileReader::ReadFile(std::string filename)
{
	std::vector<char>characters;

	try {
		std::ifstream File;
		File.open(filename, std::ios::binary | std::ios::in);
		char c;
		File >> c;
		while (!File.eof()) {
			characters.push_back(c);
			File >> c;
		}		


		File.close();
	}
	catch (std::ifstream::failure e) {
		std::cerr << "File Error";
	}
	return characters;
}


std::vector<int> FileReader::ReadBinary(std::string filename)
{
	std::vector<int>data;
	try {
		std::ifstream File;

		File.open(filename, std::ios::binary | std::ios::in);
		char c;
		File >> c;
		while (!File.eof()) {
			data.push_back(c);
			File >> c;
		}

	}
	catch (std::ifstream::failure e) {
		std::cerr << "File Error";
	}

	return data;
}

