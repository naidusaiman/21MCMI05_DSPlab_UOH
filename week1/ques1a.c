#include<stdio.h>
#include<stdlib.h>
int top=-1;
void push(int*stack,int max,int ele){
	if(top==max)
		printf("Stack Overflow.\n");
	else{
		stack[++top]=ele;
		printf("Element Pushed Successfully.\n");
	}
}
void pop(int*stack){
	if(top==-1)
		printf("Stack Underflow.\n");
	else{
		printf("Element %d Popped Sucessfully.\n",stack[top]);
		top-=1;
	}
}
void display(int*stack){
	int i=0;
	for(i=top;i>=0;i--)
		printf("%d\n",stack[i]);
}
int main(){
	int size;
	printf("Stack Size: ");
	scanf("%d",&size);
	int*stack=(int*)malloc(sizeof(int)*size);
	int max=size-1;
	int choice,ele,rep=1;
	do{
		printf("AVAILABLE CHOICES:\n1.PUSH\n2.POP\n3.DISPLAY\n\t\tCHOICE: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter Element: ");
				scanf("%d",&ele);
				push(stack,max,ele);
				break;
			case 2: pop(stack);
				break;
			case 3: display(stack);
				break;
			default: printf("Wrong Choice Entered.\n");
				break;
		}
		printf("Click 1 to Repeat.\nClick 0 to Stop.\nDo you wish to repeat: ");
		scanf("%d",&rep);
	}while(rep == 1);
	return 0;
}
