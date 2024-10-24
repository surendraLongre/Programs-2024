#ifndef SPARSE_H
#define SPARSE_H
#include<iostream>

class Sparse
{
		class Elements
		{
			public:
				int i{}, j{}, k{};
		};
		int m{}, n{}, num{};
		Elements *e;

	public:
		void create(Sparse *s);
		void display();
		int get(int, int);
		friend Sparse operator+(const Sparse &, const Sparse &);
		~Sparse();
};

Sparse operator+(const Sparse &s1, const Sparse &s2)
{
	Sparse to_return;
	to_return.m=s1.m;
	to_return.n=s1.n;
	to_return.num=0;
	to_return.e=new Sparse::Elements[s1.num+s2.num];

	int i=0, j=0, k=0;
	while(i<=s1.num && j<=s2.num)
	{
		if(s1.e[i].Elements::i==s2.e[j].Elements::i && s1.e[i].Elements::j==s2.e[j].Elements::j)
		{
			to_return.e[k].Elements::i=s1.e[i].Elements::i;
			to_return.e[k].Elements::j=s1.e[i].Elements::j;
			to_return.e[k].Elements::k=s1.e[i].Elements::k + s2.e[j].Elements::k;
			std::cout<<"s1 num: "<<s1.e[i].Elements::k<<std::endl;
			std::cout<<"s2 num: "<<s2.e[j].Elements::k<<std::endl;
			i++; j++;
		} else if( s1.e[i].Elements::i==s2.e[j].Elements::i) { //if rows number is equal
			if(s1.e[i].Elements::j>s2.e[j].Elements::j)
			{
				//increment and copy the smaller one
				to_return.e[k].Elements::i=s2.e[j].Elements::i;
				to_return.e[k].Elements::j=s2.e[j].Elements::j;
				to_return.e[k].Elements::k=s2.e[j].Elements::k;
				std::cout<<"s2 num: "<<s2.e[j].Elements::k<<std::endl;
				j++;
			} else {
				to_return.e[k].Elements::i=s1.e[i].Elements::i;
				to_return.e[k].Elements::j=s1.e[i].Elements::j;
				to_return.e[k].Elements::k=s1.e[i].Elements::k;
				std::cout<<"s1 num: "<<s1.e[i].Elements::k<<std::endl;
				i++;
			}
		} else { //if rows are not equal
			if(s1.e[i].Elements::i>s2.e[j].Elements::i)
			{
				//increment and copy the smaller one
				to_return.e[k].Elements::i=s2.e[j].Elements::i;
				to_return.e[k].Elements::j=s2.e[j].Elements::j;
				to_return.e[k].Elements::k=s2.e[j].Elements::k;
				std::cout<<"s2 num: "<<s2.e[j].Elements::k<<std::endl;
				j++;
			} else {
				to_return.e[k].Elements::i=s1.e[i].Elements::i;
				to_return.e[k].Elements::j=s1.e[i].Elements::j;
				to_return.e[k].Elements::k=s1.e[i].Elements::k;
				std::cout<<"s1 num: "<<s1.e[i].Elements::k<<std::endl;
				i++;
			}
		}
		k++;
		to_return.num++;
	}

	while(i<=s1.num)
	{
		to_return.e[k].Elements::i=s1.e[i].Elements::i;
		to_return.e[k].Elements::j=s1.e[i].Elements::j;
		to_return.e[k].Elements::k=s1.e[i].Elements::k;
		to_return.num++;
		std::cout<<"s1 num: "<<s1.e[i].Elements::k<<std::endl;
		i++;
		k++;
	}
	while(j<=s2.num)
	{
		to_return.e[k].Elements::i=s1.e[j].Elements::i;
		to_return.e[k].Elements::j=s1.e[j].Elements::j;
		to_return.e[k].Elements::k=s1.e[j].Elements::k;
		std::cout<<"s2 num: "<<s2.e[j].Elements::k<<std::endl;
		j++;
		to_return.num++;
		k++;
	}
	std::cout<<"s1 num val: "<<s1.num<<std::endl;
	std::cout<<"s2 num val: "<<s2.num<<std::endl;
	std::cout<<"num val: "<<to_return.num<<std::endl;;
	return to_return;
}

void Sparse::create(Sparse *s)
{
	std::cout<<"Enter number of rows, columns, and non zero elements: ";
	std::cin>>s->m>>s->n>>s->num;
	s->e=new Elements[num];
	for(int p=0; p!=num; p++){
		std::cout<<"Please enter the row, column and value of the number\n";
		std::cin>>s->e[p].i>>s->e[p].j>>s->e[p].k;
	}
	std::cout<<"last element in s: "<<std::endl
		<<s->e[s->num-1].i<<" "
		<<s->e[s->num-1].j<<" "
		<<s->e[s->num-1].k<<" "<<std::endl;
}

void Sparse::display()
{
	for(int i=0; i!=m; i++){
		for(int j=0; j!=n; j++)
		{
			std::cout<<get(i,j)<<" ";
		}
		std::cout<<std::endl;
	}
}

int Sparse::get(int row, int col)
{
	for(int i=0; i!=num; i++)
	{
		if(e[i].Elements::i>row)
			return 0;
		else if(e[i].Elements::i==row && e[i].Elements::j>col)
			return 0;
		else if(e[i].Elements::i==row && e[i].Elements::j==col)
			return e[i].Elements::k;
		else 
			continue;
	}
//	std::cout<<"returning from default";
		return 0;
}

Sparse::~Sparse()
{
	delete e;
}

#endif
