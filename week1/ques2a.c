#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int front=-1,rear=-1;
void enqueue(int*queue,int item,int size){
    if(rear==size-1)
        printf("Can't enqueue as the queue is full\n");
    else{
        if(front == -1)
            front = 0;
	rear = rear + 1;
        queue[rear] = item;
   }
}
void dequeue(int*queue){
    if(front == -1)
        printf("Queue Is Empty\n");
    else{
        printf("Element dequeued : %d\n", queue[front]);
        front = front + 1;
        if(front > rear){
	        front = -1;
	        rear = -1;
        }
   }
}
void printQueue(int*queue){
    if(rear==-1)
        printf("\nQueue Is Empty");
    else{
        int i;
        for(i = front; i <= rear; i++)
	        printf("%d ",queue[i]);
   }
}
int main()
{
    int size;
    printf("Size: ");
    scanf("%d",&size);
    int choice,ele,rep;
    int*queue=(int*)malloc(sizeof(int)*size);
    do{
		printf("AVAILABLE CHOICES:\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n\t\tCHOICE: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter Element: ");
				scanf("%d",&ele);
				enqueue(queue,ele,size);
				break;
			case 2: dequeue(queue);
				break;
			case 3: printQueue(queue);
				break;
			default: printf("Wrong Choice Entered.\n");
				break;
		}
		printf("Click 1 to Repeat.\nClick 0 to Stop.\nDo you wish to repeat: ");
		scanf("%d",&rep);
	}while(rep == 1);

    return 0;
}
