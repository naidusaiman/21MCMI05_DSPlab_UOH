#include <stdio.h>
#include <stdlib.h>

struct sNode{
	char data;
    	struct sNode* next;
};

void push(struct sNode** top_ref,int new_data){
	struct sNode* new_node=(struct sNode*)malloc(sizeof(struct sNode));
 	if(new_node == NULL){
        	printf("Stack Overflow\n");
        	getchar();
        	exit(0);
    	}
 	new_node->data = new_data;
 	new_node->next = (*top_ref);
 	(*top_ref) = new_node;
}

int pop(struct sNode** reftop){
	char ser;
    	struct sNode* top;
    	if(*reftop == NULL) {
        	printf("Stack overflow n");
        	getchar();
        	exit(0);
    	}else{
        	top = *reftop;
        	ser = top->data;
        	*reftop = top->next;
        	free(top);
        	return ser;
    	}
}

int isMatchingPair(char character1, char character2){
	if(character1=='(' && character2==')')
        	return 1;
    	else if(character1=='{' && character2=='}')
        	return 1;
    	else if(character1=='[' && character2==']')
        	return 1;
    	else
        	return 0;
}
 

int areBracketsBalanced(char exp[]){
	int i = 0;
    	struct sNode* stack = NULL;
    	while(exp[i]){
        	if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
            		push(&stack, exp[i]);
 		if(exp[i]=='}' || exp[i]==')' || exp[i]==']'){
            		if(stack == NULL)
                		return 0;
            		else if(!isMatchingPair(pop(&stack),exp[i]))
                		return 0;
        	}
        	i++;
    }
	if(stack == NULL)
        	return 1;
    	else
        	return 0;
}

int main(){
	int size,i;
	printf("Size: ");
	scanf("%d",&size);
	char exp[size];
	printf("Enter Data: ");
	scanf("%s",exp);
    	if(areBracketsBalanced(exp))
        	printf("true \n");
    	else
        	printf("false \n");
    	return 0;
}
