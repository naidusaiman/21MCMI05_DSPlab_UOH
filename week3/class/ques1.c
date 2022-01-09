#include<stdlib.h>
#include <stdio.h>

int count = 0;

struct node{
        int info;
        struct node *next;
};

struct node *start=NULL;

void conv(int*arr){
	int i = 0;
        struct node *ptr;
        if(start==NULL){
                printf("List is empty\n");
                return;
        }else{
                ptr=start;
                while(ptr!=NULL){
                	arr[i++]=ptr->info;
                        ptr=ptr->next ;
                }
        }
}

void display(){
        struct node *ptr;
        if(start==NULL){
                printf("List is empty\n");
                return;
        }else{
                ptr=start;
                printf("The List elements are: \n");
                while(ptr->next!=NULL){
                        printf("%d->",ptr->info );
                        ptr=ptr->next ;
                }
                printf("%d\n",ptr->info);
                printf("\n\n");
        }
}

void insert_begin(){
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL){
                printf("Out of Memory Space\n");
                return;
        }
        printf("Enter the data value for the node: " );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL){
               	start=temp;
        }else{
               	temp->next=start;
               	start=temp;
        }
        ++count;
        printf("\n\n");
}

void insert_end(){
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL){
                printf("Out of Memory Space\n");
                return;
        }
        printf("Enter the data value for the node: " );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL){
                start=temp;
        }else{
                ptr=start;
                while(ptr->next !=NULL){
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
        ++count;
        printf("\n\n");
}

void reverse(int*arr,int *arrtemp,int k){
	if(k == 1 || k == 0){
		display();
		exit(0);
	}else if(k>count){
		printf("Reverse Amount Larger Than Linked List Size.\n");
		exit(0);
	}else{
		int i,j,s,temp;
		for(i=0;i<count;i=i+k){
			s=k-1;
			temp=0;
			temp = count-k;
			if(i<=temp){
				for(j=i;j<(i+k);j++)				
					arrtemp[s--] = arr[j];
				s=0;
				for(j=i;j<(i+k);j++){
					arr[j]=arrtemp[s++];
				}
			}
		}
	}
}

int main(){
        int choice,i,decimal=0,k;
        while(1){
                printf("1.Display\n");
                printf("2.Insert at the beginning\n");
                printf("3.Insert at the end\n");
                printf("4.EXIT\n");
                printf("Enter your choice: ");
                scanf("%d",&choice);
                if(choice == 1){
                	display();
                }else if(choice ==2){
                	insert_begin();
                }else if(choice ==3){
                	insert_end();
                }else if(choice ==4){
                	break;
                }else{
                	printf("Incorrect Choice.\n");
                }
        }
        int*arr=(int*)malloc(sizeof(int)*count);
        conv(arr);
        printf("Enter Reverse Amount(K): ");
        scanf("%d",&k);
        int*arrtemp=(int*)malloc(sizeof(int)*k);
       /* if(k == 1 || k == 0){
		display();
		exit(0);
	}else if(k>count){
		printf("Reverse Amount Larger Than Linked List Size.\n");
		exit(0);
	}else{
		int w,x,y;
		for(w=0;i<count;w=w+k){
			y=0;
			if(w<=k){
				for(x=w;x<(w+k);x++)				
					arrtemp[y++] = arr[y++];
				x=0;
				for(x=w;x<(w+k);x++)
					arr[x]=arrtemp[x];
			}
		}
	}*/
        reverse(arr,arrtemp,k);
        for(i=0;i<count;i++)
        	printf("%d ",arr[i]);	
        return 0;
}
