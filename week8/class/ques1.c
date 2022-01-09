#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int count=0;

void insert();
void search();
void display();

int h[SIZE];


int main(){
	int choice;
	float lf;
    	while(1){
        	printf("\nMENU:\n1. INSERT\n2. SEARCH\n3. DISPLAY\n4. LOAD-FACTOR\n5. EXIT\n");
        	printf("CHOICE: ");
        	scanf("%d",&choice);
		if(choice==1){
                	insert();
           	}else if(choice==2){
           		search();
           	}else if(choice==3){
           		display();
           	}else if(choice==4){
           		if(count==0)
           			printf("\nNO ELEMENT INSERTED YET.\n");
           		else{	
           			lf = (float)count/(float)SIZE;
           			printf("LOAD FACTOR: %lf.\n",lf);
           		}
           	}else if(choice==5){
           		exit(0);
           	}else{
           		printf("WRONG CHOICE ENTERED. PLEASE TRY AGAIN.\n");
           	}
	}
}

void insert(){
	int ele,ind,i,hk;
 	printf("\nENTER VALUE: ");
 	scanf("%d",&ele);
 	hk=ele%SIZE;
 	for(i=0;i<SIZE;i++){
		ind=(hk+i)%SIZE;
		if(h[ind]==NULL){
        		h[ind]=ele;
        		++count;
         		break;
     		}
	}
	if(i==SIZE)
		printf("\nUNABLE TO INSERT\n");
}

void search(){
	int ele,ind,i,hk;
 	printf("\nENTER VALUE TO SEARCH: ");
 	scanf("%d",&ele);
 	hk=ele%SIZE;
 	for(i=0;i<SIZE; i++){
    		ind=(hk+i)%SIZE;
    		if(h[ind]==ele){
      			printf("\nVALUE AT INDEX: %d",ind);
      			break;
    		}
  	}
  	if(i==SIZE)
    		printf("\nVALUE NOT FOUND\n");
}

void display(){
	printf("\n\tHASH-TABLE:\n\n");
	printf("\tINDEX \t VALUE\n");
	for(int i=0;i<SIZE;i++)
		printf("\n\t%d \t %d",i,h[i]);
}
