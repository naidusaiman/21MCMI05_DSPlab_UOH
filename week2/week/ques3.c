#include <stdio.h>
#include <stdlib.h>

struct node{
    char data[2];
    struct node * next;
}*head;

void createList(int n);
void displayList();


int main(){
	int n,data,choice=1;
	head = NULL;
	while(choice != 0){
		printf("============================================\n");
        	printf("CIRCULAR LINKED LIST PROGRAM\n");
        	printf("============================================\n");
        	printf("1. Create List\n");
        	printf("2. Display list\n");
        	printf("0. Exit\n");
        	printf("--------------------------------------------\n");
        	printf("Enter your choice : ");

        	scanf("%d", &choice);

        	switch(choice){
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-2");
        }

        printf("\n\n\n\n\n");
    }

    return 0;
}


void createList(int n){
    int i,j;
    char data[100];
    struct node *prevNode, *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        for(j=0;j<3;j++){
        	scanf("%s",&data);
		head->data[i] = data;
	}
        head->next = NULL;
	prevNode = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            for(j=0;j<3;j++){
            	scanf("%s", &data);
		newNode->data[i] = data;
		}
            newNode->next = NULL;

        
            prevNode->next = newNode;

            prevNode = newNode;
        }


        prevNode->next = head;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



void displayList()
{
    struct node *current;
    int n = 1,j=0;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
        	for(j=0;j<3;j++)
            		printf("%s\t",current->(data+j));
		printf("\n");
            current = current->next;
            n++;
        }while(current != head);
    }
}
