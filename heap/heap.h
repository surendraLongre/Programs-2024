#ifndef HEAP_H
#define HEAP_H

//aliases
typedef int index;

class Heap
{
	private:
		int arr[50]{}; //array for storing heap data which must be non-zero
		bool is_max_heap;
		int size;

	public:
		Heap();
		void insert(int);
		void display();
		bool is_arranged(index); //to check whether it's min or max or not
		void arrange();	//arrange if not already arranged
		void swap(index, index);
		int del();
};

#endif
