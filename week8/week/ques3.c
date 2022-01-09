#include<stdio.h>
#include<stdlib.h>


void swap(int *a,int *b){
	int tmp = *a;
    	*a = *b;
    	*b = tmp;
}
  
void max_heapify(int arr[],int n,int i){
    	int max = i;
    	int leftChild = 2*i+1;
    	int rightChild = 2*i+2;
  	if(leftChild<n && arr[leftChild]<arr[max])
      		max = leftChild;
  	if(rightChild<n && arr[rightChild]<arr[max])
      		max = rightChild;
  	if(max!=i){
      		swap(&arr[i], &arr[max]);
            	max_heapify(arr, n, max);
    	}
}

void min_heapify(int arr[],int n,int i){
    	int max = i;
    	int leftChild = 2*i+1;
    	int rightChild = 2*i+2;
  	if(leftChild<n && arr[leftChild]>arr[max])
      		max = leftChild;
  	if(rightChild<n && arr[rightChild]>arr[max])
      		max = rightChild;
  	if(max!=i){
      		swap(&arr[i], &arr[max]);
            	min_heapify(arr, n, max);
    	}
}


void minheapSort(int arr[], int n) {
    	for(int i=n/2-1;i>=0;i--)
      		min_heapify(arr,n,i);
    	for(int i=n-1;i>=0;i--){
      		swap(&arr[0],&arr[i]);
  		min_heapify(arr,i,0);
    	}
}

void maxheapSort(int arr[], int n) {
    	for(int i=n/2-1;i>=0;i--)
      		max_heapify(arr,n,i);
    	for(int i=n-1;i>=0;i--){
      		swap(&arr[0],&arr[i]);
  		max_heapify(arr,i,0);
    	}
}

void maxbuildHeap(int *arr,int count){
	for(int i = count/2-1;i>=0;i--)
      		max_heapify(arr,count,i);
}

void minbuildHeap(int *arr,int count){
	for(int i = count/2-1;i>=0;i--)
      		min_heapify(arr,count,i);
}

void display(int arr[],int n){
	for(int i=0;i<n;++i)
      		printf("%d ",arr[i]);
    	printf("\n");
}


int main(){
	int size,choice,temp,i,count=0,ele,bh;
	printf("MAXIMUM SIZE OF LIST: ");
	scanf("%d",&size);
	int*arr=(int*)malloc(sizeof(int)*size);
	printf("\nPROGRAM WILL RUN FUNCTIONS ONLY AFTER ONCE BUILD HEAP IS USED.\n\n");
	do{
		printf("\n\tMENU\n\n");
		printf("1.BUILD HEAP\n2.INSERT\n3.DELETE\n4.SORT\n5.DISPLAY\n6.EXIT\n\n");
		printf("ENTER CHOICE: ");
		scanf("%d",&choice);
		if(choice == 1){
			printf("SIZE, must be less than maximum size of list: ");
			scanf("%d",&temp);
			if(temp<=size && count<=size){
				for(i=0;i<temp;i++){
					scanf("%d",arr+i);
				}
				count = count + temp;
			}else{
				printf("MEMORY OVERFLOW. PLS TRY AGAIN.\n");
				break;
			}
			printf("\n1. FOR BUILD HEAP USING MIN HEAPIFY.\n2. FOR BUILD HEAP USING MAX HEAPIFY.\n");
			scanf("%d",&bh);
			if(bh == 1){
				minbuildHeap(arr,count);
				printf("\nHEAP SUCCESSFULLY CREATED.\n");
			}else if(bh == 2){
				maxbuildHeap(arr,count);
				printf("\nHEAP SUCCESSFULLY CREATED.\n");
			}else
				printf("\nWrong choice.\n");			
		}else if(choice == 2){
			if(count<size){
				++count;
				printf("DATA: ");
				scanf("%d",&ele);
				arr[count-1]=ele;
				printf("\n1. FOR BUILD HEAP USING MIN HEAPIFY.\n2. FOR BUILD HEAP USING MAX HEAPIFY.\n");
				scanf("%d",&bh);
				if(bh == 1){
					minbuildHeap(arr,count);
					printf("\nHEAP SUCCESSFULLY CREATED.\n");
				}else if(bh == 2){
					maxbuildHeap(arr,count);
					printf("\nHEAP SUCCESSFULLY CREATED.\n");
				}else
					printf("\nWrong choice.\n");
			}else
				printf("\nSIZE FULL. DELETE FIRST TO INSERT MORE\n");
		}else if(choice == 3){
				printf("\n%d element deleted successfully.\n",arr[count-1]);
				--count;
		}else if(choice == 4){
				printf("\n1. MIN HEAPIFY HEAP SORT.\n2. MAX HEAPIFY HEAP SORT.\n");
				scanf("%d",&bh);
				if(bh == 1){
					minheapSort(arr,count);
					printf("\nSUCCESSFULLY CREATED.\n");
				}else if(bh == 2){
					maxheapSort(arr,count);
					printf("\nSUCCESSFULLY CREATED.\n");
				}else
					printf("\nWrong choice.\n");
		}else if(choice == 5){
			display(arr,count);
		}else if(choice == 6){
			return 0;
		}else{
			printf("\nWRONG CHOICE ENTERED. PLS TRY AGAIN.\n");
		}		
    	}while(1);
	return 0;  
}
