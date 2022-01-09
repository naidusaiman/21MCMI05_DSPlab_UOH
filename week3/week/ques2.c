#include<stdio.h>  
#include<stdlib.h>  
  
struct Node{ 
  int data; 
  struct Node *next; 
};  
  
void split(struct Node *head,struct Node **head1,struct Node **head2){ 
	struct Node *slow = head; 
	struct Node *fast = head;  
  	if(head == NULL) 
    		return; 
   	while(fast->next != head && fast->next->next != head){ 
     		fast = fast->next->next; 
     		slow = slow->next; 
  	}   
  	if(fast->next->next == head) 
    		fast = fast->next;       
    	*head1 = head;     
       	if(head->next != head) 
    		*head2 = slow->next; 
    	fast->next = slow->next; 
    	slow->next = head;        
} 
  
void enq(struct Node **head, int data){ 
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); 
  	struct Node *t = *head;  
  	ptr->data = data;   
  	ptr->next = *head;  
  	if(*head != NULL){ 
    		while(t->next != *head) 
      			t = t->next;         
    		t->next = ptr;  
  	}else
     		ptr->next = ptr;
  	*head = ptr;      
}  
  
void display(struct Node *head){ 
	struct Node *t = head;  
  	if(head != NULL){ 
    		do{ 
      			printf("%d->", t->data); 
      			t = t->next; 
    		}while(t->next != head);
    		printf("%d",t->data); 
  	}
  	printf("\n"); 
} 
 
void display1(struct Node *head){ 
	struct Node *t = head;  
  	if(head != NULL){ 
    		do{ 
      			printf("%d ", t->data); 
      			t = t->next; 
    		}while(t != head); 
  	}
  	printf("\n"); 
}  
int main(){ 
  	int size,i;
  	printf("Enter Size: ");
  	scanf("%d",&size);
  	int*arr=(int*)malloc(sizeof(int)*size);
    	struct Node *h = NULL; 
  	struct Node *h1 = NULL; 
  	struct Node *h2 = NULL;   
	for(i=0;i<size;i++){
		printf("Enter %d Element: ",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=size-1;i>=0;i--)
		enq(&h,arr[i]);
  	printf("Circular Linked List: ");
  		if(size == 1)
  			display1(h);
  		else
  			display(h);       
  	split(h,&h1,&h2); 
   	printf("\n");
  	display1(h1);   
  	printf("\n"); 
 	display1(h2);   
    	return 0; 
}  
