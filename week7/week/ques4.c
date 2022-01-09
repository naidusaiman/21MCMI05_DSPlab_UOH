#include<stdio.h>
#include<stdlib.h>

int med(int,int);
int partition(int*,int,int);

void quickSort(int*a,int s,int e){
	int ind;
	if(s<e){
		ind=partition(a,s,e);
		quickSort(a,s,ind-1);
		quickSort(a,ind+1,e);
	}
}

int partition(int*a,int s,int e){
	int pivot=a[med(s,e)];
	int i=s-1,j,temp=0;
	for(j=s;j<e;j++){
		if(a[j]<=pivot){
			++i;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[e];
	a[e]=a[i+1];
	a[i+1]=temp;
	return (i+1);
}

int med(int s,int e){
	int m,me;
	if(s<e){
		m = s + (e-s)/2;
		me = (s+m+e)/3;
		printf("MEDIAN INDEX: %d.\n",me);
		me=e;
	}
	return me;
}

int main(){
	printf("MEDIAN OF first middle and last selected as pivot.\n");
	int n;
	printf("Size: ");
	scanf("%d",&n);
	int*a=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("BEFORE SORTING:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	quickSort(a,0,n-1);
	printf("\nAFTER SORTING:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
