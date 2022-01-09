#include<stdio.h>
#include<stdlib.h>

void quicksort(int *array,int f,int l){
	int i,j,pivot,temp;
	if(f<l){
		pivot=f;
		i=f;
		j=l;
		while(i<j){
			while(array[i]<=array[pivot]&&i<l)
				i++;
			while(array[j]>array[pivot])
				j--;
			if(i<j){
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
		temp=array[pivot];
		array[pivot]=array[j];
		array[j]=temp;
		quicksort(array,f,j-1);
		quicksort(array,j+1,l);
	}
}
int main(){
	int i,size;
	printf("\nFIRST ELEMENT SELECTED AS PIVOT.\n\n");
	printf("Array Size: ");
	scanf("%d",&size);
	int*arr=(int*)malloc(sizeof(int)*size);
	printf("Enter %d elements: ",size);
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,size-1);
	printf("The Sorted Order is: ");
	for(i=0;i<size;i++)
		printf(" %d",arr[i]);
	printf("\n\n");
	return 0;
}
