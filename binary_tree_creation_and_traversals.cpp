#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int data;
};

Node *root=NULL;

Node *createNode(int d)
{
	Node *tmp=new Node;
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->data=d;
	return tmp;
}


createTree()
{
	queue<Node *> q;
	if(root==NULL)
	{
		cout<<"Enter root node value"<<endl;
		int val;
		cin>>val;
		root=createNode(val);
		q.push(root);
	}
	
		while(!q.empty())
		{
			
			Node *tmp=q.front();
			q.pop();
			cout<<"Enter left child of "<<tmp->data<<endl;
			int lval;
			cin>>lval;
			if(lval!=-1)
			{
				Node *t=createNode(lval);
				tmp->left=t;
				q.push(t);
			}
			cout<<"Enter right child of "<<tmp->data<<endl;
			int rval;
			cin>>rval;
			if(rval!=-1)
			{
				Node *t=createNode(rval);
				tmp->right=t;
				q.push(t);
			}
		
	}
}

void preorder(Node *root)
{
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node *root)
{
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node *root)
{
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void levelorder()
{
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *tmp=q.front();
		q.pop();
		cout<<tmp->data<<" ";
		if(tmp->left)
		{
			q.push(tmp->left);
		}
		if(tmp->right)
		{
			q.push(tmp->right);
		}
	}
}


int main()
{	
	cout<<"Please Enter -1, if Node doesn't contain Left child or Right child."<<endl<<endl;
    createTree();
    cout<<endl<<"Preorder Traversal"<<endl;
    preorder(root);
    cout<<endl<<endl<<"Inorder Traversal"<<endl;
    inorder(root);
    cout<<endl<<endl<<"Postorder Traversal"<<endl;
    postorder(root);
    cout<<endl<<endl<<"Levelorder Traversal"<<endl;
    levelorder();


	return 0;
}

