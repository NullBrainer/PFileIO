#include "Matrix.h"
// PUBLIC

Matrix::Matrix(std::vector<std::vector<double>> matrix) {
	this->matrix = matrix;
}

void Matrix::setMatrix(std::vector<std::vector<double>> matrix) {
	this->matrix = matrix;
}

std::vector<std::vector<double>> Matrix::getMatrix() {
	return matrix;
}

Matrix Matrix::transpose(Matrix matrix) {
	std::vector<std::vector<double>> transposed;
	std::vector<std::vector<double>> origMatrix = matrix.getMatrix();
	// initialize matrix to 0
	for (int i = 0; i < origMatrix[0].size(); i++) {
		std::vector<double> row(origMatrix.size(), 0);
		transposed.push_back(row);
	}
	// transpose original matrix and save into transposed
	for (int i = 0; i < origMatrix.size(); i++) {
		for (int j = 0; j < origMatrix[i].size(); j++) {
			transposed[j][i] = origMatrix[i][j];
		}
	}
	Matrix matrixT(transposed);
	return matrixT;
}

Matrix Matrix::cofactors(Matrix m) {
	std::vector<std::vector<double>> origMatrix = m.getMatrix();
	std::vector<std::vector<double>> cof;
	double one = 1;
	for (int i = 0; i < origMatrix.size(); i++) {
		std::vector<double> row;
		for (int j = 0; j < origMatrix[0].size(); j++) {
			row.push_back(one);
			one = one * (-1);
		}
		cof.push_back(row);
	}
	Matrix cofactorMatrix(cof);
	return cofactorMatrix;
}

double Matrix::determinant(Matrix m) {
	std::vector<std::vector<double>> origMatrix = m.getMatrix();
	double rows = origMatrix.size();
	double columns = origMatrix[0].size();
	double determ = 0;
	if (rows == columns && (rows == 2)) {
		determ = (origMatrix[0][0] * origMatrix[1][1]) - (origMatrix[1][0] * origMatrix[0][1]);
		return determ;
	}
	else {
		Matrix cof = Matrix::cofactors(m);
		std::vector<std::vector<double>> cofactors = cof.getMatrix();

		for (int i = 0; i < origMatrix[0].size(); i++) {
			Matrix nMatrix;
			std::vector<std::vector<double>> nMatrixParam;
			for (int row = 0; row < origMatrix.size(); row++) {
				if (row != 0) {
					std::vector<double> nRow;
					for (int column = 0; column < origMatrix[0].size(); column++) {
						if (column != i) {
							nRow.push_back(origMatrix[row][column]);
						}
					}
					nMatrixParam.push_back(nRow);
				}
			}
			nMatrix.setMatrix(nMatrixParam);
			determ = determ + (origMatrix[0][i] * cofactors[0][i] * determinant(nMatrix));
		}
		return determ;
	}
}

Matrix Matrix::minors(Matrix m) {
	std::vector<std::vector<double>> origMatrix = m.getMatrix();
	std::vector<std::vector<double>> minorsMatrix;
	std::vector<std::vector<double>> cofactorsMatrix = Matrix::cofactors(m).getMatrix();
	for (int i = 0; i < origMatrix.size(); i++) {
		std::vector<double> minorsRow;
		for (int j = 0; j < origMatrix[0].size(); j++) {
			std::vector<std::vector<double>> nMatrix;
			for (int r = 0; r < origMatrix.size(); r++) {
				if (r != i) {
					std::vector<double> row;
					for (int c = 0; c < origMatrix[0].size(); c++) {
						if (c != j) {
							row.push_back(origMatrix[r][c]);
						}
					}
					nMatrix.push_back(row);
				}
			}
			Matrix m2(nMatrix);
			minorsRow.push_back(Matrix::determinant(m2) * cofactorsMatrix[i][j]);
		}
		minorsMatrix.push_back(minorsRow);
	}
	Matrix matrixOfMinors(minorsMatrix);
	return matrixOfMinors;
}

Matrix Matrix::adjugate(Matrix m) {
	Matrix adjugateMatrix = Matrix::transpose(Matrix::minors(m));
	return adjugateMatrix;
}

Matrix Matrix::inverse(Matrix m) {
	Matrix adjugateMatrix = Matrix::adjugate(m);
	double determ = Matrix::determinant(m);
	std::vector<std::vector<double>> inv = adjugateMatrix.getMatrix();
	for (int i = 0; i < inv.size(); i++) {
		for (int j = 0; j < inv[0].size(); j++) {
			inv[i][j] = inv[i][j] / determ;
		}
	}
	Matrix inverseMatrix(inv);
	return inverseMatrix;
}

Matrix Matrix::multiply(Matrix m1, Matrix m2) {
	std::vector<std::vector<double>> matrix1 = m1.getMatrix();
	std::vector<std::vector<double>> matrix2 = m2.getMatrix();
	std::vector<std::vector<double>> resultMatrix;

	for (int i = 0; i < matrix1.size(); i++) { // for every row in m1
		std::vector<double> resultRow;

		for (int j = 0; j < matrix2[0].size(); j++) { // go through every column in m2
			double product = 0;
			for (int k = 0; k < matrix1[0].size(); k++) { // multiply each row in m1 by each column in m2
				product += matrix1[i][k] * matrix2[k][j];
			}
			resultRow.push_back(product);
		}
		resultMatrix.push_back(resultRow);
	}
	Matrix result(resultMatrix);
	return result;
}
