#include <stdio.h>
#include <stdlib.h>

struct Node{
  	int key,height;
  	struct Node *left;
  	struct Node *right;
};

int height(struct Node *node){
  	if (node == NULL)
    		return 0;
  	return node->height;
}

void preorder(struct Node *root){
 	if(root != NULL){
    		printf("%d ",root->key);
    		preorder(root->left);
    		preorder(root->right);
  	}
}

void inorder(struct Node *root){
 	if(root != NULL){
    		inorder(root->left);
    		printf("%d ",root->key);
    		inorder(root->right);
  	}
}

void postorder(struct Node *root){
 	if(root != NULL){
 		postorder(root->left);
    		postorder(root->right);
    		printf("%d ",root->key);
  	}
}

void CurrentLevel(struct Node* root,int level){
    	if(root == NULL)
        	return;
    	if(level == 1)
        	printf("%d ", root->key);
    	else if(level > 1) {
        	CurrentLevel(root->left,level - 1);
        	CurrentLevel(root->right,level - 1);
    	}
}

void LO(struct Node* root){
	int h = height(root);
    	int i;
    	for(i=1;i<=h;i++)
        	CurrentLevel(root,i);
}

int compsum(struct Node* root){
	static int sum = 0;
	if(root != NULL){
    		sum = sum + (root->key);
    		compsum(root->left);
    		compsum(root->right);
  	}
  	return sum;
}

struct Node *newNode(int value){
  	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  	node->key = value;
  	node->left = NULL;
  	node->right = NULL;
  	node->height = 1;
  	return node;
}

struct Node *rRotate(struct Node *pre){
	struct Node *temp1 = pre->left;
  	struct Node *temp2 = temp1->right;
	temp1->right = pre;
  	pre->left = temp2;
	pre->height = (height(pre->left) > height(pre->right) ? height(pre->left) : height(pre->right)) + 1;
  	temp1->height = (height(temp1->left) > height(temp1->right) ? height(temp1->left) : height(temp1->right)) + 1;
	return temp1;
}

struct Node *lRotate(struct Node *pre){
	struct Node *temp1 = pre->right;
  	struct Node *temp2 = temp1->left;
	temp1->left = pre;
  	pre->right = temp2;
	pre->height = (height(pre->left) > height(pre->right) ? height(pre->left) : height(pre->right)) + 1;
  	temp1->height = (height(temp1->left) > height(temp1->right) ? height(temp1->left) : height(temp1->right)) + 1;
	return temp1;
}

int BF(struct Node *cnode){
  	if(cnode == NULL)
    		return 0;
  	return height(cnode->left) - height(cnode->right);
}

struct Node *insertNode(struct Node *node,int key){
	if(node==NULL)
    		return newNode(key);
	if(key<node->key)
    		node->left = insertNode(node->left, key);
  	else if(key>node->key)
    		node->right = insertNode(node->right,key);
  	else
    		return node;
  	node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
	int balance = BF(node);
  	if(balance>1 && key<node->left->key)
    		return rRotate(node);
	if(balance<-1 && key>node->right->key)
    		return lRotate(node);
	if(balance>1 && key>node->left->key){
    		node->left = lRotate(node->left);
    		return rRotate(node);
  	}
	if(balance<-1 && key<node->right->key){
    		node->right = rRotate(node->right);
    		return lRotate(node);
  	}
	return node;
}

struct Node *min(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

struct Node *deleteNode(struct Node *root,int key){
  	if(root==NULL)
    		return root;

  	if(key<root->key)
    		root->left = deleteNode(root->left,key);
	else if (key>root->key)
    		root->right = deleteNode(root->right,key);
	else{
    		if((root->left==NULL) || (root->right==NULL)){
      			struct Node *temp = root->left ? root->left : root->right;
			if(temp == NULL){
        			temp = root;
        			root = NULL;
      			}else
        			*root = *temp;
      			free(temp);
    		}else{
      			struct Node *temp = min(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,temp->key);
    		}
  	}
	if (root==NULL)
    		return root;
  	root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
	int balance = BF(root);
 	if(balance>1 && BF(root->left)>=0)
    		return rRotate(root);
	if(balance>1 && BF(root->left)<0){
    		root->left = lRotate(root->left);
    		return rRotate(root);
  	}
	if(balance<-1 && BF(root->right)<=0)
    		return lRotate(root);
	if(balance<-1 && BF(root->right)>0){
    		root->right = rRotate(root->right);
    		return lRotate(root);
  	}
	return root;
}

int main(){
	struct Node *root = NULL;
	int choice,data,sum;
	do{
		printf("\nMENU\n");
		printf("1. INSERT\n2. DELETE\n3. PRE-ORDER\n4. IN-ORDER\n5. POST-ORDER\n6. LEVEL-ORDER\n7. SUM\n8. EXIT\n\n");
		scanf("%d",&choice);
		if(choice == 1){
			printf("\nEnter NODE data to insert: ");
			scanf("%d",&data);
			 root = insertNode(root,data);
		}else if(choice == 2){
			printf("\nEnter NODE data to delete: ");
			scanf("%d",&data);
			root = deleteNode(root,data);
		}else if(choice == 3){
			printf("\nPRE-ORDER: ");
			preorder(root);		
		}else if(choice == 4){
			printf("\nIN-ORDER: ");
			inorder(root);		
		}else if(choice == 5){
			printf("\nPOST-ORDER: ");
			postorder(root);		
		}else if(choice == 6){
    			printf("\nLEVEL ORDER TRAVERSAL: ");
    			LO(root);
    		}else if(choice == 7){
    			sum = compsum(root->left);
    			printf("\nSum of left subtree of root node: %d.\n",sum);
    		}else if(choice != 8)
    			printf("\nINVALID CHOICE. TRY AGAIN.\n");			
  	}while(choice!=8);
  	return 0;
}
