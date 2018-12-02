#ifndef THREEBYTHREEMATRIXBUILDER_H
#define THREEBYTHREEMATRIXBUILDER_H
#include "MatrixBuilder.h"
#include <ctime>
#include <random>

class ThreeByThreeMatrixBuilder : public MatrixBuilder{
public:
	const int ROWS = 3;
	const int COLS = 3;

	ThreeByThreeMatrixBuilder() {
		srand(time(0));
	}
	~ThreeByThreeMatrixBuilder() = default;
	Matrix createMatrix() override {
		std::vector<std::vector<double>> mat;
		for (int i = 0; i < ROWS; i++) {
			std::vector<double> row;
			for (int j = 0; j < COLS; j++) {
				row.push_back(rand() % 51);
			}
			mat.push_back(row);
		}
		Matrix matrix(mat);
		return matrix;
	}
private:
	
};
#endif THREEBYTHREEMATRIXBUILDER_H