#ifndef TREESTACK_H
#define TREESTACK_H
#include "treeNode.h"

class Stack
{
	public:
		class qNode
		{
			public:
				Node * data;
				qNode *next;
		};
	private:
		qNode* head;
		int length;
	public:
		Stack();
		bool isEmpty();
		void append(Node*);
		Node* pop();
};

Stack::Stack()
{
	qNode *head=NULL;
	length=0;
}

bool Stack::isEmpty()
{
	return length==0;
}

void Stack::append(Node *data)
{
	Stack::qNode * new_node=new Stack::qNode;
	new_node->data=data;
	if(isEmpty()){
		new_node->next=NULL;
		head=new_node;
	} else {
		new_node->next=head;
		head=new_node;
	}
	length++;
}

Node* Stack::pop()
{
	if(isEmpty())
	{
		throw std::string("stack is empty");
	}
	Stack::qNode *to_delete=head;
	head=head->next;
	Node* data=to_delete->data;
	delete to_delete;
	length--;
	return data;
}

#endif
