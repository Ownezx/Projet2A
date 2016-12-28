//============================================================================
// Name        : Projet2A.cpp
// Author      : Elliot Drees
// Version     :
// Copyright   : Blahblah
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "Classes/Vector.h"
#include "Classes/Matrix.h"
#include "Classes/CompMatrix.h"
using namespace std;

int main() {

	cout<<"Tests on Vector Class>>>>>>>>>>>>>"<<endl;

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

	//vec1+vec2;
	Vector vec3 = vec1;
	vec3.print();
	vec3=vec1+vec3;
	vec3.print();
	vec3 = vec3*5;
	vec3.print();
	cout<<vec3.sumUp()<<endl;
	vec1.negate();
	vec3 = vec3-vec1;
	vec3.print();
	cout<<vec1.sumUp()<<endl;


	cout<<"Tests valid,\n\nTests on Matrix class>>>>>>>>>>>>>"<<endl;

	float matrixbrut2[16];
	float matrixbrut3[4];
	float matrixbrut1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	Vector vectmatrix1(16,matrixbrut1);
	Vector vectmatrix2 = vectmatrix1*-1;
	Matrix mat1(4,4,vectmatrix1);

	for(int i=1;i<=4;i++){
		mat1.getColumn(i).print();}
	mat1.print();

	Matrix mat2 = mat1*-1;



	mat2.print();
	mat1.print();

	Matrix mat3 = mat2+mat1;
	mat3.print();
	Matrix mat4 = mat2 - mat1;
	mat4.print();
	cout<<"ewqieuiwhferwui"<<endl;
	mat2 = mat2 - mat1;
	mat2.print();
	mat2 = mat2*2;
	mat2.print();
	mat3 = mat2.transpose();
	mat3.print();
	//mat4.print();

	cout<<"Putain ca maaaaaaaaaaarche paaaaaaaaaas!ewuiqfy8324q9udasix 3192bfxy 820"<<endl;






	return 0;
}
