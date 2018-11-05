#include "FileController.h"


FileController::FileController()
{
}

FileController::FileController(std::string filename) : FileName{ filename }, writer{}
{
	writer = std::make_unique<FileWriter>(FileWriter());
	reader = std::make_unique<FileReader>(FileReader());
}


FileController::~FileController()
{
}

std::vector<char> FileController::Read()
{
	return reader->ReadFile(FileName);
}

std::vector<int> FileController::GetBinary() 
{
	return reader->ReadBinary(FileName);
}

void FileController::Write(std::string content)
{
	writer->WriteToFile(FileName, content);

}
