#include "FileWrite.h"



FileWriter::FileWriter()
{
}

FileWriter::~FileWriter()
{
}


void FileWriter::WriteToFile(std::string filename,std::string content)
{
	std::ofstream newFile(filename);
	newFile.write(content.c_str(), content.size());
	newFile.close();
}


