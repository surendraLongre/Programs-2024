#include<bits/stdc++.h>

class Node
{
	public:
		char data;
		Node *next=nullptr;
};

class Stack:public Node
{
	Node *head=new Node;
	Node *tail=new Node;
	public:
		Stack();
		void push_back(char);
		void print();
		void pop();
		bool empty();
		char get_last();
};

Stack::Stack(){
	head=NULL;
	tail=NULL;
}

void Stack::push_back(char num){
	Node *to_join=new Node;
	to_join->data=num;
	to_join->next=NULL;
	if(head==NULL){
//		std::cout<<"empty";
		head=tail=to_join;
	}
	else{
//		std::cout<<"not empty";
		tail->next=to_join;
		tail=to_join;
	}
	to_join=NULL;
	delete to_join;
}

void Stack::print(){
	Node *to_loop=head;
	while(to_loop!=NULL){
		std::cout<<to_loop->data<<" ";
		to_loop=to_loop->next;
	}
}

void Stack::pop(){
	if(tail==NULL){
		std::cout<<"nothing to pop";
		return;
	}

	Node * to_loop=head;
	if(head==tail){
		head=tail=NULL;
		return;
	}
	while(to_loop->next!=tail){
		to_loop=to_loop->next;
	}

	to_loop->next=NULL;
	tail=to_loop;
	
}

bool Stack::empty(){
	if(head==NULL) return true;
	return false;
}

char Stack::get_last(){
	return tail->data;
}

int main()
{
	Stack st1;
	st1.push_back('(');
	st1.pop();
	st1.push_back('{');
	std::cout<<st1.get_last();
	st1.push_back('p');
	std::cout<<st1.get_last();
}
