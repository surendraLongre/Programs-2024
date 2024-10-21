#include<iostream>
#include "matrix.h"
#include "diagonal.h"
#include "lowerTriangular.h"
#include "triDiagonal.h"

int main()
{
	TriDiagonal<int>t1;
	t1.append(15,0,0);
	t1.append(25,0,1);
	t1.append(35,1,0);
	t1.append(45,1,1);
	t1.append(55,1,2);
	t1.append(65,2,1);
	t1.append(45,2,2);
	t1.display();
}
