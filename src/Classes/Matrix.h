/*
 * Matrix.h
 *
 *  Created on: Dec 15, 2016
 *      Author: Elliot
 */

#ifndef CLASSES_MATRIX_H_
#define CLASSES_MATRIX_H_

#include "Vector.h"
#include "CompMatrix.h"
#include <iostream>

namespace std {

class Matrix {

public:
	int sizeX;
	int sizeY;
	Vector *pvalues;

public:
	Matrix(int,int);
	Matrix(int,int,Vector);
	virtual ~Matrix();
	Matrix(const Matrix& mat);

	float getValue(int,int);
	Vector getColumn(int);
	Vector getRow(int);
	void setValue(int,int,float);
	void setRow(int,Vector);
	void setColumn(int, Vector);
	void print();

	float det();
	Matrix& transpose();   //TO CORRECT
	Matrix negate();
	Matrix& operator*(Matrix const& A);
	Matrix& operator*(double a);
	Matrix& operator+(Matrix const& A);
	Matrix& operator-(Matrix const& A);
	Matrix& operator=(const Matrix& mat);
	CompMatrix convertToComp();     //TODO






};

} /* namespace std */

#endif /* CLASSES_MATRIX_H_ */
