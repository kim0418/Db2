#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<vector>

#define max 100
#define INF 99999

#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct Graphtype{
    int n;
    int weight[max][max];
}Graphtype;

vector<int> arr[max];

void init(Graphtype*g){
	g->n=0;
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			if(i==j){
				g->weight[i][j]=0;
			}
			else{
				g->weight[i][j]=INF;
			}
		}
	}
	
}

void insert_vertex(Graphtype*g,int v){
	if((g->n)+1>max){
		fprintf(stderr,"error");
		return;
	}
	g->n++;
}

void insert_edge(Graphtype*g,int s,int e,int w){
	if(s > g->n| e >= g->n){
		fprintf(stderr,"error");
		return ;
	}
	g->weight[s][e]=w;
	g->weight[e][s]=w;
}

int GetMinDistIdx(Graphtype*g,int visited[max],int distance[max]){
	int foundIdx=-1;
	int minvalue=INT_MAX;
	for(int i=0;i<g->n;i++){
		if(visited[i]==TRUE) continue;
		if(minvalue>distance[i]){
			minvalue=distance[i];
			foundIdx=i;
			
		}
	}
	return foundIdx;
}

void updateDistance(Graphtype*g,int u,int distance[max]){
	for(int i=0;i<g->n;i++){
		if(distance[i]>distance[u]+g->weight[u][i]){
			distance[i]=distance[u]+g->weight[u][i];
			arr[i]=arr[u];
		}
	}
}

void short_path(Graphtype*g,int s){
	int distance[max]={INT_MAX,};
	int visited[max]={FALSE,};

	for(int i=0;i<g->n;i++){
		distance[i]=g->weight[s][i];
		arr[i].push_back(s);
	}
	for(int i=0;i<g->n;i++){
		int u=GetMinDistIdx(g,visited,distance);
		visited[u]=TRUE;
		arr[u].push_back(u);
		updateDistance(g,u,distance);
	}
	for(int i=0;i<g->n;i++){
	    if(i==s) continue;
	    printf("PATH %d -> %d",s,i);
	    for(int j=0;j<arr[i].size();j++){
		printf(" %d",arr[i][j]);
	    }
	    printf("(%d)",distance[i]);
	    printf("\n");
	}
}

int main(void){

	Graphtype*g=(Graphtype*)malloc(sizeof(Graphtype));
	init(g);
	for(int i=0;i<7;i++){
		insert_vertex(g,i);
	}
	insert_edge(g,0,1,7);
	insert_edge(g,0,4,3);
	insert_edge(g,0,5,10);
	insert_edge(g,1,2,4);
	insert_edge(g,1,3,10);
	insert_edge(g,1,4,2);
	insert_edge(g,1,5,6);
	insert_edge(g,2,3,2);
	insert_edge(g,3,4,11);
	insert_edge(g,3,5,9);
	insert_edge(g,3,6,4);
	insert_edge(g,4,6,5);

	short_path(g,0);
	return 0;
}
