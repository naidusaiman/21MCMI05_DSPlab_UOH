#include<stdio.h>
#include<stdlib.h>

int maximum(int*,int);
void RadixSort(int*,int);


int main(){
	int i, n;
    	printf("Element Count: ");
    	scanf("%d",&n);
    	int* a = (int*)malloc(sizeof(int)*n);
    	printf("Enter Elements: ");
    	for(i=0;i<n;i++){
        	scanf("%d",&a[i]);
    	}
    	RadixSort(a,n);
    	printf("Sorted Elements:\n");
    	for(i = 0; i < n; i++)
        	printf("%d  ",a[i]);
    	printf("\n");
    	return 0;
}

int maximum(int* a,int n){
	int large = a[0],i;
    	for(i=1;i<n;i++){
        	if(large<a[i])
            		large = a[i];
    	}
    	return large;
}

void RadixSort(int* a,int n){
	int bucket[n][n], bucket_count[n];
    	int i,j,k,remainder,NOP=0,divisor=1,large,pass;
	large = maximum(a,n);
    	printf("The large element %d\n",large);
  	while(large > 0){
        	NOP++;
        	large/=10;
    	}
 	for(pass=0;pass<NOP;pass++){
        	for(i=0;i<n;i++)
            		bucket_count[i] = 0;
        	for(i=0;i<n;i++){
            		remainder = (a[i]/divisor)%10;
            		bucket[remainder][bucket_count[remainder]] = a[i];
            		bucket_count[remainder] += 1;
        	}
 		i=0;
        	for(k=0;k<n;k++){
            		for(j=0;j<bucket_count[k];j++){
                		a[i] = bucket[k][j];
                		i++;
            		}
        	}
        	divisor *= 10;
 		for(i=0;i<n;i++)
            		printf("%d  ",a[i]);
        	printf("\n");
    	}
}
