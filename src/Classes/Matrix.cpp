/*
 * Matrix.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: Elliot
 */

#include "Matrix.h"
#include "Vector.h"

namespace std {

Matrix::Matrix(int SizeX,int SizeY){
	this->sizeX=SizeX;
	this->sizeY=SizeY;
	this->pvalues = new Vector(sizeX*sizeY);
}

Matrix::Matrix(int columns,int rows,Vector vect){
	sizeX=columns;
	sizeY=rows;
	pvalues = new Vector(columns*rows,vect.values);
}

Matrix::~Matrix() {
	if (!pvalues || sizeX*sizeY!=0)
		delete pvalues;
	pvalues = NULL;
}

Matrix::Matrix(const Matrix& mat){
	this->sizeX = mat.sizeX;
	this->sizeY = mat.sizeY;
	this->pvalues = new Vector(mat.sizeX*mat.sizeY,mat.pvalues->values);
}


/////////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


float Matrix::getValue(int row,int column){
	return (pvalues->values[(row-1)*sizeX+column-1]);
}

Vector Matrix::getColumn(int colNumber){
	Vector* pvect = new Vector(sizeY);
	for (int i=0;i<sizeY;i++){
		pvect->values[i] = pvalues->values[i*sizeX+colNumber-1];
	}
	return *pvect;
	delete pvect;
}

Vector Matrix::getRow(int rowNumber){
	Vector* pvect = new Vector(sizeX);
	for (int i=0;i<sizeX;i++){
		pvect->values[i] = pvalues->values[(rowNumber-1)*sizeX+i];
	}
	return *pvect;
	delete pvect;
}

void Matrix::setColumn(int colNumber,Vector vectColumn){
	for(int i=0;i<sizeY;i++)
		this->pvalues->values[i*sizeX+colNumber-1] = vectColumn.values[i];
}

void Matrix::setRow(int rowNumber,Vector vectLine){
	for(int i=0;i<sizeX;i++)
		this->pvalues->values[(rowNumber-1)*sizeX+i] = vectLine.values[i];
}

void Matrix::print(){
	cout<<"\n" <<"Matrix = " <<endl;
	for(int i=1;i<=this->sizeY;i++){
		this->getRow(i).print();
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

float Matrix::det(){
	return -1;
}

Matrix& Matrix::transpose(){
	if (sizeX * sizeY != 0 && pvalues != NULL) {
		Vector* temp = new Vector(sizeX * sizeY);
		for (int i = 0; i < sizeX; i++) {
			for (int j = 0; j < sizeY; j++) {
				temp->values[i * sizeX + j] = this->pvalues->values[j * sizeY
						+ i];
			}
		}
		Matrix* tempmat = new Matrix(sizeY, sizeX, *temp);
		delete temp;
		return *tempmat;
		delete tempmat;
	} else {
		cerr << "Error : cannot transpose empty matrix" << endl;
		throw -1;
	}
}

Matrix Matrix::negate(){
	*this->pvalues = *this->pvalues*-1;
	return *this;
}

Matrix& Matrix::operator*(Matrix const& A){
	if (sizeX*sizeY != 0 && A.sizeX!=sizeY && A.sizeY != sizeX) {
		Vector* temp = new Vector(sizeX*sizeY);
		for(int i=0;i<sizeY;i++){
			for(int j=0;j<sizeX;j++){
				double sumA = 0;
				for (int k=0;k<sizeY;k++){
					sumA = sumA + A.pvalues->values[k*sizeX+j]; //const empeche l'utilisation du getColumn sur A
				}
				temp->values[i*sizeX+j] = this->getRow(i).sumUp()*sumA;
			}
		}
		Matrix* tempmat = new Matrix(sizeX,sizeY,*temp);
		delete temp;
		return *tempmat;
		delete tempmat;
	} else {
		cerr << "Error : cannot product empty matrix or not equal dimensions" << endl;
		throw -1;
	}
}

Matrix& Matrix::operator*(double a){
	if (sizeX*sizeY != 0) {
		Vector* temp = new Vector(sizeX*sizeY);
		*temp = *this->pvalues*a;
		Matrix* tempmat = new Matrix(sizeX,sizeY,*temp);
		delete temp;
		return *tempmat;
		delete tempmat;
	} else {
		cerr << "Error : cannot product empty Matrix with scalar" << endl;
		throw -1;
	}
}

Matrix& Matrix::operator+(Matrix const& A){
	if (sizeX*sizeY != 0) {
		Vector* temp = new Vector(sizeX*sizeY);
		*temp = *this->pvalues + *A.pvalues;
		Matrix* tempmat = new Matrix(sizeX,sizeY,*temp);
		return *tempmat;
		delete temp;
		delete tempmat;
	} else {
		cerr << "Error : cannot product empty vectors with scalar" << endl;
		throw -1;
	}
}

Matrix& Matrix::operator-(Matrix const& A){
	if (sizeX*sizeY != 0) {
		Vector* temp = new Vector(sizeX*sizeY);
		*temp = *this->pvalues - *A.pvalues;
		Matrix* tempmat = new Matrix(sizeX,sizeY,*temp);
		return *tempmat;
		delete temp;
		delete tempmat;
	} else {
		cerr << "Error : cannot product empty vectors with scalar" << endl;
		throw -1;
	}
}

Matrix& Matrix::operator=(const Matrix& mat){
	if((sizeX != mat.sizeX) || (sizeY!=mat.sizeY) || pvalues == NULL){
		sizeX = mat.sizeX;
		sizeY = mat.sizeY;
		if(pvalues != NULL)
			delete pvalues;
		pvalues = new Vector(mat.sizeX*mat.sizeY);
	}
	this->pvalues = mat.pvalues;
	return *this;

}




} /* namespace std */
