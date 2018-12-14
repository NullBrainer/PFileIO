#ifndef HEADER_KEY_WRITER
#define HEADER_KEY_WRITER


#include "FileWrite.h"
#include "Key.h"
#include <memory>

class KeyWriter : FileWriter
{
public:
	KeyWriter();
	~KeyWriter();
	void WriteKeyToFile(std::string, Key);
private:
	std::string ParseKey(Key);
	std::string ParseMatrix(Key);
	std::string ParsePositions(Key);

};
#endif HEADER_KEY_WRITER