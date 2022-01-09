//Stack Using LinkedList
//Copyright @ Saiman
#include <stdio.h>  
#include <stdlib.h>  
struct node{  
    int val;  
    struct node *next;  
};
struct node *head;  
void push(){  
	int val;  
	struct node *ptr = (struct node*)malloc(sizeof(struct node));   
	if(ptr==NULL)  
            printf("Element Cannot Be Pushed");   
        else{  
        	printf("Enter the value");  
         	scanf("%d",&val);  
           	if(head==NULL){         
                	ptr->val = val;  
                	ptr -> next = NULL;  
                	head=ptr;  
            	}else{  
                	ptr->val = val;  
                	ptr->next = head;  
                	head=ptr;  
               	}  
            	printf("Item pushed");  
	}  
} 
void pop(){  
        int item;  
        struct node *ptr;  
        if (head==NULL)  
        	printf("Stack Underflow");   
        else{  
            item = head->val;  
            ptr = head;  
            head = head->next;  
            free(ptr);  
            printf("Item popped");  
       }  
} 
void display(){  
        int i;  
        struct node *ptr;  
        ptr=head;  
        if(ptr==NULL)
            printf("No Elements Present In The Stack\n");    
        else{    
            while(ptr!=NULL){  
                printf("%d\n",ptr->val);  
                ptr = ptr->next;  
            }  
        }  
}      
int main(){  
        int choice=0;       
        while(choice != 4)  
        {  
            printf("\n\nChose one from the below options...\n");  
            printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
            printf("\n Enter your choice \n");        
            scanf("%d",&choice);  
            switch(choice){  
                case 1: push();  
                        break;   
                case 2: pop();  
                        break;  
                case 3: display();  
                        break;  
           	case 4: printf("Exiting");  
                        break;   
                default:printf("Invalid Choice Entered.\n");  
                }   
        }
        return 0;  
}  
