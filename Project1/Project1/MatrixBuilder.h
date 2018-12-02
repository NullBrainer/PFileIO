#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H
#include <memory>
#include "Matrix.h"
class MatrixBuilder {
public:
	MatrixBuilder() {};
	virtual ~MatrixBuilder() = default;
	virtual Matrix createMatrix() = 0;
};
#endif MATRIXBUILDER_H