/*
 * Vector.h
 *
 *  Created on: Dec 15, 2016
 *      Author: Elliot
 */

#ifndef CLASSES_VECTOR_H_
#define CLASSES_VECTOR_H_

namespace std {

class Vector {

public:
	int size;
	float* values;

public:
	Vector(int);
	Vector(int,float*);
	virtual ~Vector();

	void setValue(int,float);
	int getSize();

	float scalar(Vector const& A);
	float norm();
	int max();
	Vector operator*(Vector const& A, Vector const& B);
	Vector negate();
	Vector operator-(Vector const& A, Vector const& B);
	Vector operator+(Vector const& A, Vector const& B);


};

} /* namespace std */

#endif /* CLASSES_VECTOR_H_ */
