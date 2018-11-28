#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix {
public:
	Matrix() = default;
	Matrix(std::vector<std::vector<double>>);
	~Matrix() = default;
	Matrix(Matrix const&) = default;

	static Matrix transpose(Matrix);
	static double determinant(Matrix);
	static Matrix adjugate(Matrix);
	static Matrix cofactors(Matrix);
	static Matrix minors(Matrix);
	static Matrix inverse(Matrix);
	static Matrix multiply(Matrix, Matrix);

	void setMatrix(std::vector<std::vector<double>>);
	std::vector<std::vector<double>> getMatrix();

	//Matrix operator*(Matrix const & right) const;
	//Matrix operator*=(Matrix const & right);
private:
	std::vector<std::vector<double>> matrix;
};

#endif MATRIX_H