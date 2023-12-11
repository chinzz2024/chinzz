#include<stdio.h>


void waittime(int process[],int n,int bt[],int wt[],int tat[]);
void avgtime(int process[],int n,int bt[],int prio[]);

void main()
{	int n,temp;
	int process[10],bt[10],prio[10];
	printf("enter number of process :");
	scanf("%d",&n);
	printf("enter the burst time of the processes\n");
	for(int i=0;i<n;i++)
	{
		printf("process %d :",i+1);
		process[i]=i+1;
		printf("burst:");
		scanf("%d",&bt[i]);
		printf("priority:");
		scanf("%d",&prio[i]);
	}
	
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(prio[j]>prio[j+1])
			{
				temp=prio[j];
				prio[j]=prio[j+1];
				prio[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
				
			}
		}
	}
	avgtime(process,n,bt,prio);
}

void waittime(int process[],int n,int bt[],int wt[],int tat[])
{
	int i;
	wt[0]=tat[0]=0;
	tat[0]=wt[0]+bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=wt[i]+bt[i];
	}
}

void avgtime(int process[],int n,int bt[],int prio[])
{
	int wt[n],tat[n],i,totwt=0,tottat=0;
	float avgwt,avgtat;
	waittime(process,n,bt,wt,tat);
	printf("\n\tprocess\tbt\twt\ttat\tpriority");
	for(i=0;i<n;i++)
	{
		totwt+=wt[i];
		tottat+=tat[i];
		printf("\n\t%d\t%d\t%d\t%d\t%d",process[i],bt[i],wt[i],tat[i],prio[i]);
		
	}
	
	avgwt=(float)totwt/n;
	avgtat=(float)tottat/n;
	printf("\naverage waiting time=%.2f",avgwt);
	printf("\naverage turnaround time=%.2f\n",avgtat);
	
}

