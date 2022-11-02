#include<iostream>
#include<queue>

using namespace std;

#define TRUE 1
#define FALSE 0
#define max 50

typedef struct GraphType{
    int n;
    int adj[max][max];
}GraphType;
int visited[max];

void init(GraphType*g){
    g->n=0;
    for(int r=0;r<max;r++){
	for(int c=0;c<max;c++){
	    g->adj[r][c];
	}
    }
}

void insert_vertex(GraphType*g,int v){
    if(((g->n)+1)>max){
	fprintf(stderr,"그래프:정점번호오류");
	return;
    }
    g->n++;
}

void insert_edge(GraphType*g,int s, int e){
    if(s >= g->n || e >= g->n){
	fprintf(stderr,"그래프:정점번호오류");
	return;
    }
    g->adj[s][e]=1;
    g->adj[e][s]=1;
}

void bfs_list(GraphType*g,int v){
    
}

void bfs(GraphType*g,int v){
    queue<int>q;
    visited[v]=TRUE;

    printf("%d 방문 -> ",v);
    q.push(v);
    while(!q.empty()){
	v=q.front();
	q.pop();
	for(int w=0;w<g->n;w++){
	    if(g->adj[v][w] && !visited[w]){
		visited[w]=TRUE;
		printf("%d 방문 ->",w);
		q.push(w);
	    }
	}
    }
}

int main(int argc, char*argv[]){
    GraphType*g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<6;i++){
	insert_vertex(g,i);
    }
    insert_edge(g,0,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,0,4);
    insert_edge(g,4,5);
    insert_edge(g,1,5);
    printf("너비 우선 탐색\n");
    bfs(g,0);
    printf("\n");
    free(g);
    return 0;
}
