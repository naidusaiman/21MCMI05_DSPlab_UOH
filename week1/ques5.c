#include <stdio.h>
#include <limits.h>
  
int min(int x, int y) {
    return (x < y) ? x : y;
}
  
int find(int arr[], int n, int k){
	int ws = 0;
 	int len = INT_MAX;
 	int left = 0;
 	for(int right=0;right<n;right++){
	        ws+= arr[right];
 		while(ws>k && left<=right){
     			len = min(len,right-left+1);
            		ws-= arr[left];
            		left++;
        	}	
    	}
    	if(len==INT_MAX)
        	return 0;
    	return len;
}

int main(){
	int n;
	printf("Array Length: ");
		scanf("%d",&n);
	int arr[n];
	int i,j,sum=0;
	printf("Enter Array Elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int k;
	printf("Enter Value from which sub-array needs to be greater: ");
	scanf("%d",&k);
    	int len = find(arr, n, k);
    	int r; 
    	if (len != INT_MAX) {
        	printf("The smallest subarray length is %d\n", len);
        	for(i=0;i<n-len;i++){
        		sum = 0;
        		for(j=i;j<len+i;j++){
        			//arr1[j]=arr[j];
        			sum+=arr[j];
        		}
        		if(sum>=k){
        			printf("{ ");
        			for(r=i;r<len+i;r++)
        				printf("%d ", arr[r]+len);
        			printf("}\n");
        			return 0;
        		}
        	}
        			
    	}
    	else{
        	printf("No subarray exists");
    	}
	return 0;
}

