#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

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
	int ele,ind,i=1,hk,t,hk1;
 	printf("\nENTER VALUE: ");
 	scanf("%d",&ele);
 	hk=ele%SIZE;
	if(h[hk]==NULL){
        	h[hk]=ele;
        	++count;
     	}else if(h[hk]!=NULL){
     		while(i<=9){
     			t=((SIZE-3)-(ele%(SIZE-3)));
     			hk1 = (hk + (i*t))%SIZE;
     			if(h[hk1]==NULL){
        			h[hk1]=ele;
        			++count;
         			break;
     			}
     			++i;	
		}
	}
	if(i==SIZE)
		printf("\nUNABLE TO INSERT\n");
}

void search(){
	int ele,ind,i,t,hk,hk1;
 	printf("\nENTER VALUE TO SEARCH: ");
 	scanf("%d",&ele);
 	hk=ele%SIZE;
 	for(i=0;i<SIZE; i++){
    		ind=(hk+i)%SIZE;
    		if(h[ind]==ele){
      			printf("\nVALUE AT INDEX: %d",ind);
      			break;
    		}
    		while(i<=9){
     			t=((SIZE-3)-(ele%(SIZE-3)));
     			hk1 = (hk + (i*t))%SIZE;
     			if(h[hk1] == ele){
        			printf("\nVALUE AT INDEX: %d",hk1);
        			goto label;
     			}
     			++i;	
		}
  	}
  	label:
  	if(i==SIZE)
    		printf("\nVALUE NOT FOUND\n");
}

void display(){
	printf("\n\tHASH-TABLE:\n\n");
	printf("\tINDEX \t VALUE\n");
	for(int i=0;i<SIZE;i++)
		printf("\n\t%d \t %d",i,h[i]);
}
