#include "MessageEncoder.h"
#include "MatrixBuilder.h"
#include "ThreeByThreeMatrixBuilder.h"
#include <iterator>
std::vector<double> MessageEncoder::encode(std::string phrase, Key& k) {
	MatrixBuilder * threeByThree = new ThreeByThreeMatrixBuilder();
	Matrix encodingMatrix = threeByThree->createMatrix();
	std::vector<double> encodedVals; // return value
	std::string::iterator strIter = phrase.begin();
	std::vector<std::vector<double>> threeLettersMatrix;
	std::vector<double> row;
	int count = 0;
	while (strIter != phrase.end()) {
		count++;
		double ch = *strIter;
		row.push_back(ch);
		if (row.size() == 3) {
			threeLettersMatrix.push_back(row);
			// Transpose matrix before multiplying to satisfy (m * n)(n * m) rule
			Matrix letters(threeLettersMatrix);
			letters = Matrix::transpose(letters);
			Matrix encodedLettersMatrix = Matrix::multiply(encodingMatrix, letters);
			std::vector<std::vector<double>> encodedLettersMatrix_ = encodedLettersMatrix.getMatrix();

			// Now put the encoded values in the newly encoded matrix into encodedVals
			for (std::vector<double> num : encodedLettersMatrix_) {
				encodedVals.push_back(num[0]);
			}

			// Reset variables
			threeLettersMatrix.clear();
			row.clear();
		}
		strIter++;
	}
	// CHECK IF THERE ARE LEFTOVER CHARACTERS IF
	// THE WHOLE STR IS NOT DIVISIBLE BY 3 RIGHT HERE!!!
	if (count % 3 != 0) {
		for (int i = 0; i < 3 - (count % 3); i++) {
			row.push_back(' ');
		}
		threeLettersMatrix.push_back(row);
		// Transpose matrix before multiplying to satisfy (m * n)(n * m) rule
		Matrix letters(threeLettersMatrix);
		letters = Matrix::transpose(letters);
		Matrix encodedLettersMatrix = Matrix::multiply(encodingMatrix, letters);
		std::vector<std::vector<double>> encodedLettersMatrix_ = encodedLettersMatrix.getMatrix();

		// Now put the encoded values in the newly encoded matrix into encodedVals
		for (std::vector<double> num : encodedLettersMatrix_) {
			encodedVals.push_back(num[0]);
		}
	}
	Matrix inverse = Matrix::inverse(encodingMatrix);
	k.setinverseMatrix(inverse);
	return encodedVals;
}