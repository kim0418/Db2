#include<iostream>
#include<stack>

using namespace std;

#define TRUE 1
#define FLASE 0
#define max 50

typedef struct GraphType{
    int n;
    int adj[max][max];
}GraphType;

int visited[max];

void init(GraphType*g){
    g->n=0;
    for(int i=0;i<max;i++){
	for(int j=0;j<max;j++){
	    g->adj[max][max]=0;
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
    if(s>=g->n || e>=g->n){
	fprintf(stderr,"그래프: 정점 번호 오류");
	return;
    }
    g->adj[s][e]=1;
    g->adj[e][s]=1;
}

void dfs(GraphType*g,int v){
    visited[v]=TRUE;
    printf("정덤 %d -> ",v);
    for(int w=0;w<g->n;w++){
	if(g->adj[v][w] && !visited[w]){
	    dfs(g,w);
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
    dfs(g,0);
    printf("\n");
    free(g);
    return 0;
}
