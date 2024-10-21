#ifndef DIAGONAL_H
#define DIAGONAL_H
#include "matrix.h"
#include<iostream>

template<class T>
class Diagonal:public Matrix<T>
{
public:
	Diagonal();
	Diagonal(int, T* arr2=nullptr, int arr2_len=0);
	void display();
	void append(T, int i=0, int j=0);
	T get(int, int);
};

template<class T>
Diagonal<T>::Diagonal()
{
	this->arr=new T[10];
	this->mn=10;
	this->length=0;
}

template<class T>
void Diagonal<T>::display()
{
	for(int i=0; i!=this->length; i++)
	{
		for(int j=0; j!=this->length; j++)
		{
			std::cout<<get(i,j)<<" ";
		} 
		std::cout<<std::endl;
	}

}

template<class T>
void Diagonal<T>::append(T var, int i, int j)
{
	try{
		if(this->mn==this->length)
			throw std::string("Size exceeded");
		this->arr[this->length++]=var;
	} catch(std::string str){
		std::cout<<"error: "<<str<<std::endl;
	}	
}

template<class T>
Diagonal<T>::Diagonal(int l, T *arr2, int arr2_len)
{
	this->arr=new T[l];
	this->mn=l;
	this->length=0;
	for(int i=0; i!=arr2_len; i++)
		append(arr2[i]);
}

template<class T>
T Diagonal<T>::get(int i, int j)
{
	try{
		if(i<0 || j<0 || i>=this->length || j>=this->length)
			throw std::string("invalid index");
		if(i==j)
			return this->arr[i];
		return T{};
	} catch(std::string str){
		std::cout<<"error: "<<str<<std::endl;
	}
	return T{};
}

#endif
