#include<stdio.h>
#include<stdlib.h>  
#include<string.h>  
#define MAX 100

int max = 0;
char temp[MAX];

void isPal(char* str,int len){
	//printf("\n\t\t%s\n\n",str);
	int i,flag = 0;
	for(i=0;i<len;i++){
        	if(str[i] != str[len-i-1]){
            		flag = 1;
            		break;
   		}
   	}
   	if(flag){
        }else{
        	if(len > max){
        		max = len;
        		strcpy(temp,str);
        	}
    	}
}

void substring(char s[],char sub[],int p,int len){  
	int c=0;  
       	while(c<len){  
          	sub[c] = s[p+c];  
          	c++;  
       	}  
       	sub[c] = '\0';  
}  
       
int main(){
	int i,j,len,len1,size;
	printf("String Size: ");
	scanf("%d",&size);  
        char c[size];
        char* str = (char*)malloc(sizeof(char)*size);
        printf("Enter String: ");
        scanf(" %[^\n]s",str);
        //scanf("%s",str);  
        len = strlen(str);  
        for(i=0;i<len;i++){ 
            for(j = 1;j<=len-i;j++){  
                substring(str,c,i,j);
                len1 = strlen(c);  
                isPal(c,len1);
        	fflush(stdin);  
            }  
        }
        printf("Maximum Pallindrome Length in the string: %d.\n",max);
        printf("String: %s.\n",temp);  
        return 0;  
}  
