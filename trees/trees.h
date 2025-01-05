#ifndef TREES_H
#define TREES_H
#include "treeStack.h"
#include "treeNode.h"

class Tree
{
	private:
		Node *head;
		int length;

	public:
		Tree();
		friend std::ostream & operator<<(std::ostream &, Stack &);
		int node_count();
		void preOrder();
		void in_order(Node*);
		Node * get_head();
		void post_order(Node*);
		void level_order(Stack);
		int node_count(Node*);
};

Tree::Tree()
{
	head=new Node;
	length=0;
	Stack st; //linkedlist for storing the nodes of the tree to store their left and right childs
	
	//prompt for nodes
	std::cout<<"Enter your first node: ";
	std::cin>>head->data;
	head->lchild=NULL;
	head->rchild=NULL;

	st.append(head);

	while(!st.isEmpty()) //loop until the queue is empty
	{
		Node* node=new Node;
		node=st.pop();

		//for left child
		bool hasLeft;
		std::cout<<"does "<<node->data<<" has left child? (0/1): ";
		std::cin>>hasLeft;
		if(hasLeft)
		{
			node->lchild=new Node;
			std::cout<<"Enter left child of "<<node->data<<": "; 
			std::cin>>node->lchild->data;
			st.append(node->lchild);
		}

		//for right child
		bool hasRight;
		std::cout<<"does "<<node->data<<" has right child? (0/1): ";
		std::cin>>hasRight;
		if(hasRight)
		{
			node->rchild=new Node;
			std::cout<<"Enter right child of "<<node->data<<": "; 
			std::cin>>node->rchild->data;
			st.append(node->rchild);
		}


	}
}

void Tree::preOrder()
{
	Node *to_loop=head;
	Stack st;
	st.append(to_loop);
	while(!st.isEmpty())
	{
		Node *new_node=st.pop();
		std::cout<<new_node->data<<" ";

		if(new_node->rchild)
			st.append(new_node->rchild);
		if(new_node->lchild)
			st.append(new_node->lchild);
	}
}

Node * Tree::get_head()
{
	return head;
}

void Tree::in_order(Node *to_loop)
{
	if(to_loop){
		in_order(to_loop->lchild);
		std::cout<<to_loop->data<<" ";
		in_order(to_loop->rchild);
	}
}

void Tree::post_order(Node *to_loop)
{
	if(to_loop){
		post_order(to_loop->lchild);
		post_order(to_loop->rchild);
		std::cout<<to_loop->data<<" ";
	}
}

void Tree::level_order(Stack st)
{
	Stack st2;
	while(!st.isEmpty()){
		Node *new_node=st.pop();
		std::cout<<new_node->data<<" ";
		if(new_node->rchild)
			st2.append(new_node->rchild);
		if(new_node->lchild)
			st2.append(new_node->lchild);
	}
	std::cout<<std::endl;
	if(!st2.isEmpty())
		level_order(st2);
}

int Tree::node_count(Node* node)
{
	int x{},y{};
	if(node)
	{
		x=node_count(node->lchild); //returns either 1 or 0 based upon whether the left child exists or not
		y=node_count(node->rchild); //returns either 1 or 0 based upon whether the right child exists or not
		return x+y+1;	// we added 1 to count for the current node and not just left or right
	} else
		return 0;
}

#endif
