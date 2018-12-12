#ifndef FILE_WRITE_HEADER
#define FILE_WRITE_HEADER

#include <string>
#include <fstream>
#include <iostream>

class FileWriter
{
public:
	FileWriter();
	~FileWriter();	

	/*Creates a output filestream and writes to the file
	filename is used to set the file name
	content is used to write the string into the file*/
	virtual void WriteToFile(std::string,std::string);

private:

};


#endif // !FILE_WRITE_HEADER