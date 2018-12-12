#ifndef KEY_H
#define KEY_H
#include "Matrix.h"
#include <list>
#include <tuple>
class Key {
public:
	std::list<std::tuple<int, int, int>> getPositionsQuotients() {
		return posQuotient;
	}
	Matrix getInverseMatrix() {
		return inverseMatrix;
	}

	void setinverseMatrix(Matrix m) {
		inverseMatrix = m;
	}

	void setPosQuotient(std::list<std::tuple<int, int, int>> p) {
		posQuotient = p;
	}

private:
	// TAKE IN TUPLE FOR X POS, Y POS, THEN QUOTIENT
	std::list<std::tuple<int, int, int>> posQuotient;
	Matrix inverseMatrix;

};
#endif KEY_H