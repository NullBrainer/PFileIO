#include "KeyReader.h"



KeyReader::KeyReader()
{
}


KeyReader::~KeyReader()
{
}
/*tokenizing strings that represent the matrix and the positions for Key Object*/
Key KeyReader::ReadFromFile(std::string filename)
{
	
	std::vector<char> v = reader->ReadFile(filename);
	std::string info = MakeString(v);


	std::vector<std::vector<double>> matrixvector;
	std::string delimiter = "#";
	
	std::string token = info.substr(0, info.find(delimiter));
	std::vector<std::vector<double>> matrix = CreateVector(token);

	token = info.substr(0, info.find(delimiter));//get next token TODO 
	auto positions = Positions(token);
	
	return ;
}
/*
takes a string to be parsed into a vector to be used for creating a Matrix object
 a component function used to build the key
TODO
*/
std::vector<std::vector<double>> KeyReader::CreateVector(std::string info)
{

	for (int i = 0; i < info.size(); i++)
	{
		if (info[i] == ',') {

		}
	}
	return std::vector<std::vector<double>>();
}

/*creates and returns a list of tuples, a component function used to build the key*/
std::list<std::tuple<int, int, int>> KeyReader::Positions(std::string info)
{
	return std::list<std::tuple<int, int, int>>();
}

std::string KeyReader::MakeString(std::vector<char> vect)
{
	std::string result = "";
	for (int i = 0; i < vect.size(); i++)
	{
		result.append(vect[i]+"");
	}
	return result;
}

