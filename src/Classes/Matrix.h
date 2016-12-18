/*
 * Matrix.h
 *
 *  Created on: Dec 15, 2016
 *      Author: Elliot
 */

#ifndef CLASSES_MATRIX_H_
#define CLASSES_MATRIX_H_

#include "Vector.h"
#include <iostream>

namespace std {

class Matrix {

public:
	int sizeX;
	int sizeY;
	Vector values=Vector(sizeX*sizeY);

public:
	Matrix(int,int);
	Matrix(int,int,Vector);
	virtual ~Matrix();

	float getValue(int,int);
	Vector getLine(int);
	Vector getRow(int);
	void setValue(int,int,float);
	void setRow(int,Vector);
	void setLine(int, Vector);

	float det();
	Matrix transpose();
	Matrix negate();
	Matrix operator*(Matrix const& A);
	Matrix operator+(Matrix const& A);
	Matrix operator-(Matrix const& A);





};

} /* namespace std */

#endif /* CLASSES_MATRIX_H_ */
