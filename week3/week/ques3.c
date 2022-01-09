#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char data[100];
   	int priority;
   	struct node* next;
}Node;

Node* newNode(char*d,int p){
   	Node* temp = (Node*)malloc(sizeof(Node));
   	strcpy(temp->data,d);
   	temp->priority = p;
   	temp->next = NULL;
   	return temp;
}

void peek(Node** head){
	printf("%s\t",(*head)->data);
	printf("%d\n",(*head)->priority);
}
void pop(Node** head){
   	Node* t = *head;
   	(*head) = (*head)->next;
   	free(t);
}
void push(Node** head,char*d,int p){
   	Node* s = (*head);
   	Node* t = newNode(d,p);
   	if((*head)->priority < p){
      	t->next = *head;
      	(*head) = t;
   	}else{
      		while(s->next != NULL && s->next->priority > p){
        	 	s = s->next;
      		}
      		t->next = s->next;
      		s->next = t;
   	}
}

int isEmpty(Node** head){
   	return (*head) == NULL;
}

int main(){
	char*ch=(char*)malloc(sizeof(char)*100);
	int gate,choice;
	printf("Enter NAME: ");
	scanf("%s",ch);
	printf("Enter GATE SCORE: ");
	scanf("%d",&gate);
   	Node* pq = newNode(ch,gate);
   	while(1){
   		printf("AVAILABLE CHOICES:\n");
   		printf("1. Insert Data\n2. Delete Data\n3. EXIT\n");
   		printf("Enter Choice: ");
   		scanf("%d",&choice);
   		if(choice == 1){
   			printf("Enter NAME: ");
			scanf("%s",ch);
			printf("Enter GATE SCORE: ");
			scanf("%d",&gate);
   			push(&pq,ch,gate);
   		}else if(choice == 2){
   			pop(&pq);
   		}else if(choice == 3){
   			while(!isEmpty(&pq)){
      				peek(&pq);
      				pop(&pq);
   			}
   			exit(0);
   		}else
   			printf("Incorrect Choice. TRY AGAIN.\n");
	}		
   	return 0;
}
