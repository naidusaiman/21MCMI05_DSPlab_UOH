#include <stdio.h>
#include<stdlib.h>

void init(int**,int);
void createAdj(int**,int**,int,int);
void printAdj(int**,int);
void bfs(int*,int,int,int**);
void dfs(int*,int,int,int**);

int* q;

int main(){
	int ver,edg,i,j;
	printf("No. Of Vertices: ");
	scanf("%d",&ver);
	int ed;
	printf("No. Of Edges: ");
	scanf("%d",&edg);
	int** arr = (int**)malloc(sizeof(int*)*edg);
	for(i=0;i<edg;i++)
		arr[i] = (int*)malloc(sizeof(int)*2);
	for(i=0;i<edg;i++){
		printf("ENTER EDGE %d DETAILS.\n",i+1);
		for(j=0;j<2;j++){
			if(j == 0){
				printf("Enter Source Vertex Number: ");
				scanf("%d",&arr[i][j]);
			}else{
				printf("Enter Destination Vertex Number: ");
				scanf("%d",&arr[i][j]);
			}
		}
	}
	
	int** Adj = (int**)malloc(sizeof(int*)*(ver+1));
	for(i=0;i<ver+1;i++)
		Adj[i] = (int*)malloc(sizeof(int)*(ver+1)); 

    	createAdj(Adj,arr,ver,edg);
    	printAdj(Adj,ver);
  	
  	int* visited = (int*)malloc(sizeof(int)*(ver+1));
  	int* reach = (int*)malloc(sizeof(int)*(ver+1));
    	int v = arr[0][0];
    	q = (int*)malloc(sizeof(int)*(ver+1));
    	
	
	int choice = 1;
	while(choice != 3){
		printf("\n\n1. BFS TRAVERAL\n2.DFS TRAVERSAL\n3. EXIT\n\n");
		scanf("%d",&choice);
		if(choice == 1){
    			printf("\n\nBFS FUNCTION RUNNING...\n\n");
    			for(i=1;i<=ver;i++){
				q[i]=0;
				visited[i]=0;
			}
    			bfs(visited,v,ver,Adj);
			printf("\nREACHABLE NODES:\n");
			for(i=1;i<=ver;i++)
	  			if(visited[i])
	   				printf("%d ",i); 
	   			else
	   				printf("\n BFS TRAVERSAL NOT POSSIBLE\n");
	   	}else if(choice == 2){
	   		printf("\n\nDFS FUNCTION RUNNING...\n\n");
	   		for(i=1;i<=ver;i++){
				reach[i]=0;
			}
	   		printf("%d ",v);
			dfs(reach,v,ver,Adj);
		}else if(choice == 3)
			return 0;
		else
			printf("Choice Not Available.\n\n");
	}
    	return 0;
}

void init(int** Adj,int N){
	int i,j;
	for(i=0;i<N+1;i++){
        	for(j=0;j<N+1;j++){
            		Adj[i][j] = 0;
        	}
    	}
}

void createAdj(int** Adj,int** arr,int N,int M){
	init(Adj,N);
	int i,j,x,y;
    	for(i=0;i<M;i++){
        	x = arr[i][0];
        	y = arr[i][1];
        	Adj[x][y] = 1;
        	Adj[y][x] = 1;
    	}
}

void printAdj(int** Adj,int N){
	printf("\n\nADJACENCY MATRIX OF GIVEN INPUT\n\n");
	int i,j;
    	for(i=1;i<N+1;i++){
        	for(j=1;j<N+1;j++)
            		printf("%d ",Adj[i][j]);
        	printf("\n");
    	}
}

void bfs(int* visited,int v,int n,int** a){	
	int i;
	static int f = 0,r = -1;	
	for(i=1;i<=n;i++)
		if(a[v][i] && !visited[i])
	   		q[++r]=i;
	if(f<=r){
		visited[q[f]]=1;
		bfs(visited,q[f++],n,a);
	}
}

void dfs(int* reach,int v,int n,int** a){
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
		if(a[v][i] && !reach[i]){
			printf("%d ",i);
			dfs(reach,i,n,a);
	}
}
