#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
};

 
typedef struct node snode;
snode *newnode, *ptr, *prev, *temp;

snode *first = NULL, *last = NULL;

snode* create_node(int val){
	newnode = (snode *)malloc(sizeof(snode));
	if(newnode == NULL){
		printf("Memory Cannot be Assigned\n");
		return 0;
	}else{
		newnode->value = val;
		newnode->next = NULL;
	        return newnode;

    }
}

void insert_node_first(){
	int val;
	printf("Enter data for the node: ");
	scanf("%d", &val);
	newnode = create_node(val);
	if(first == last && first == NULL){
		first = last = newnode;
	        first->next = NULL;
		last->next = NULL;
	}
	else{
		temp = first;
	        first = newnode;
	        first->next = temp;
	}
	printf("Inserting Successfull");    
}

void insert_node_last(){
	int val;
	printf("\nEnter data for the node:");    
	scanf("%d", &val);
	newnode = create_node(val);
	if(first == last && last == NULL){
	        first = last = newnode;
		first->next = NULL;
	        last->next = NULL;
	}else{
		last->next = newnode;
	        last = newnode;
		last->next = NULL;
	}
	printf("Inserting Successfull");
}    

void insert_node_pos(){
	int pos, val, cnt = 0, i;
	printf("\nEnter data for the node:");
	scanf("%d", &val);
	newnode = create_node(val);
	printf("\nEnter Position: ");
	scanf("%d", &pos);
	ptr = first;
	while (ptr != NULL){
		ptr = ptr->next;
		cnt++;
	}
	if (pos==1){
		if (first == last && first == NULL){
			first = last = newnode;
			first->next = NULL;
			last->next = NULL;
		}
		else{
			temp = first;
			first = newnode;
	                first->next = temp;
		}
		printf("Inserting Successfull.\n");
	}else if(pos>1 && pos<=cnt){
		ptr = first;
		for (i = 1;i < pos;i++){
			prev = ptr;
	                ptr = ptr->next;
		}
		prev->next = newnode;
		newnode->next = ptr;
		printf("Inserting Successfull.\n");
	}
	else
		printf("Position Unreachable.\n");
}

void delete_pos(){
	int pos, cnt = 0, i;
	if(first == NULL){
		printf("EMPTY LIST: No node to delete.\n");
	}else{
		printf("Enter position to be deleted:");
		scanf(" %d", &pos);
		ptr = first;
	if(pos == 1){
		first = ptr->next;
		printf("Element deleted\n");    

        }else{
		while (ptr != NULL){
			ptr = ptr->next;
			cnt = cnt + 1;
	        }

            	if(pos > 0 && pos <= cnt){
			ptr = first;
			for (i=1;i<pos;i++){
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = ptr->next;
		}
		else{
			printf("Position Unreachable.\n");
		}
		free(ptr);
		printf("Element deleted\n");
	}

    }

}

void display(){
	if(first == NULL)
		printf("No nodes in the list to display\n");
	else{
		for(ptr=first;ptr!=NULL;ptr=ptr->next)    
			printf("%d\t", ptr->value);
	}
}

void rev_display(snode *ptr){
	int val;
	if (ptr==NULL)
		printf("No nodes to display\n");
	else{
		if(ptr != NULL){
			val = ptr->value;
			rev_display(ptr->next);
			printf("%d\t", val);        
		}
	}
}
int main(){
	int ch;
	char ans = 'Y';
	while (ans == 'Y'||ans == 'y'){
		printf("\n*****\tOperations on singly linked list\t*****\n");
		printf("1. INSERT NODE AT BEGINNING\n");
		printf("2. INSERT NODE AT END\n");
		printf("3. INSERT NODE AT POSITION\n");
		printf("4. DELETE NODE FROM ANY POSITION\n");
		printf("5. DISPLAY\n");
		printf("6. REVERSE\n");
		printf("7. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &ch);
		if(ch==1){
			printf("Inserting Node At Beginning\n");
			insert_node_first();
		}else if(ch==2){
			printf("Inserting Node At End\n");
			insert_node_last();
		}else if(ch==3){
			printf("Inserting Node At Position\n");
			insert_node_pos();
		}else if(ch==4){
			printf("Deleting Node From Any Position\n");
			delete_pos();
		}else if(ch==5){
			printf("DISPLAY: \n");
			display();
		}else if(ch==6){
			printf("REVERSE \n");
			rev_display(first);
		}else if(ch==7){
			return 0;
		}else{
			printf("Incorrect Choice\n");
		}

		printf("Press Y To Continue");
		scanf(" %c", &ans);
	}
	return 0;
}

