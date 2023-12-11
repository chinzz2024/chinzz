#include<stdio.h>
int main()
{
	int i,j=0,n,a[50],frame[10],no,k,avail,count=0;
        printf("\n ENTER THE NUMBER OF PAGES:\n");
	scanf("%d",&n);
        printf("\n ENTER THE REFERENCE STRING :\n");
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("\n ENTER THE NUMBER OF FRAMES :");
        scanf("%d",&no);
	for(i=0;i<no;i++)
            frame[i]= -1;
        printf("ref\t");
        for(int i=1;i<=no;i++)
        {
        	printf("frame%d\t",i);
        }
        printf("\n");
	for(i=1;i<=n;i++)
        {
            printf("%d\t",a[i]);
            avail=0;
            for(k=0;k<no;k++)
		if(frame[k]==a[i])
                    avail=1;
                    if (avail==0)
                    {
                           frame[j]=a[i];
                           j=(j+1)%no;
                           count++;
                           for(k=0;k<no;k++)
                           {
                                  if(frame[k]!=-1)
                                  	printf("%d\t",frame[k]);
                                  else
                                  	printf("-\t");
                           }
		    }
                    printf("\n");
	}
        printf("Page Fault Is %d\n",count);
        return 0;
}

