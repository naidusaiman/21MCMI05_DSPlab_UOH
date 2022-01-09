#include<stdio.h>
#include<stdlib.h>

int firq=0,secq=0,thiq=0,fouq=0;
int max = 1000;

int insq(int queue[max],int qno,int rear[],int limit[],int *data){
	if(rear[qno]==limit[qno])
	        return -1;
	else{
		if(qno==1)
			++firq;
		else if(qno==2)
			++secq;
		else if(qno==3)
			++thiq;
		else if(qno==4)
			++fouq;
        	rear[qno]++;
        	queue[rear[qno]]=*data;
        	return 1;
    	}
}

int delq(int queue[max],int qno,int front[],int rear[],int *data){
	if(front[qno]==rear[qno])
        	return -1;
    	else{
    		if(qno==1 && firq!=0)
			--firq;
		else if(qno==2 && secq!=0)
			--secq;
		else if(qno==3 && thiq!=0)
			--thiq;
		else if(qno==4 && fouq!=0)
			--fouq;
        	front[qno]++;
        	*data=queue[front[qno]];
        	return 1;
    	}
}

int getQueueNumber(int n){
	int qNo=0;
    	Inva:
    	printf("Queue Number from (1 to %d): ", n);
    	scanf("%d",&qNo);
    	if(qNo<1 || qNo >n){
        	printf("Queue Out Of Bound\n");
        	goto Inva;
    	}
    	return qNo;
}

int main(){
	//int maximum;
	int queue[max],data;
    	int bott[10],limit[10],f[10],r[10];
    	int i,n=4,qno,option,reply;
    	int size1=5,size2=3,size3=2,size4=6; 
    	bott[0] = -1;
        bott[1]=bott[0]+size1;
        bott[2]=bott[1]+size2;
        bott[3]=bott[2]+size3;
        
        limit[0]=bott[0]+size1;
        limit[1]=bott[1]+size2;
        limit[2]=bott[2]+size3;
        limit[3]=bott[3]+size4;

    	for(i=0;i<n;i++)
        	f[i]=r[i]=bott[i];
 
        while(1){
         	printf("\n\nAvailable Choices\n");
        	printf("1. Insert in a Queue\n");
        	printf("2. Delete from a Queue\n");
        	printf("3. Display Selected Queue\n");
        	printf("4. Display All Queues\n");
        	printf("5. Delete from a Queue with Maximum Elements\n");
        	printf("6. Insert in a Queue with Minimum Elements\n");
        	printf("7. Exit\n");
        	printf("\nEnter Choice: ");
        	scanf("%d", &option);
        	if(option==1){
                	qno=getQueueNumber(n);
                	printf("\nEnter Data: ");
                	scanf("%d",&data);
                	reply = insq(queue,qno-1,r,limit,&data);
                	if(reply==-1)
                    		printf("\nQueue %d is Full \n",qno);
                	else
                    		printf("\n %d is inserted in queue number - %d \n",data,qno);
                }else if(option==2){
                	qno=getQueueNumber(n);
                	reply=delq(queue,qno-1,f,r,&data);
                	if(reply==-1)
                    		printf("\nQueue %d is Empty \n",qno);
                	else
                    		printf("\n%d is deleted from Queue No - %d \n", data, qno);
           	}else if(option==3){
                	qno=getQueueNumber(n);
                	printf("\nElements of Queue %d are as: ", qno);
                	if(f[qno-1]==r[qno-1]){
                    		printf("Queue is empty\n");
                	}else{
                		for(i=f[qno-1]+1;i<=r[qno-1];i++)
                    			printf("%d ",queue[i]);
                		printf("\n");
                	}
                }else if(option==4){
                	for(qno=1;qno<5;qno++){
                		printf("\nElements of Queue %d are as: ", qno);
                		if(f[qno-1]==r[qno-1]){
                    			printf("Queue is empty");
                		}else{
                			for(i=f[qno-1]+1;i<=r[qno-1];i++)
                    				printf("%d ",queue[i]);
                			printf("\n");
                		}
                	} 
                }else if(option==5){
                	qno = (firq<secq && firq<thiq && firq<fouq) ? 1 :((secq<thiq && secq<fouq) ? 2 :(thiq<fouq ? 3 : 4));
                	reply=delq(queue,qno-1,f,r,&data);
                	if(reply==-1)
                    		printf("\nQueue %d is Empty \n",qno);
                	else
                    		printf("\n%d is deleted from Queue No - %d \n", data, qno);
           	}else if(option==6){
			qno = (firq>secq && firq>thiq && firq>fouq) ? 1 :((secq>thiq && secq>fouq) ? 2 :(thiq>fouq ? 3 : 4));
                	printf("\nEnter Data: ");
                	scanf("%d",&data);
                	reply = insq(queue,qno-1,r,limit,&data);
                	if(reply==-1)
                    		printf("\nQueue %d is Full \n",qno);
                	else
                    		printf("\n %d is inserted in queue number - %d \n",data,qno);
           	}else if(option==7){
                	exit (0);
            	}else
                	printf("\nInvalid Choice.TRY AGAIN\n");
        }
}
