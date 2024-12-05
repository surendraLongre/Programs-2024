#include<iostream>
#include "matrix.h"
#include "diagonal.h"
#include "lowerTriangular.h"
#include "triDiagonal.h"
#include "toeplitz.h"
#include "sparse.h"
#include "polynomial.h"

int main()
{
	Polynomial p;
	std::cout<<p<<std::endl;
	int x=2;
	std::cout<<p.eval(x);
}
