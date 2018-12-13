#pragma once
#ifndef HEADER_KEY_READER
#define HEADER_KEY_READER
#include "FileRead.h"
#include "Key.h"

class KeyReader:FileReader
{
public:
	KeyReader();
	~KeyReader();
	Key ReadFromFile(std::string);

private:
	std::unique_ptr<FileReader>reader;
	std::vector<std::vector<double>> CreateVector(std::string);
	std::list<std::tuple<int, int, int>> Positions(std::string);
	std::string MakeString(std::vector<char>);
};

#endif // !HEADER_KEY_READER
