#include<iostream>
#include<stack>

using namespace std;


typedef struct node{
	int data;
	//struct node*up;
	struct node*left;
	struct node*right;
}node;

node*Allocnewnode(int data,node*left,node*right){
	node*newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=left;
	newnode->right=right;
	return newnode;
}
/*
void printTree(node*root){
	printf("%d ",root->data);
	if(root->left!=NULL) printTree(root->left);
	if(root->right!=NULL) printTree(root->right);
	printf("%d ",root->left->data);
	printf("%d ",root->right->data);
}*/

void printTree(node*root){
	if(root==NULL) return;
//	printf("%d ",root->data);
	printTree(root->left);
	printf("%d ",root->data);
	printTree(root->right);
//	printf("%d ",root->data);
}
/*
void printTreeRecursive(node*root){
	if(root==NULL) return;
	printf("%d ",root->data);
	printTree(root->left);
	printTree(root->right);
}*/

void printTreeIterative(node*root){

	stack<node*> s;
	while(s.empty()){
	    s.push(root);
	    if(root==NULL) return;
	    printTreeIterative(root->left);
	   // cout << root->data << " ";
	    s.pop();
	    printTreeIterative(root->right);
	    cout << root->data << " ";
	    s.pop();
	}

	// backtracking..
//	while(1){
	// print root...
	// move curr pointer to left..
	// move curr pointer to right..
//	}
}

int main(int argc,char*argv[]){

	node*root=Allocnewnode(2,NULL,NULL);
	root->left=Allocnewnode(1,NULL,NULL);
	root->right=Allocnewnode(3,NULL,NULL);
	root->left->left=Allocnewnode(4,NULL,NULL);
	root->left->right=Allocnewnode(5,NULL,NULL);
	// root->left->right=Allocnewnode(5,NULL,Allocnewnode(6,NULL,NULL));
	//root->left->right->right=Allocnewnode(6,NULL,NULL);
	printTreeIterative(root);
//	printTree(root);
//	printf("%d\n",root->left->right->data);

	return 0;
}
