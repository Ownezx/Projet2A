/*
 * CompMatrix.h
 *
 *  Created on: Dec 15, 2016
 *      Author: Elliot
 */

#ifndef CLASSES_COMPMATRIX_H_
#define CLASSES_COMPMATRIX_H_

#include "Vector.h"
#include "Matrix.h"
#include <iostream>

namespace std {

class CompMatrix {

public:
	int sizeX;
	int sizeY;
	Vector values=Vector(1);
	Vector position=Vector(1);
	Vector firstElementOfLine=Vector(1);

public:
	CompMatrix(int,int);
	CompMatrix(int,int,Vector,Vector,Vector);
	virtual ~CompMatrix();

	float getValue(int,int);
	Vector getLine(int);
	Vector getRow(int);
	void setValue(int,int,float);
	void setRow(int,Vector);
	void setLine(int, Vector);

	float det(); //TODO
	CompMatrix transpose(); //TO CORRECT
	CompMatrix negate();
	CompMatrix operator*(CompMatrix const& A);
	CompMatrix operator+(CompMatrix const& A);
	CompMatrix operator-(CompMatrix const& A);
	Matrix ConvertToMatrix(); //TODO

};

} /* namespace std */

#endif /* CLASSES_COMPMATRIX_H_ */
