#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void height(struct node* root,int currentLevel,int num) {
   	if(root == NULL){
        	return;   
    	}
  	if(root->data == num){
        	printf("Height Of Tree: %d \n",currentLevel);
 	}
        height(root->left, currentLevel+1, num);
    	height(root->right, currentLevel+1, num);
}
 

struct node* createNode(int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
    	newNode->left = NULL;
	newNode->right = NULL;
    	return newNode;
}

struct queue{
	int front,rear,size;
	struct node* *arr;
};

struct queue* createQueue(){
	struct queue* new = (struct queue*)malloc(sizeof(struct queue));
	new->front = -1;
    	new->rear = 0;
	new->size = 0;
	new->arr = (struct node**) malloc(100 * sizeof( struct node* ));
	return new;
}

void enqueue(struct queue* queue,struct node *temp){
	queue->arr[queue->rear++] = temp;
    	queue->size++;
}

struct node *dequeue(struct queue* queue){
	queue->size--;
	return queue->arr[++queue->front];
}

void insertNode(int data){
    	struct node *newNode = createNode(data);
		if(root == NULL){
			root = newNode;
			return;
    	}else{
		struct queue* queue = createQueue();
		enqueue(queue, root);
		while(1){
			struct node *node = dequeue(queue);
			if(node->left != NULL && node->right != NULL){
				enqueue(queue, node->left);
				enqueue(queue, node->right);
			}else{
				if(node->left == NULL){
					node->left = newNode;
					enqueue(queue, node->left);
				}else{
					node->right = newNode;
					enqueue(queue, node->right);
				}
				break;
			}
		}
	}
}

void inorderTraversal(struct node *node){
	if(root == NULL){
		printf("Tree is empty\n");
		return;
	}else{
		if(node->left != NULL)
			inorderTraversal(node->left);
		printf("%d ", node->data);
		if(node->right != NULL)
			inorderTraversal(node->right);
	}
}

void postorderTraversal(struct node *node){
	if(root == NULL){
		printf("Tree is empty\n");
		return;
	}else{
		if(node->left != NULL)
			postorderTraversal(node->left);
		if(node->right != NULL)
			postorderTraversal(node->right);
		printf("%d ", node->data);
	}
}

void preorderTraversal(struct node *node){
	if(root == NULL){
		printf("Tree is empty\n");
		return;
	}else{
		printf("%d ", node->data);
		if(node->left != NULL)
			preorderTraversal(node->left);
		if(node->right != NULL)
			preorderTraversal(node->right);
	}
}
int main(){

	int num,i=0,val;
	printf("Enter Element Size: ");
	scanf("%d",&num);
	int*array=(int*)malloc(sizeof(int)*num);
	for(i=0;i<num;i++){
		scanf("%d",&val);
		array[i]=val;
		insertNode(val);
    	}
	printf("\n\n");
	printf("\nINORDER TRAVERSAL: ");
	inorderTraversal(root);
	printf("\nPREORDER TRAVERSAL: ");
	preorderTraversal(root);
	printf("\nPOSTORDER TRAVERSAL: ");
	postorderTraversal(root);
	
	printf("\n\n");
	int j,k;
	for(j=0;j<i;j++){
		if(j==0){
			for(k=0;k<i-j;k++)
				printf(" ");
		}
		if(j==1 || j==3 || j==7 || j==15 || j==31){
			printf("\n");
			for(k=0;k<i-j;k++)
				printf(" ");
		}	
		printf("%d ",array[j]);
	}
	printf("\n");
	height(root,0,array[i-1]); 
    return 0;
}
