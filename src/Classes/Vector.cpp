/*
 * Vector.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: Elliot
 */

#include "Vector.h"
#include <math.h>

namespace std {



Vector::Vector(int Size) {
	size = Size;
	values = new float[size];
}

Vector::Vector(int Size, float* Values) {
	size = Size;
	values = Values;
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}


void Vector::setValue(int pos, float value) {
	if(pos<size){
		values[pos]=value;
	}
	else{
		cout<<"Error : cannot assign value to higher dimentions"<<endl;
		throw -1;
	}
}

int Vector::getSize() {
	return size;
}

float Vector::scalar(const Vector& A) {
	if(this->size==A.size){
		float sum = 0;
		for(int i=0; i< size; i++){
			sum+=values[i]*A.values[i];
		}
		return sum;
	}
	else{
		cout<<"Error : cannot scalar vector with different dimensions"<<endl;
		throw -1;
	}
}

float Vector::norm() {
	float sum = 0;
	for(int i=0; i< size; i++){
				sum+=values[i]*values[i];
			}
	sum = sqrt(sum);
	return sum;
}

int Vector::max() {
	float max = values[0];
	int posmax = 0;
	for(int i=1; i< size; i++){
				if (values[i]>max){
					posmax=i;
					max=values[i];
				}
			}
	return posmax;
}


} /* namespace std */



