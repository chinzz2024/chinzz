
   
    	#include<stdio.h>
struct process
{
    int id,AT,BT,WT,TAT,CT;
};
struct process a[10];
int queue[100];
int front=-1;
int rear=-1;

void insert(int n)
{
	if(front==-1)
		front=0;
	rear=rear+1;
    	queue[rear]=n;
}

int delete()
{
	int n;
    	n=queue[front];
    	front=front+1;
    	return n;
}
int main()
{
	int n,TQ,p,TIME=0;
    	int temp[10],exist[10]={0};
    	float total_wt=0,total_tat=0,Avg_WT,Avg_TAT;
    	printf("Enter the number of the process\n");
    	scanf("%d",&n);
    	printf("Enter the arrival time and burst time of the process\n");
    	printf("AT BT\n");
    	for(int i=0;i<n;i++)
    	{
        	scanf("%d%d",&a[i].AT,&a[i].BT);
        	a[i].id=i;
        	temp[i]=a[i].BT;
    	}
    	printf("Enter the time slice\n");
    	scanf("%d",&TQ);
   
    	insert(0);
    	exist[0]=1;
    	int maxp=0;
    	int z=1;
    	while(front<=rear)
    	{
    		p=delete();
    		if(p>maxp)
    			maxp=p;
        	if(a[p].BT>=TQ)
        	{
            		a[p].BT=a[p].BT-TQ;
            		TIME=TIME+TQ;
        	}
        	else
        	{
            		TIME=TIME+a[p].BT;
            		a[p].BT=0;
        	}
        
		
        	for(int i=0;i<n;i++)
        	{
            		if(exist[i]==0 && a[i].AT<=TIME)
            		{
                		insert(i);
                		exist[i]=1;
                		z++;
            		}
        	}
        	if(a[p].BT==0)
        	{
	    		a[p].CT=TIME;
            		a[p].TAT=TIME-a[p].AT;
            		a[p].WT=a[p].TAT-temp[p];
            		total_tat=total_tat+a[p].TAT;
            		total_wt=total_wt+a[p].WT;
        	}
        	else
        	{
            		insert(p);
        	}
        	if (maxp<n-1)
        	{if(front > rear && z!=n)
        	
       		{	
			TIME=a[maxp+1].AT;
			insert(maxp+1);
			exist[maxp+1]=1;
		}
		}
    	}    
    	Avg_TAT=total_tat/n;
    	Avg_WT=total_wt/n;
    	printf("ID AT BT CT WT TAT\n");
    	for(int i=0;i<n;i++)
    	{
        	printf("%d  %d  %d  %d  %d  %d \n",a[i].id,a[i].AT,temp[i],a[i].CT,a[i].WT,a[i].TAT);
    	}
   	printf("Average waiting time of the processes is : %f\n",Avg_WT);
    	printf("Average turn around time of the processes is : %f\n",Avg_TAT);
    	return 0;
}

