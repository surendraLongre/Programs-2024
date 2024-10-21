#ifndef LOWERTRIANGULAR_H
#define LOWERTRIANGULAR_H
#include<iostream>
#include "matrix.h"
#include<cmath>

//bug: currently the length variable increases even by just changing the currently existing

template<class T>
class LowerTriangular:public Matrix<T>
{
	public:
		LowerTriangular();
		void display();
		void append(T, int, int);
		T get(int,int);
};

template<class T>
LowerTriangular<T>::LowerTriangular()
{
	this->arr=new T[55];
	this->mn=55;
	this->length=0;
}

template<class T>
void LowerTriangular<T>::display()
{
	int limit=sqrt(1+8*this->length);
	limit=(limit-1)/2;
	for(int i=0; i!=limit; i++){
		for(int j=0; j!=limit; j++)
		{
			std::cout<<get(i,j)<<" ";
		} std::cout<<std::endl;
	}
}

template<class T>
T LowerTriangular<T>::get(int i, int j)
{
	try{
		if(i<0 || j<0 || i>=this->length || j>=this->length)
			throw std::string("invalid index");
		if(i<j)
			return T{};
		return this->arr[i*(i+1)/2+j];
	} catch(std::string str) {
		std::cout<<"error: "<<str<<std::endl;
	}
		return T{};
}

template<class T>
void LowerTriangular<T>::append(T var, int i, int j)
{
	try{
		if(i<0 || j<0 || i>=this->mn || j>=this->mn)
			throw std::string("invalid index");
		if(i<j)
			throw std::string("already zero");
		try{
			if(this->mn==this->length)
				throw std::string("Size exceeded");
			this->arr[i*(i+1)/2+j]=var;
			this->length++;
		} catch(std::string str){
			std::cout<<"error: "<<str<<std::endl;
		}	
	} catch(std::string str) {
		std::cout<<"error: "<<str<<std::endl;
	}
}

#endif
