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

	Vector vec1 = Vector(4);
	vec1.setValue(0,1);
	vec1.setValue(1,2);
	vec1.setValue(2,3);
	vec1.setValue(3,4);
	vec1.print();
	Vector vec2 = Vector(3);
	vec2.setValue(0,1);
	vec2.setValue(1,1);
	vec2.setValue(2,1);
	vec2.print();

	vec1+vec2;

	return 0;
}
