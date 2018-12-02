#ifndef KEY_H
#define KEY_H
#include "Matrix.h"
#include <list>
class Key {
public:
	std::list<std::pair<int, int>> getPositions() {
		return posLens;
	}
	Matrix getInverseMatrix() {
		return inverseMatrix;
	}

	void setinverseMatrix(Matrix m) {
		inverseMatrix = m;
	}

	void setPosLens(std::list<std::pair<int, int>> p) {
		posLens = p;
	}

private:
	std::list<std::pair<int, int>> posLens;
	Matrix inverseMatrix;

};
#endif KEY_H