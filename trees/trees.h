#ifndef TREES_H
#define TREES_H
#include "treeStack.h"
#include "treeNode.h"

class Tree
{
	protected:
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

class BST:public Tree
{
	public:
		bool search(int);
		void insert(int);
};

class AVL:public BST
{
	public:

		void insert(int);
		bool is_imbalanced();
		int height(Node *);
		int balance_factor(Node *);
		void ll_rotation(Node *);
		void balance();
		void rr_rotation(Node *);
		void lr_rotation(Node *);
		void rl_rotation(Node *);
		~AVL();
};

bool AVL::is_imbalanced()
{
	Node *new_node=get_head();
	return std::abs(height(new_node->rchild)-height(new_node->lchild))>1?true:false;
}

int AVL::height(Node *p)
{
	if(p==0)
		return 0;
	return std::max(height(p->lchild),height(p->rchild))+1;
}

int AVL::balance_factor(Node *p)
{
	return height(p->lchild)-height(p->rchild);
}

void AVL::balance()
{
	std::cout<<"balancing: ";
	Node *new_node=get_head();
	int bf_head=balance_factor(new_node);
	if(bf_head>0)
	{
		if(balance_factor(new_node->lchild)>0)
			ll_rotation(new_node);
		else
			lr_rotation(new_node);
	} else {
		if(balance_factor(new_node->rchild)<0)
			rr_rotation(new_node);
		else
			rl_rotation(new_node);
	}
}


void AVL::ll_rotation(Node *p)
{
	std::cout<<"LL rotation"<<std::endl;

	head=p->lchild;
	Node *node=p->lchild->rchild; //store the node of left child of right child of root
	p->lchild->rchild=p;
	p->lchild=node; //reassign the node to the root's left
}

void AVL::lr_rotation(Node *p)
{
	std::cout<<"LR rotation"<<std::endl;

	head=p->lchild->rchild;
	Node *node=p;	//store the root node;
	Node *plr_lchild=head->lchild;
	Node *plr_rchild=head->rchild;

	head->lchild=p->lchild;
	head->rchild=node;
	node->lchild=plr_rchild;
	head->lchild->rchild=plr_lchild;
}

void AVL::rr_rotation(Node *p)
{
	std::cout<<"RR rotation"<<std::endl;

	head=p->rchild;
	Node *node=p->rchild->lchild; //store the node of left child of right child of root
	p->rchild->lchild=p;
	p->rchild=node; //reassign the node to the root's left
}

void AVL::rl_rotation(Node *p)
{
	std::cout<<"RL rotation";

	head=p->rchild->lchild;
	Node *node=p;	//store the root node;
	Node *plr_lchild=head->lchild;
	Node *plr_rchild=head->rchild;

	head->rchild=p->rchild;
	head->lchild=node;
	node->rchild=plr_lchild;
	head->rchild->lchild=plr_rchild;
}

AVL::~AVL()
{
	if(is_imbalanced())
	{
		balance();
	}
}

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

bool BST::search(int num)
{
	Node *to_loop=get_head();
	while(to_loop)
	{
		if(num==to_loop->data)
			return true;
		else if(num<to_loop->data)
			to_loop=to_loop->lchild;
		else
			to_loop=to_loop->rchild;
	}
	return false;
}

void BST::insert(int num) //this function also works perfectly fine if the preorder is given to us
			  //it generates accurately
{
	if(!search(num))
	{
		Node *new_node=new Node;
		new_node->data=num;

		//loop until the to_loop's pointer is null and insert it there
		Node *to_loop=get_head();
		Node *prev_node=new Node;
		while(to_loop)
		{
			if(to_loop->lchild==0 && num<to_loop->data){ //new number must be smaller than data of to_loop because otherwise it won't be a sorted binary tree
				to_loop->lchild=new_node;
				break;
			} else if(to_loop->rchild==0 && num>to_loop->data) { //new number must be greater than data of to_loop because otherwise it won't be a sorted binary tree
				to_loop->rchild=new_node;
				break;
			}
			else if(num<to_loop->data)
				to_loop=to_loop->lchild;
			else
				to_loop=to_loop->rchild;
		}
	} else
		std::cout<<"value already present";
}

void AVL::insert(int num) //this function also works perfectly fine if the preorder is given to us
			  //it generates accurately
{
	if(!search(num))
	{
		Node *new_node=new Node;
		new_node->data=num;

		//loop until the to_loop's pointer is null and insert it there
		Node *to_loop=get_head();
		Node *prev_node=new Node;
		while(to_loop)
		{
			if(to_loop->lchild==0 && num<to_loop->data){ //new number must be smaller than data of to_loop because otherwise it won't be a sorted binary tree
				to_loop->lchild=new_node;
				break;
			} else if(to_loop->rchild==0 && num>to_loop->data) { //new number must be greater than data of to_loop because otherwise it won't be a sorted binary tree
				to_loop->rchild=new_node;
				break;
			}
			else if(num<to_loop->data)
				to_loop=to_loop->lchild;
			else
				to_loop=to_loop->rchild;
		}
		if(is_imbalanced())
			balance();
	} else
		std::cout<<"value already present";
}
#endif
