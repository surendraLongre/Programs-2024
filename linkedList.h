#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkedList
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
		LinkedList();
		template<typename U>
			friend std::ostream & operator<<(std::ostream &, LinkedList<U> &);
		void append(T);
		int get_length();
		void insert(T , int); //value, index
		T delete_at_ind(int);
		void displayCircular();
		void appendCircular(T);
};

template<typename T>
void LinkedList<T>::displayCircular()
{
	typename LinkedList<T>::Node to_loop=first;
	if(get_length()==0)
		return;
	do{
		std::cout<<to_loop.data<<" ";
		to_loop=to_loop->next;
	} while(to_loop!=first);
}

template<class T>
int LinkedList<T>::get_length()
{
	return length;
}

template<class T>
LinkedList<T>::LinkedList()
{
	first=NULL;
	last=first;
	length=0;
}

template<typename U>
std::ostream & operator<<(std::ostream &ost, LinkedList<U> &list)
{
	typename LinkedList<U>::Node * to_loop=new typename LinkedList<U>::Node;
	to_loop=list.first;
	while(to_loop!=0)
	{
		ost<<to_loop->data<<" ";
		to_loop=to_loop->next;
	}
	delete to_loop;
	return ost;
}

template<class T>
void LinkedList<T>::append(T val)
{
	Node *new_node=new Node;
	new_node->data=val;
	new_node->next=NULL;
	if(first==0)
	{
		first=new_node;
		last=first;
	}

	else{
		last->next=new_node;
		last=last->next;
	}
	length++;
}

template<class T>
void LinkedList<T>::appendCircular(T val)
{
	Node *new_node=new Node;
	new_node->data=val;
	new_node->next=first;
	if(first==0)
	{
		first=new_node;
		new_node->next=first;
		last=first;
	}

	else{
		last->next=new_node;
		last=last->next;
	}
	length++;
}

template<typename T>
void LinkedList<T>::insert(T val, int ind)
{
	if(ind<0 || ind>get_length())
		throw std::string("index out of range");
	typename LinkedList<T>::Node *new_node=new typename LinkedList<T>::Node;
	new_node->data=val;

	if(ind==0){
		new_node->next=first;
		first=new_node;
		if(get_length()==0) //if no element exist in the list
			last=first;
	} else {
		typename LinkedList<T>::Node *to_loop=first;
		while(ind!=1)
		{
			to_loop=to_loop->next;
			ind--;
		}

		new_node->next=to_loop->next;
		to_loop->next=new_node;
		if(ind==get_length()) //inserting at last
			last=new_node;
	}
	length++;
}

template <typename T>
T LinkedList<T>::delete_at_ind(int ind)
{
	if(ind<0 || ind>get_length()-1)
		throw std::string("invalid index");
	typename LinkedList<T>::Node *to_delete;
	if(ind==0){
		to_delete=first;
		first=first->next;
		delete to_delete;
	} else {
		to_delete=first;
		typename LinkedList<T>::Node *to_loop=first;
		int i=ind;
		while(i!=1){
			to_loop=to_loop->next;
			i--;
		}

		to_delete=to_loop->next; //delete the next element

		if(ind==get_length()-1){
			to_loop->next=NULL;
			last=to_loop;
		} else {
			to_loop->next=to_loop->next->next;
		}
	}
	T to_return=to_delete->data;
//	to_delete=NULL;
	//delete to_delete;
	length--;
	return to_return;
}

#endif
