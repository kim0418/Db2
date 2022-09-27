#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

void printTree(node*head){
    if(head==NULL) return;
    //printf("%d ",head->data);
    printTree(head->left);
    //printf("%d ",head->data);
    printTree(head->right);
    printf("%d ",head->data);
}

node*Allocroot(int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insert(node**root,int data){
	if(*root==NULL){
		*root=Allocroot(data);
	}
	else if(*root!=NULL){
		if( ((*root)->data) > data){
			insert(&(*root)->left,data);
		}
		else{
			insert(&(*root)->right,data);
		}
	}
}

int main(int argc, char*argv[]){
   
    node*root=Allocroot(10);
    insert(&root,5);
    insert(&root,20);
    insert(&root,1);
    insert(&root,6);
    insert(&root,15);
    insert(&root,30);
    printTree(root);
    printf("\n");
    return 0;
}




/*
node{
	int value;
	node*edge[5];
}
*/
