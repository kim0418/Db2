#include<iostream>
#include<stack>
#include<queue>
using namespace std;
static int sum;

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

node*Allocnewnode(int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* Make_tree(void){
    node*s=Allocnewnode(1);
    s->left=Allocnewnode(2);
    s->right=Allocnewnode(3);
    s->left->left=Allocnewnode(4);
    s->right->left=Allocnewnode(5);
    s->right->right=Allocnewnode(6);
    s->right->left->right=Allocnewnode(7);
    return s;
}

void pre_rec(node*root){
   stack<node*>s;
    while(s.empty()){
	s.push(root);
	if(root==NULL) return;
	cout << root->data << " ";
	pre_rec(root->left);
	s.pop();
	pre_rec(root->right);
	s.pop();
    }
}

void pre_iterative(node*root){
    stack<node*>s;
    while(1){
	cout << root->data << " ";
	if(root->right !=NULL){
	    s.push(root->right);
	}
	if(root->left==NULL){
	    if(s.empty()) break;
	    root=s.top();
	    s.pop();
	}
	else{
	    root=root->left;
	}
    }
}

void pre_iter(node*root){
   stack<node*>s;
    while(s.empty()){
	s.push(root);
	if(root==NULL) return;
	cout << root->data << " ";
	pre_iter(root->left);
	s.pop();
	pre_iter(root->right);
	s.pop();
    }
}

void pre_order_recursive(node*root){
    printf("[pre_recursive]");
    pre_rec(root);
    printf("\n");
}

void pre_order_iter(node*root){
    printf("[pre_iter]");
    pre_iter(root);
    printf("\n");
}

int get_sum(node*root){
   if(root==NULL) return 0;
   sum+=root->data;
   get_sum(root->left);
   get_sum(root->right);
   if(root->left==NULL && root->right==NULL) return sum;
   return sum;
}

void get_node_sum(node*root){
   printf("[sum] %d\n",get_sum(root));
}

void find_leafnodes(node*root){
    if(root==NULL) return;
    find_leafnodes(root->left);
    find_leafnodes(root->right);
    if(root->left==NULL && root->right==NULL){
	cout << root->data << " ";
    }
}

int main(void){
    node*root=Make_tree();
    pre_order_recursive(root);
    pre_order_iter(root);
    get_node_sum(root);
    find_leafnodes(root);
    //level_order(root);
    return 0;
}
