#ifndef FILE_READ_HEADER
#define FILE_READ_HEADER

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class FileReader
{
public:
	FileReader();
	~FileReader();

	/*Creates a file using filename.
	Reads the file one character at a time
	returns a vector of bytes representing the file content*/
	std::vector<char> ReadFile(std::string);

	/*Returns a vector of integers used to display the file as integers*/
	std::vector<int> ReadBinary(std::string);

private:
};

#endif // !FILE_READ_HEADER
