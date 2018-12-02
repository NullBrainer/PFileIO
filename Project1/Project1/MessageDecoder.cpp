#include "MessageDecoder.h"

std::string MessageDecoder::decode(std::vector<double> encodedValues, Key& key) {
	Matrix decodingMatrix = key.getInverseMatrix();
	std::string decodedMessage = "";

	std::vector<std::vector<double>> rhs;
	std::vector<double> row;
	std::vector<double>::iterator iter = encodedValues.begin();
	while (iter != encodedValues.end()) {
		row.push_back(*iter);
		if (row.size() == 3) {
			rhs.push_back(row);
			Matrix rhsM(rhs);
			// transpose so you can multiply
			rhsM = Matrix::transpose(rhsM);
			// multiply encoded matrix by inverse of the encoding matrix to decode the message
			Matrix decodedMatrix = Matrix::multiply(decodingMatrix, rhsM);
			std::vector<std::vector<double>> decodedMatrix_ = decodedMatrix.getMatrix();
			for (std::vector<double> num : decodedMatrix_) {
				char ch = std::round(num[0]); // round in case operations wrongfully truncate division operations
				decodedMessage.push_back(ch);
			}
			
			// reset
			row.clear();
			rhs.clear();
		}
		iter++;
	}
	return decodedMessage;
}