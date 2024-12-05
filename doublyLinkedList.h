#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>

class DoublyLinkedList
{
	public:
		class Node
		{
			public:
				Node *prev;
				T data;
				Node *next;
		};
	private:
		Node * head;
		Node *tail;
		int length{};
	public:
		DoublyLinkedList();
		void append(T);
		int get_length();
		void display();
		void reverseDisplay();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head=NULL;
	tail=NULL;
	int length=0;
}

template<class T>
void DoublyLinkedList<T>::display()
{
	Node *to_loop=head;
	while(to_loop!=0){
		std::cout<<to_loop->data<<" ";
		to_loop=to_loop->next;
	}
	to_loop=nullptr;
	delete to_loop;
}

template<class T>
void DoublyLinkedList<T>::reverseDisplay()
{
	Node *to_loop=tail;
	while(to_loop!=0){
		std::cout<<to_loop->data<<" ";
		to_loop=to_loop->prev;
	}
	to_loop=nullptr;
	delete to_loop;
}

template<class T>
void DoublyLinkedList<T>::append(T data)
{
	DoublyLinkedList<T>::Node * new_node=new DoublyLinkedList<T>::Node;
	new_node->data=data;
	new_node->next=NULL;
	if(head==0){
		new_node->prev=NULL;
		head=new_node;
		tail=new_node;
	} else {
		new_node->prev=tail;
		tail->next=new_node;
		tail=new_node;
	}
	length++;
}

template<class T>
int DoublyLinkedList<T>::get_length()
{
	return length;
}

#endif

