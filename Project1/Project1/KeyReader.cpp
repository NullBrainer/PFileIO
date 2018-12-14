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
	
	// MatrixAndPositions holds Matrix in [0] and Positions in [1]
	// after splitting by #
	std::vector<std::string> MatrixAndPositions = split(info, delimiter);
	
	// Parsing Matrix from MatrixAndPositions
	std::vector<std::string> matrixRowsStrings = split(MatrixAndPositions[0], " ");
	std::vector<std::vector<double>> matrixVector(3, std::vector<double>());
	for (size_t i = 0; i < matrixRowsStrings.size(); i++) 
	{
		std::vector<std::string> matrixRowString = split(matrixRowsStrings[i], ",");
		for (size_t j = 0; j < matrixRowString.size(); j++)
		{
			matrixVector[i].push_back(std::stod(matrixRowString[j]));
		}
	}

	Matrix matrix(matrixVector);

	// Parsing Positions from MatrixAndPositions
	std::vector<std::string> positionsString = split(MatrixAndPositions[1], " ");
	std::list<std::tuple<int, int, int>> positions;
	// Parsing tuples from the split string
	for (size_t i = 0; i < positionsString.size(); i++) {
		std::vector<std::string> positionTupleString = split(positionsString[i], ",");
		std::tuple<int, int, int> positionTuple;
		int x = std::stod(positionTupleString[0]);
		int y = std::stod(positionTupleString[1]);
		int quotient = std::stod(positionTupleString[2]);
		positionTuple = std::make_tuple(x, y, quotient);
		positions.push_back(positionTuple);
	}
	
	Key key;
	key.setinverseMatrix(matrix);
	key.setPosQuotient(positions);
	
	return key;
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

std::string KeyReader::MakeString(std::vector<char> vect)
{
	std::string result = "";
	for (int i = 0; i < vect.size(); i++)
	{
		result.push_back(vect[i]);
	}
	return result;
}

std::vector<std::string> KeyReader::split(std::string str, std::string delim) {
	std::vector<std::string> splitStr;
	size_t pos = 0;
	std::string token;
	while ((pos = str.find(delim)) != std::string::npos) {
		token = str.substr(0, pos);
		splitStr.push_back(token);
		str.erase(0, pos + delim.length());
	}
	splitStr.push_back(str);
	return splitStr;
}