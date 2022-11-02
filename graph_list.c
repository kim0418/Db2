#include<stdio.h>
#include<stdlib.h>

#define max_vertices 50

//using namespace std;

typedef struct Graphnode{
    int vertex;
    struct Graphnode* link;
}Graphnode;

typedef struct GraphType{
    int n;
    Graphnode* adj[max_vertices];
}GraphType;

void init(GraphType*s){
    s->n=0;
    for(int i=0;i<max_vertices;i++){
    	s->adj[i]=NULL;
    }
}

void insert_vertex(GraphType*s,int v){
    if(((s->n)+1)>max_vertices){
	fprintf(stderr,"그래프: 정점의 개수초과");
	return;
    }
    s->n++;
}

void insert_edge(GraphType*s,int u,int v){
    Graphnode*node=(Graphnode*)malloc(sizeof(Graphnode));
    if(u >=s->n || v>=s->n){
    	fprintf(stderr,"그래프: 장점 번호 오류");
    	return;
    }
    node->vertex=v;
    node->link = s->adj[u];
    s->adj[u] = node;
}

void print_adj(GraphType*s){
    for(int i=0;i<s->n;i++){
    	Graphnode*p=s->adj[i];
    	printf("정점 %d의 인접 리스트",i);
    	while(p!=NULL){
    		printf("-> %d",p->vertex);
    		p=p->link;
    	}
    	printf("\n");
    }
}

void main(int argc,char*argv[]){

    GraphType*s=(GraphType*)malloc(sizeof(GraphType));
    init(s);

    for(int i=0;i<4;i++){
	insert_vertex(s,i);
    }

    insert_edge(s,0,1);
    insert_edge(s,1,0);
    insert_edge(s,0,2);
    insert_edge(s,2,0);
    insert_edge(s,0,3);
    insert_edge(s,3,0);
    insert_edge(s,1,2);
    insert_edge(s,2,1);
    insert_edge(s,2,3);
    insert_edge(s,3,2);
    print_adj(s);

    free(s);

}



