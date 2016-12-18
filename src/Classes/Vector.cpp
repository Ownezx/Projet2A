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
		cerr<<"Error : cannot assign value to higher dimensions"<<endl;
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
		cerr<<"Error : cannot scalar vectors with different dimensions"<<endl;
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

Vector Vector::operator*(Vector const& A){
	if(size==A.size && A.size==3){
		float* vals = new float[A.size];
		for (int i=0; i<size ; i++){
			vals[i]=values[i]*A.values[(i+1)%3] - values[(i+1)%3]*A.values[i];
		}
		return Vector(A.size,vals);

	}
	else{
		cerr<<"Error : cannot dot product vectors with different dimensions or with dimension different than 3"<<endl;
		throw -1;
	}
}

void Vector::negate(){
	for(int i=0; i< size; i++){
		values[i]= -values[i];
			}
}

Vector Vector::operator-(Vector const& A){
	if(size==A.size){
		float* vals =new float[size];
		for(int i=0; i< A.size; i++){
			vals[i] = values[i]-A.values[i];
				}
		return Vector(A.size,vals);
	}
	else{
		cerr<<"Error : cannot substract vectors with different dimensions"<<endl;
		throw -1;
	}
}

Vector Vector::operator+(Vector const& A){
	if(size==A.size){
		float* vals =new float[size];
		for(int i=0; i< A.size; i++){
			vals[i] = A.values[i]+values[i];
				}
		return Vector(A.size,vals);
	}
	else{
		cout<<"Error : cannot add vectors with different dimensions"<<endl;
		throw -1;
	}
}

void Vector::print(){
	cout<<"(";
	for(int i=0; i< size-1; i++){
		cout<<values[i]<<",";
			}
	cout<<values[size-1]<<")"<<endl;
}



} /* namespace std */



