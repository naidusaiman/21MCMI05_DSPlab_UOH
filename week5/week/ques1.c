#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

struct detail{
	char word[20];
	int freq;
};

struct detail s[10];
int sum=0;

int update(struct detail s[],const char unit[],int count){
	int i;
	for(i=0;i<count;i++){
		if(strcmp(s[i].word, unit) == 0){
			s[i].freq++;
			return count;
		}
	}
        strcpy(s[count].word, unit);
	s[count].freq++;
        return (count + 1);
}

void check(char*string){
	char unit[20];
	int i=0,freq=0,j=0,count=0,num=0;
	for(i=0;i<strlen(string);i++){
		while(i<strlen(string) && string[i] != ' ' && isalnum(string[i])){
                	unit[j++] = string[i++];

            	}
		if(j != 0){
			unit[j] = '\0';
			count = update(s, unit, count);
			j = 0;
		}
	}
	for(i=0;i<count;i++)
		sum = sum+s[i].freq;
}

void frequency(char*string){
	char unit[20];
	struct detail temp;
	int i=0,freq=0,j=0,count=0,num=0;
	for(i=0;i<strlen(string);i++){
		while(i<strlen(string) && string[i] != ' ' && isalnum(string[i])){
                	unit[j++] = string[i++];

            	}
		if(j != 0){
			unit[j] = '\0';
			count = update(s, unit, count);
			j = 0;
		}
	}
	/*printf("\nWord\tFrequency\n\n");
	for(i=0;i<count;i++){
		sum = sum+s[i].freq;
		printf("%s\t   %d\n",s[i].word,s[i].freq);
	}*/
	int i1, j1;
   	for(i1 = 0;i1 < count-1;i1++){     
       		for(j1 = 0;j1 < count-i1-1;j1++){
           		if(s[j1].freq < s[j1+1].freq){
              			strcpy(temp.word,s[j1].word);
              			temp.freq = s[j1].freq;
				strcpy(s[j1].word,s[j1+1].word);
				s[j1].freq = s[j1+1].freq;
				strcpy(s[j1+1].word,temp.word);
				s[j1+1].freq = temp.freq;
			}
		}
	}
	printf("Word\tFrequency\n");
	for(i=0;i<count;i++){
		sum = sum+s[i].freq;
		printf("%s\t   %d\n",s[i].word,s[i].freq);
	}
}

int main(){
	char string[100],c;
	int i=0,freq=0;
	int size;
	printf("Enter Number Of Categories: ");
	scanf("%d",&size);	
	char variable[size][1000];
	printf("Enter Categories\n\n");
	for(i = 0; i <= size ;i++)
		fgets(variable[i], sizeof(variable[i]), stdin);  
	//for(int i = 0; i <= size ;i++)  
    		//printf("%s\n", variable[i]);
    	for (i = 0;i < 10;i++)
		s[i].freq = 0;
	printf("\nEnter the complete list of words in a single string:\n");
	i = 0;
	do{
		fflush(stdin);
		c = getchar();
		string[i++] = c;
     	}while(c != '\n');
	string[i-1] = '\0';
	printf("\nCATEGORIES:");
	for(int i = 0; i <= size ;i++)  
    		printf("%s", variable[i]);
    	printf("\nFREQUENCY DESCENDING ORDER:\n");
	frequency(string);
	//printf("%d",sum);	
	return 0;
}
