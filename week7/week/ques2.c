#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX 1000

void swap(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void random_shuffle(int *arr){
	srand(time(NULL));
	int i,j,temp;
	for(i=MAX-1;i>0;i--){
		j = rand()%(i+1);
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

int partion(int *arr,int l,int h){
	int pivotIndex = l + rand()%(h-l+1);
	int pivot;
	int i = l - 1;
	int j;
	pivot = arr[pivotIndex];
	swap(&arr[pivotIndex], &arr[h]);
	for (j = l; j < h; j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[h]);
	return i + 1;
}

void quick_sort(int *arr,int l,int h){
	int j;
	if (l<h){
		j = partion(arr,l,h);
		quick_sort(arr,l,j-1);
		quick_sort(arr,j+1,h);
	}
}

int main(){
	int i;
	printf("\nRANDOM ELEMENT SELECTED AS PIVOT.\n\n");
	int*arr=(int*)malloc(sizeof(int)*MAX);
    	for(i=0;i<MAX;i++)
		arr[i] = i+1;
	random_shuffle(arr);
	quick_sort(arr,0,MAX-1);
	printf("\n");
	for(i=0;i<MAX;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
