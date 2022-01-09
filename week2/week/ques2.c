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
        if(temp->info == 0 || temp->info == 1){
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
        if(temp->info == 0 || temp->info == 1){
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
        }
        printf("\n\n");
}

int power(int base,int check,int a){
	if(check == 1){
    		if(a!=0)
        		return (base * power(base,check,a - 1));
    		else
        		return 1;
        }
        return 0;
}
int main(){
        int choice,i,decimal=0;
        while(1){
                //printf("1.Create\n");
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
        for(i=0;i<count;i++){
        	decimal+=power(2,arr[i],count-(i+1));
        }
        printf("Decimal Equivalent: %d\n",decimal);	
        return 0;
}
