#ifndef STACK_H
#define STACK_H

class Stack
{
	public:
		class Node
		{
			public:
				int data;
				Node *next;
		};
	private:
		Node* head;
		int length;
	public:
		Stack();
		bool isEmpty();
		void append(int);
		void display();
		int pop();
		bool isMatching(std::string); //for the parenthesis matching
		bool complexMatching(std::string);
};

Stack::Stack()
{
	Node *head=NULL;
	length=0;
}

bool Stack::isEmpty()
{
	return length==0;
}

void Stack::append(int data)
{
	Stack::Node * new_node=new Stack::Node;
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

void Stack::display()
{
	Stack::Node * to_loop=head;
	while(to_loop!=0){
		std::cout<<to_loop->data<<" ";
		to_loop=to_loop->next;
	}
}

int Stack::pop()
{
	if(isEmpty())
	{
		throw std::string("stack is empty");
	}
	Stack::Node *to_delete=head;
	head=head->next;
	int data=to_delete->data;
	delete to_delete;
	length--;
	return data;
}

bool Stack::isMatching(std::string str) //parenthesis matching only if it's '(' or ')'
{
	for(auto c:str)
	{
		if(c=='(')
			append(int(c));
		else if(c==')') {
			if(isEmpty() || pop()!=int('('))
				return false;
		}
	}
	return isEmpty();
}

bool Stack::complexMatching(std::string str) //parenthesis matching only if it's '(' or ')'
{
	for(auto c:str)
	{
		if(c=='(' || c=='{' || c=='[')
			append(int(c));
		else if(int(c)==41 || int(c)==93 || int(c)==125) {
			int to_cmp=int(c)==41?40:int(c)-2;
			if(isEmpty() || pop()!=to_cmp)
				return false;
		}
	}
	return isEmpty();
}

#endif
