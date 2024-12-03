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
		std::string InfixToPostfix(std::string);
		friend int presidence(char ch);
		int evalPostfix(std::string);
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

bool isOperand(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		return false;
	return true;
}

int presidence(char ch) 
{
	if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/')
		return 2;
	return 15;
}

std::string Stack::InfixToPostfix(std::string str) //for converting infix to postfix
{
	std::string postfix{};
	//loop through the string and check for presidence
	for(auto c:str)
	{
		if(isOperand(c)) {
			postfix+=c;
			continue;
		} else {
popin: 			//append in the stack
			if(isEmpty() || presidence(c)>presidence(char(head->data)))
			{
				append(int(c));
				continue;
			} else {
popout:				//popout until the stack is empty || presidence(c) is not smaller than presidence(head->data);
				postfix+=char(pop());
				if(!isEmpty() && !presidence(c)>presidence(char(head->data)))
					goto popout;
				else
					goto popin;

			}
		}
	}
popout2:
	if(!isEmpty())
		postfix+=char(pop());
	if(!isEmpty())
		goto popout2;
	return postfix;
}

int operate(int num1, int num2, char c)
{
	switch(c){
		case '+':
			return num1+num2;
		case '-':
			return num2-num1;
		case '*':
			return num1*num2;
		case '/':
			return num2/num1;
	}
	return 0;
}

int Stack::evalPostfix(std::string str)
{
	int result{};
	for(auto c:str) //loop through the string
	{
		if(isOperand(c)) {
			append(int(c)-int('0'));
			continue;
		} else {
			int num1=pop();
			int num2=pop();
			append(operate(num1, num2, c));
		}
	}
	return head->data;
}

#endif
