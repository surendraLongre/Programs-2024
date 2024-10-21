#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H
#include<iostream>
#include "matrix.h"

template<class T>
class TriDiagonal:public Matrix<T>
{
	public:
		TriDiagonal();
		void display();
		void append(T, int, int);
		T get(int, int);
		TriDiagonal(int, T* arr2=nullptr, int arr2_len=0);
};

template<class T>
TriDiagonal<T>::TriDiagonal()
{
	this->arr=new T[28];
	this->mn=28;
	this->length=0;
}

template<class T>
void TriDiagonal<T>::display()
{
	int limit{};
	if(this->length<5)
		limit=sqrt(this->length);
	else{
		limit=(this->length-4)/3+2;
	}

	for(int i=0; i!=limit; i++){
		for(int j=0; j!=limit; j++)
		{
			std::cout<<get(i,j)<<" ";
		} std::cout<<std::endl;
	}
}

template<class T>
T TriDiagonal<T>::get(int i, int j)
{
	try{
		if(i<0 || j<0 || i>=this->length || j>=this->length)
			throw std::string("invalid index");
		if(abs(i-j)>1)
			return 0;
		else if(i==0)
			return this->arr[j];
		return this->arr[2+3*(i-1)+j];
	} catch(std::string str) {
		std::cout<<"error: "<<str<<std::endl;
	}
		return T{};
}

template<class T>
void TriDiagonal<T>::append(T var, int i, int j)
{
	try{
		if(i<0 || j<0 || i>=this->mn || j>=this->mn)
			throw std::string("invalid index");
		if(std::abs(i-j)>1)
			throw std::string("default to zero");
		try{
			if(this->mn==this->length)
				throw std::string("Size exceeded");
			if(i==0)
				this->arr[j]=var;
			else{
				this->arr[2+3*(i-1)+j]=var;
			}
			this->length++;
		} catch(std::string str){
			std::cout<<"error: "<<str<<std::endl;
		}	
	} catch(std::string str) {
		std::cout<<"error: "<<str<<std::endl;
	}
}

#endif
