#include<iostream>
#include<stack>

using namespace std;

#define TRUE 1
#define FLASE 0
#define max 50

typedef struct Graphnode{
    int vertex;
    struct Graphnode*link;
}Graphnode;

typedef struct GraphType{
    int n;
    Graphnode* adj[max];
}GraphType;

int visited[max];

void init(GraphType*g){
    g->n=0;
    for(int i=0;i<max;i++){
	for(int j=0;j<max;j++){
	    g->adj[j]=NULL;
	}
    }
}

void insert_vertex(GraphType*g,int v){
    if(((g->n)+1)>max){
	fprintf(stderr,"그래프:정점의 개수 초과");
	return;
    }
    g->n++;
}

void insert_edge(GraphType*g,int s,int e){
    Graphnode*node=(Graphnode*)malloc(sizeof(Graphnode));
    if(s>=g->n || e>=g->n){
	fprintf(stderr,"그래프: 정점 번호 오류");
	return;
    }
    node->vertex=e;
    node->link=g->adj[s];
    g->adj[s]=node;
}

void dfs_list(GraphType*g,int v){
    Graphnode*w;
    visited[v]=TRUE;
    printf("정점 %d ->",v);
    for(w=g->adj[v];w;w=w->link){
	if(!visited[w->vertex]){
	    dfs_list(g,w->vertex);
	}
    }
}

int main(int argc,char*argv[]){
    GraphType*g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++){
	insert_vertex(g,i);
    }
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    printf("깊이 우선 탐색\n");
    dfs_list(g,0);
    printf("\n");
    free(g);
    return 0;
}
