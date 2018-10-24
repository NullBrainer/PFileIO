#ifndef FILE_READ_HEADER
#define FILE_READ_HEADER

#include <string>
#include <fstream>
#include <iostream>

class FileReader
{
public:
	FileReader();
	~FileReader();

	/*Creates a file using filename.
	Reads the file one character at a time
	returns a vector of bytes representing the file content*/
	void ReadFile(std::string);

private:

};

#endif // !FILE_READ_HEADER
