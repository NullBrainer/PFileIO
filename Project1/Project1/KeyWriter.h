#pragma once
#ifndef HEADER_KEY_WRITER
#define HEADER_KEY_WRITER


#include "FileWrite.h"
#include "Key.h"

class KeyWriter : FileWriter
{
public:
	KeyWriter();
	~KeyWriter();
	void WriteKeyToFile(std::string, Key);
private:
	std::unique_ptr<FileWriter> writer;
	std::string ParseKey(Key);
	std::string ParseMatrix(Key);
	std::string ParsePositions(Key);

};
#endif // !HEADER_KEY_WRITER