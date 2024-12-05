#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

template<class T>
class Circular
{
	public:
		class Node
		{
			public:
				T data{};
				Node * next;
		};
	private:
		Node * first;
		Node *last;
		int length{};
	public:
		Circular();
		void append(T);
		int get_length();
		void display();
};

template<class T>
Circular<T>::Circular()
{
	first=last=NULL;
	length=0;
}

template<class T>
int Circular<T>::get_length()
{
	return length;
}

template<class T>
void Circular<T>::append(T val)
{
	Circular<T>::Node *new_node= new Circular<T>::Node;
	new_node->data=val;
	if(first==0){
		new_node->next=new_node;
		first=last=new_node;
	} else {

		new_node->next=first;
		last->next=new_node;
		last=new_node;
	}

	length++;
}

template<class T>
void Circular<T>::display()
{
	Node *to_loop=first;
	if(get_length()==0)
		return;
	do{
		std::cout<<to_loop->data<<" ";
		to_loop=to_loop->next;
	} while(to_loop!=first);
}

#endif 
