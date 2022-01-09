#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int top1=-1,top=-1,ios=0;
char stack[MAX],z[200];

void strrev(char *str1){  
	int i, len, temp;  
    	len = strlen(str1);  
    	for(i = 0;i < len/2;i++){   
        	temp = str1[i];  
        	str1[i] = str1[len - i - 1];  
        	str1[len - i - 1] = temp;  
    	}  
}

void push(char x){
	stack[++top] = x;
}

char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

void popx(){
    if(top == -1){
      	z[ios]='\0';
        exit(0);
    }
    else
        z[ios++] = stack[top--];
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void push1(char c){
	if(top1==MAX-1){
		printf("\nSTACK IS FULL");
	}else{
		top1++;
		stack[top1]=c;
	}
}

char pop1(){
	char c = stack[top1];
	top1--;
	return c;
}

void postfix(char*r){
	char*e,x;
	e=r;
	printf("\nPOSTFIX EXPRESSION: ");
	while(*e != '\0'){
        	if(isalnum(*e))
          	  	printf("%c",*e);
        	else if(*e == '(')
            		push(*e);
        	else if(*e == ')'){
            		while((x = pop()) != '(')
                		printf("%c", x);
        	}
        	else{
            		while(priority(stack[top]) >= priority(*e))
                		printf("%c",pop());
            			push(*e);
        	}
        	e++;
    	}
    	while(top != -1){
        	printf("%c",pop());
    	}
    	printf("\n");
}	

int isOperator(char symbol) {
	switch(symbol) {
		case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '^':
		        case '$':
		        case '&':
		        case '(':
		        case ')':
		        return 1;
		break;
		default:
		        return 0;
	}
}

void prefixx(char infix[20]){
	char prefix[20];
	int i,j=0;
	char symbol;
	stack[++top]='#';
	strrev(infix);
	for (i=0;i<strlen(infix);i++){
		symbol=infix[i];
		if (isOperator(symbol)==0){
			prefix[j]=symbol;
			j++;
		}else{
			if(symbol==')'){
				push(symbol);
			}else if(symbol == '(') {
				while(stack[top]!=')') {
					prefix[j]=pop();
					j++;
				}
				pop();
			}else{
				if (priority(stack[top])<=priority(symbol)) {
					push(symbol);
				} else {
					while(priority(stack[top])>=priority(symbol)) {
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				}
			}
		}
	}
	while (stack[top]!='#') {
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
	strrev(prefix);
	printf("PREFIX EXPRESSION: ");
	puts(prefix);
	printf("\n");
}
int main(){
	char exp[MAX],tmp;
	int i,flag=1;
	printf("\nINFIX EXPRESSION: ");
	scanf("%s",exp);
	for(i=0;i<strlen(exp);i++){
		if(exp[i]=='(' || exp[i]=='{'||exp[i]=='[')
			push1(exp[i]);
		if(exp[i]==')'|| exp[i]=='}'||exp[i]==']'){
			if(top1==-1)
				flag=0;
			else{
				tmp=pop1();
				if(exp[i]==')' && ( tmp=='{' || tmp=='['))
					flag=0;
				if(exp[i]=='}' && ( tmp=='(' || tmp=='['))
					flag=0;
				if(exp[i]==']' && ( tmp=='(' || tmp=='{'))
					flag=0;
			}
		}
	}
	if(top1>=0)
		flag=0;
	if(flag==1){
		//printf("\nVALID EXPRE");
		if((exp[0]=='+' || exp[0]=='-' || exp[0]=='*' || exp[0]=='/' || exp[0]=='%') || ((exp[0]=='+' || exp[0]=='-' || exp[0]=='*' || exp[0]=='/' || exp[0]=='%')&&(exp[1]=='+' || exp[1]=='-' || exp[1]=='*' || exp[1]=='/' || exp[1]=='%'))){
			printf("\nINVALID INFIX EXPRESSION.");
			return 0;
		}
		for(i=0;i<strlen(exp);i++){
			if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' || exp[i]==')' || exp[i]=='}' || exp[i]==']'){
			}else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='%'){
				if(((exp[i-1]==')' || exp[i-1]=='}' || exp[i-1]==']') || (exp[i-1] >= 97 && exp[i-1] <= 122)) && ((exp[i+1]=='(' || exp[i+1]=='{' || exp[i+1]=='[') || (exp[i+1] >= 97 && exp[i+1] <= 122))){
				}else{
					printf("\nINVALID INFIX EXPRESSION.");
					return 0;
				}	
			}else{
				if(!(exp[i+1]>=97 && exp[i+1]<=122)){
				}else{
					printf("\nINVALID INFIX EXPRESSION.");
					return 0;
				}
			}
		}
		printf("\nGiven String in INFIX EXPRESSION format.");
		postfix(exp);		
		prefixx(exp);
	}else
		printf("\nUnbalanced Brackets. INVALID INFIX EXPRESSION");
	return 0;
}
