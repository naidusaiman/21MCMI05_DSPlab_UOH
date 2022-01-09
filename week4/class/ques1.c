#include<stdio.h>
#include<stdlib.h>

struct btree{
        int info;
        struct btree *lchild;
        struct btree *rchild;
};

struct lnode{
        struct lnode *prev;
        int info;
        struct lnode *next;
};
struct btree*root = NULL;
struct lnode*pre = NULL;
struct lnode*in = NULL;

struct lnode *addtoempty(struct lnode *start,int data){
        struct lnode *tmp;
        tmp=(struct lnode*)malloc(sizeof(struct lnode));
        tmp->info=data;
        tmp->prev=NULL;
        tmp->next=NULL;
        start=tmp;
        return start;
}

struct lnode *addatend(struct lnode *start,int data){
        struct lnode *tmp,*p;
        tmp=(struct lnode*)malloc(sizeof(struct lnode));
        tmp->info=data;
        p=start;
        while(p->next!=NULL)
                p=p->next;
        p->next=tmp;
        tmp->next=NULL;
        tmp->prev=p;
        return start;
}
struct lnode *create(struct lnode *start,int n){
        int i,data;
        start=NULL;
        for(i=1;i<=n;i++){
                printf("Element %d : ",i);
                scanf("%d",&data);
                if(start==NULL)
                        start=addtoempty(start,data);
                else
                        start=addatend(start,data);
        }
        return start;
}
struct btree *construct(struct lnode *inptr,struct lnode *preptr,int num){
        struct btree *temp;
        struct lnode *q;
	int i,j;
        if(num==0)
                return NULL;
	temp=(struct btree *)malloc(sizeof(struct btree));
        temp->info=preptr->info;
        temp->lchild = NULL;
        temp->rchild = NULL;
	if(num==1)
                return temp;
	q=inptr;
        for(i=0;q->info!=preptr->info;i++)
                q = q->next;
	temp->lchild=construct(inptr,preptr->next,i);
        for(j=1;j<=i+1;j++)
                preptr=preptr->next;
        temp->rchild=construct(q->next,preptr,num-i-1);
	return temp;
}
void inorder(struct btree *ptr){
        if(root==NULL){
                printf("Tree is empty");
                return;
        }
        if(ptr!=NULL){
                inorder(ptr->lchild);
                printf("%d  ",ptr->info);
                inorder(ptr->rchild);
        }
}
void postorder(struct btree *ptr){
        if(root==NULL){
                printf("Tree is empty");
                return;
        }
        if(ptr!=NULL){
                postorder(ptr->lchild);
                postorder(ptr->rchild);
                printf("%d  ",ptr->info);
        }
}

int search(struct btree *ptr,int n){
	static int val = 0;
        if(root==NULL){
                printf("EMPTY TREE, Cannot search for element");
                return -1;
        }
        if(ptr!=NULL){
        	if(ptr->info==n)
                	++val;
                search(ptr->lchild,n);
                search(ptr->rchild,n);
        }
        return val;
}


int main(){
        int node,find;
	printf("Node Count: ");
        scanf("%d",&node);
	printf("Inorder List\n");
        in=create(in,node);
	printf("Preorder List\n");
        pre=create(pre, node);
	root = construct(in,pre,node);
	printf("\n");
	printf("QUESTION 1: Binary Tree Constructed.\n");
        printf("QUESTION 2: Postorder of Constructed Tree: ");  
        postorder(root);
        printf("\nEnter Node Value(TO CHECK PRESENT OR NOT): ");
        scanf("%d",&find);
        int val = search(root,find);
        if(val == 1)
        	printf("QUESTION 3: %d present in binary tree.\n",find);
        else if(val > 1)
        	printf("QUESTION 3: %d present in binary tree %d times.\n",find,val);
        else
        	printf("QUESTION 3: Node not present.\n");
        printf("\n");
        return 0;
}
