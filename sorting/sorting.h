#ifndef SORTING_H
#define SORTING_H
typedef int index;

class Sorting
{
	protected:
		int *arr;
		int size;
		int max_size;
	public:
		Sorting();
		void display();
		void swap(int, int);
		int get_size();
};

class Bubble:public Sorting
{
	public:
		Bubble();
		void sort();
};

class Insertion:public Sorting
{
	public:
		Insertion();
		void insert(int);
};

class Selection:public Sorting
{
	public:
		Selection();
		void sort();
};

class QuickSort:public Selection
{
	public:
		void sort(index, index);
};

class Merging: public Sorting
{
	public:
		Merging();
		void merge(int *, int *, int, int);
};

class Count:public Bubble
{
	public:
		void sort();
};

#endif
