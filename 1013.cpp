#include<iostream>
#include<queue>
#include<cmath>

static int widthcount;
static int num;

using namespace std;

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

node* make_linked_tree(){
	node*s=Allocnewnode(1);
	s->left=Allocnewnode(2);
	s->right=Allocnewnode(3);
	s->left->left=Allocnewnode(4);
//	s->left->right=Allocnewnode(5);
	s->right->left=Allocnewnode(6);
	s->right->right=Allocnewnode(7);
	s->right->left->right=Allocnewnode(8);
	return s;
}

int height(node*root){
    if(root==NULL) return 0;
    else{
	int left_hight=height(root->left);
	int right_hight=height(root->right);
	return (left_hight>right_hight) ? (left_hight+1) : (right_hight+1);
    }
}

int getwidth(node*root,int level){
    if(root==NULL) return 0;
    if(level==1) return 1;
    else if(level>1){
	return (getwidth(root->left,level-1)+getwidth(root->right,level-1));
    }
    return 0;
}

int level(node*root){
    int maxwidth=0;
    int width=0;
    int h=height(root);
    for(int i=1;i<=h;i++){
	width=getwidth(root,i);
	if(width>maxwidth){
	    maxwidth=width;
	}
    }
    return maxwidth;
}

int get_max_width(node*root){
    return level(root);
}

void recurse(node*root){
	if(root==NULL) return ;
	else{
		printf("%d ",root->data);
		recurse(root->left);
		recurse(root->right);
	}
}

void pre_order(node*root){
	printf("[Pre order]");
	recurse(root);
	printf("\n");
}

void level_view(node*root){
    queue<node*>q;
    int count=0;
    int lev=0;
    if(root==NULL){
	return ;
    }
    q.push(root);
    while(!q.empty()){
	if(count==0){
	    printf("%d:",lev+1);
	    lev++;
	}
	else if(count==pow(2,lev)-1 && count!=0){
	    printf("\n");
	    printf("%d:",lev+1);
	    lev++;
	}
	root=q.front();
	q.pop();
	count=root->data;
	printf("%d",root->data);
	if(root->left!=NULL){
	    q.push(root->left);
	}
	if (root->right!=NULL){
	    q.push(root->right);
	}
    }
}

void print_leveled_view(node*root){
	printf("[Leveled view]\n");
	level_view(root);
	printf("\n");
}

int main(int argc,char*argv[]){
	node*root=make_linked_tree();
	pre_order(root);
	
	int maxWidth=get_max_width(root);
	printf("[Max Width]=%d\n",maxWidth);
	
	print_leveled_view(root);
	//print_leveled_view2(root);
	return 0;
}
