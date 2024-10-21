#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>

template<class T>
class Matrix
{
protected:
	T *arr;
	int mn{};
	int length{};
	virtual void display()=0;
	virtual void append(T, int, int)=0;
	virtual T get(int, int)=0;
	~Matrix();
};

template<class T>
Matrix<T>::~Matrix()
{
	delete arr;
}
#endif
