//============================================================================
// Name        : Projet2A.cpp
// Author      : Elliot Drees
// Version     :
// Copyright   : Blahblah
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Classes/Vector.h"
using namespace std;

int main() {
	cerr << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Vector vec1 = Vector(3);
	vec1.setValue(0,1);
	vec1.setValue(1,2);
	vec1.setValue(2,3);
	vec1.print();
	Vector vec2 = Vector(3);
	vec2.setValue(0,1);
	vec2.setValue(1,1);
	vec2.setValue(2,1);
	vec2.print();

	(vec2.negate());
	vec2.print();

	return 0;
}
