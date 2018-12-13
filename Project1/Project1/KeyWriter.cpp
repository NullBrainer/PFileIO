#include "KeyWriter.h"

KeyWriter::KeyWriter()
{
}

KeyWriter::~KeyWriter()
{
}

void KeyWriter::WriteKeyToFile(std::string filename, Key kobj)
{
	std::string info = ParseKey(kobj);
	writer->WriteToFile(filename+".KEY",info);

}

std::string KeyWriter::ParseKey(Key kobj)
{
	std::string result = "";
	
	result.append(ParseMatrix(kobj) + "#" + ParsePositions(kobj));

	return result;
}

std::string KeyWriter::ParseMatrix(Key kobj)
{
	std::string result = "";
	auto matrix = kobj.getInverseMatrix().getMatrix();
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			result.append(std::to_string(matrix[i][j]));
			if (j < matrix[j].size() - 1) {
				result.append(",");
			}
			else if (j == matrix[i].size() - 1 && i < matrix.size()-1) {
				result.append(" ");
			}

		}
	}
	return result;
}

std::string KeyWriter::ParsePositions(Key kobj)
{
	std::string result = "";
	auto positions = kobj.getPositionsQuotients();
	int d = 0;
	for (auto i = positions.begin(); i != positions.end(); i++)
	{
		auto toopl = *i;
		result.append( std::to_string(std::get<0>(toopl)) + "," + std::to_string(std::get<1>(toopl)) + "," + std::to_string(std::get<2>(toopl)));
		if (d < positions.size()-1)
		{
			result.append(" ");
		}
		d++;
	}

	return result;
}


