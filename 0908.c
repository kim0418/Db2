#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
    struct node*prev;
}node;

void menu(){
    printf("1.Add_rear\n");
    printf("2.Add_frint\n");
    printf("3.delete_rear\n");
    printf("4.delete_frint\n");
    printf("5.delete_item\n");
    printf("6.ReversePreview_list\n");
    printf("7.now_list\n");
    printf("8.EXIT\n");
}

node* addnode(int data){
	node*curr=(node*)malloc(sizeof(node));
	curr->data=data;
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}

void add_rear(node**head,int data){
	if(*head==NULL){
		*head=addnode(data);
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				curr->next=addnode(data);
				curr->next->prev=curr;
				break;
			}
		}
	}
}

void add_front(node**head,int data){
	if(*head==NULL){
		*head=addnode(data);
	}
	else{
		node*newnode=addnode(data);
		newnode->next=*head;
		(*head)->prev=newnode;
		*head=newnode;
	}
}

void delete_rear(node**head){
	if(*head==NULL){
		printf("EMPTY\n");
	}
	else{
		node*a;
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				if(curr->prev==NULL){
					*head=NULL;
					printf("list is EMPTY\n");
					break;
				}
				else{
					a=curr->prev;
					free(curr);
					curr->next=NULL;
					break;
				}
			}
		}
	}
}

void delete_front(node**head){
	if(*head==NULL){
		printf("EMPTY\n");
	}
	else{
		node*curr=*head;
		if(curr->next==NULL){
			*head=NULL;
			printf("list is empty\n");		
		}
		else{
			curr=(*head)->next;
			free(*head);
			*head=curr;
			(*head)->prev=NULL;
		}
	}
}

void delete_item(node**head, int target){
	node*remove=NULL;
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(curr->data==target){
			remove=curr;
			break;
		}
	}
	if(remove->prev==NULL){
		remove=(*head)->next;
		free(*head);
		*head=remove;
		remove->prev=NULL;
	}
	else if(remove->next==NULL){
		remove->prev->next=remove->prev;
		free(remove);
	}
	else{
		remove->next->prev=remove->prev;
		remove->prev->next=remove->next;
		if(remove==NULL);
		else{free(remove);}
	}
}

void reverse(node**head){
	node*rev;
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(curr->next==NULL){
			rev=curr;
			break;
		}
	}
	for(node*reve=rev;reve!=NULL;reve=reve->prev){
		printf("%d->",reve->data);
	}
	printf("\n");
}

void preview(node**head){
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		printf("%d->",curr->data);
	}
	printf("\n");
}

void protocal(node**s){
    int num=0;
    int target=0;
    scanf("%d",&num);
    switch(num){
	case 1:
	    scanf("%d",&target);
	    add_rear(s,target);
	    break;
	case 2:
	    scanf("%d",&target);
	    add_front(s,target);
	    break;
	case 3:
	    delete_rear(s);
	    break;
	case 4:
	    delete_front(s);
	    break;
	case 5:
	    scanf("%d",&target);
	    delete_item(s,target);
	    break;
	case 6:
	    reverse(s);
	    break;
	case 7:
	    preview(s);
	    break;
	case 8:
	    printf("EXIT\n");
	    exit(1);
	default:
	    printf("system error\n");
	    exit(1);
    }
}

int main(int argc,char*argv[]){

    node*s=NULL;

    do{
	menu();
	protocal(&s);
	printf("\n");
    }while(1);

    return 0;

}
