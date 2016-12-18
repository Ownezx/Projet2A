/*
 * Matrix.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: Elliot
 */

#include "Matrix.h"

namespace std {

Matrix::Matrix(int SizeX,int SizeY) {
	sizeX=SizeX;
	sizeY=SizeY;
	values = Vector(sizeX*sizeY);
	// TODO Auto-generated constructor stub

}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
