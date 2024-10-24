#ifndef TOEPLITZ_H
#define TOEPLITZ_H
#include<iostream>
#include "matrix.h"

template<class T>
class Toeplitz:public Matrix<T>
{
	public:
		Toeplitz();
		Toeplitz(int);
		void display();
		void append(T, int, int);
		T get(int, int);
};

template<class T>
Toeplitz<T>::Toeplitz()
{
	this->arr=new T[19];
	this->mn=19;
	this->length=0;
}

template<class T>
Toeplitz<T>::Toeplitz(int order)
{
	this->arr=new T[order*2-1];
	this->mn=order*2-1;
	this->length=0;
}

template<class T>
void Toeplitz<T>::display()
{
	int limit=(this->length+1)/2;

	for(int i=0; i!=limit; i++){
		for(int j=0; j!=limit; j++)
		{
			std::cout<<get(i,j)<<" ";
		} std::cout<<std::endl;
	}
}

//In this toeplitz we're considering only the elements of first column and last column
//we're storing first column elements and then last column elements

template<class T>
T Toeplitz<T>::get(int i, int j)
{
	try{
		if(i<0 || j<0 || i>=this->length || j>=this->length)
			throw std::string("invalid index");
		if(i-j>-1)
			return this->arr[i-j];
		else{
			return this->arr[this->length/2+i-j+(this->length+1)/2];
		}
	} catch(std::string str) {
		std::cout<<"error: "<<str<<std::endl;
	}
		return T{};
}

template<class T>
void Toeplitz<T>::append(T var, int i, int j)
{
	try{
		if(i<0 || j<0 || i>=this->mn || j>=this->mn)
			throw std::string("invalid index");
		try{
			if(this->mn==this->length)
				throw std::string("Size exceeded");
			if(i-j>-1)
				this->arr[i-j]=var;
			else{
				this->arr[this->mn/2+i-j+(this->mn+1)/2]=var;
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
