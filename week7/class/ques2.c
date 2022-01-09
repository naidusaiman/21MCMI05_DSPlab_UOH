#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void merge(int*a,int s,int mid,int e){
	int n1=mid-s+1;
	int n2=e-mid;
	int*a1=(int*)malloc(sizeof(int)*(n1+1));
	int*a2=(int*)malloc(sizeof(int)*(n2+1));
	int i,j;
	for(i=0;i<n1;i++)
		a1[i]=a[s+i];
	for(j=0;j<n2;i++,j++)
		a2[j]=a[mid+j+1];	
	a1[n1]=123456;
	a2[n2]=123456;
	
	int k=0;
	i=0,j=0;	
	for(k=s;k<=e;k++){
		if(a1[i]<=a2[j]){
			a[k]=a1[i];
			++i;
		}else{
			a[k]=a2[j];
			++j;
		}
	}
	free(a1);
	free(a2);	
}		
void mergeSort(int*a,int s,int e){
	int mid;
	if(s<e){
		mid=floor((e+s)/2);
		//printf("\n\n\n\n%d\n\n\n\n",mid);
		mergeSort(a,s,mid);
		mergeSort(a,mid+1,e);
		merge(a,s,mid,e);
	}
}
int main(){
	int n;
	printf("SIZE: ");
		scanf("%d",&n);
	int*a=(int*)malloc(sizeof(int)*n);
	int i;
	printf("Enter Binary Data:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		if(a[i] == 0 || a[i] == 1){
		}else{
			printf("Enter data is not binary. EXITING.\n");
			return 0;
		}
	}
	printf("BEFORE SORTING:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	mergeSort(a,0,n-1);
	printf("\nAFTER SORTING:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
