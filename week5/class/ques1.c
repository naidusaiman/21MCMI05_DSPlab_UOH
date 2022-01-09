#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node* search(struct node *root,int x){
	if(root==NULL || root->data==x) 
	        return root;
    	else if(x>root->data) 
        	return search(root->right,x);
    	else 
        	return search(root->left,x);
}

struct node* find_minimum(struct node *root){
	if(root == NULL)
        	return NULL;
    	else if(root->left != NULL) 
        	return find_minimum(root->left);
    	return root;
}

struct node* new_node(int x){
    	struct node *p;
    	p = malloc(sizeof(struct node));
    	p->data = x;
    	p->left = NULL;
    	p->right = NULL;
	return p;
}

struct node* insert(struct node *root,int x){
    	if(root==NULL)
		return new_node(x);
    	else if(x>root->data)
        	root->right = insert(root->right,x);
    	else
        	root->left = insert(root->left,x);
    	return root;
}

struct node* delete(struct node *root, int x){
	if(root==NULL)
	        return NULL;
    	if(x>root->data)
        	root->right = delete(root->right,x);
    	else if(x<root->data)
        	root->left = delete(root->left, x);
    	else{
        	if(root->left ==NULL && root->right == NULL){
        	    	free(root);
        	    	return NULL;
        	}else if(root->left==NULL || root->right==NULL){
            		struct node *temp;
            		if(root->left==NULL)
                		temp = root->right;
            		else
                		temp = root->left;
            		free(root);
            		return temp;
        	}else{
            		struct node *temp = find_minimum(root->right);
            		root->data = temp->data;
            		root->right = delete(root->right,temp->data);
        	}
    	}
    	return root;
}

void inorder(struct node *root){
    	if(root!=NULL){
        	inorder(root->left);
        	printf(" %d ", root->data);
        	inorder(root->right);
    	}
}

int sumleaf(struct node *root){
	static int sum = 0;
    	if(!root){
    		return;
    	}
    	if(root->left==NULL && root->right==NULL){
    		sum+=(root->data);
       	}
       	sumleaf(root->left);
        sumleaf(root->right);
    	return sum;
}

int sumnleaf(struct node *root){
	static int sum = 0;
    	if(root->left!=NULL || root->right!=NULL){
    		sum+=(root->data);
        	sumnleaf(root->left);
        	sumnleaf(root->right);
    	}
    	return sum;
}

int height(struct node* node){
    	if(node == NULL)
        	return 0;
    	else{
        	int lheight = height(node->left);
        	int rheight = height(node->right);
        		if(lheight > rheight)
            			return(lheight + 1);
        		else
            			return(rheight + 1);
    	}
}

void CurrentLevel(struct node* root,int level){
    	if(root == NULL)
        	return;
    	if(level == 1)
        	printf("%d ", root->data);
    	else if(level > 1) {
        	CurrentLevel(root->left,level - 1);
        	CurrentLevel(root->right,level - 1);
    	}
}

void LO(struct node* root){
	int h = height(root);
    	int i;
    	for(i=1;i<=h;i++)
        	CurrentLevel(root,i);
}
 
int main(){
	struct node *root;
	int n,data,choice,s,s1;
	printf("Enter Root Value: ");
	scanf("%d",&n);

    	root = new_node(n);
    	while(1){
    		printf("\nAVAILABLE CHOICES:\n");
    		printf("1. INSERT\n2. DELETE\n3. LEVEL-ORDER TRAVERSE\n4. SUM OF LEAF NODES\n5. SUM OF NON-LEAF NODES\n6. EXIT\n");
    		scanf("%d",&choice);
    		if(choice == 1){
    			printf("Enter Data: ");
    			scanf("%d",&data);
    			insert(root,data);
    			printf("DATA inserted successfully.\n");
    		}else if(choice == 2){
    			printf("Enter node data from tree to delete: ");
    			scanf("%d",&data);
    			root = delete(root,data);
    			printf("DATA deleted successfully.\n");
    		}else if(choice == 3){
    			printf("LEVEL ORDER TRAVERSAL: ");
    			LO(root);
    			printf("\n");
    		}else if(choice == 4){
    			s = sumleaf(root);
    			printf("Sum Of Leaf Nodes: %d.\n",s);
    		}else if(choice == 5){
    			s1 = sumnleaf(root);
    			printf("Sum Of Non - Leaf Nodes: %d.\n",s1);
    		}else if(choice == 6){
    			//inorder(root);
    			exit(0);
    		}else{
    			printf("Incorrect Choice. TRY AGAIN.\n");
    		}	
    	}


    

    printf("\n");

    return 0;
}
