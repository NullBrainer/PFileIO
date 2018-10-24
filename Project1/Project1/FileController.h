#ifndef FCONTROLLER_HEADER
#define FCONTROLLER_HEADER

#include<stdio.h>
#include "FileRead.h"
#include "FileWrite.h"
#include <memory>
/*
Manages the read and write functionality
Uses unqique pointers for reading and writing.
*/
class FileController
{
public:
	FileController(std::string);
	FileController();
	~FileController();

	/*A function that calls the write function from FileWriter class*/
	void Write(std::string);

	/*A function that calls the read function from FileReader class*/
	void Read();
private:
	std::unique_ptr<FileWriter> writer;
	std::unique_ptr<FileReader> reader;
	std::string FileName;
};


#endif // !FCONTROLLER_HEADER
