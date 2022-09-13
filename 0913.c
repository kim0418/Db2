#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

void printTree(node*root){
	printf("%d ",root->data);
	if(root->left!=NULL) printfTree(root->left);
	if(root->right!=NULL) printfTree(root->right);
	printf("%d ",root->left->data);
	printf("%d ",root->right->data);
}

void printTree(node*root){
	if(root==NULL) return;
	printf("%d ",root->data);
	printTree(root->left);
	printTree(toor->right);
}

void printTreeRecursive(node*root){
	if(root==NULL) return;
	printf("%d ",root->data);
	printTree(root->left);
	printTree(toor->right);
}

void printTreeIterative(node*root){

	stack<node*> s;	
	// backtracking..
	while(1){
	// print root...
	// move curr pointer to left..
	// move curr pointer to right..
	}
}

int main(int argc,char*argv[]){

	node*root=Allocnewnode(2,NULL,NULL);
	root->left=Allocnewnode(1,NULL,NULL);
	root->right=Allocnewnode(3,NULL,NULL);
	root->left->left=Allocnewnode(4,NULL,NULL);
	root->left->right=Allocnewnode(5,NULL,NULL);
	// root->left->right=Allocnewnode(5,NULL,Allocnewnode(6,NULL,NULL));
	//root->left->right->right=Allocnewnode(6,NULL,NULL);
	
	//printf("%d\n",root->left->right->data);

	return 0;
}




/*
node* addnode(int data){
	node*newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void add_right(node*head,int data){
	for(node*curr=head;curr!=NULL;curr=curr->right){
		if(curr->right==NULL){
			node*newnode=addnode(data);
			curr->right=newnode;
			//curr->right->left=curr;
			break;
		}
	}
}

void add_left(node*head,int data){
	for(node*curr=head;curr!=NULL;curr=curr->left){
		if(curr->left==NULL){
			node*newnode=addnode(data);
			curr->left=newnode;
			//curr->left->right=curr;
			break;
		}
	}
}

int main(int argc,char*argv[]){

	node*root=NULL;
	root=addnode(2);
	add_right(root,3);
	add_left(root,1);

	return 0;
}*/





/*
typedef struct node{
	int data;
	struct node*left;
	struct node*middle;
	struct node*right;
}node;


noad*Allocnode(int data,node*left,node*middle,node*right){
	node*newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=left;
	newnode->right=right;
	newnode->middle=middle;
	return newnode;
}

int main(int argc,char*argv[]){

	node*root=Allocnode(1,Allocnode(2,Allocnode(5,NULL,NULL,NULL),NULL,Allocnode(6,NULL,NULL,NULL)),Allocnode(3,NULL,NULL,NULL),Allocnode(4,NULL,NULL.NULL));

	return 0;
}
*/

