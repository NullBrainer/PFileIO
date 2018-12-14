
#ifndef HEADER_KEY_READER
#define HEADER_KEY_READER
#include "FileRead.h"
#include "Key.h"
#include <memory>
#include "Matrix.h"

class KeyReader:FileReader
{
public:
	KeyReader();
	~KeyReader();
	Key ReadFromFile(std::string);

private:
	std::unique_ptr<FileReader> reader;
	std::vector<std::vector<double>> CreateVector(std::string);
	std::string MakeString(std::vector<char>);
	std::vector<std::string> split(std::string, std::string);
};

#endif HEADER_KEY_READER
