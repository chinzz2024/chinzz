#include <stdio.h> 
int main() 
{ 
	

	int n, m, i, j, k, y,alloc[20][20],max[20][20],avail[50],ind=0; 
 printf("Enter the no of Proceses:");
 scanf("%d",&n);
 printf("Enter the no of Resources:");
 scanf("%d",&m);
 printf("Enter the Allocation Matrix:");
 for (i = 0; i < n; i++) {
 	for (j = 0; j < m; j++)
 		{scanf("%d",&alloc[i][j]);
 		}
 		printf("\n");
 }
 printf("Enter the Max Matrix:");
 for (i = 0; i < n; i++) {
 		for (j = 0; j < m; j++)
 		{	scanf("%d",&max[i][j]);
 			}
 			printf("\n");
 }
printf("Enter the Available Matrix");
 for(i=0;i<m;i++)
 	scanf("%d",&avail[i]);
	
	
	int f[n], ans[n]; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	printf("THE NEED MATRIX IS \n");
	for (i = 0; i < n; i++) 
		{for (j = 0; j < m; j++) 
			{printf("%d   ",need[i][j]);}
			printf("\n\n");
			} 
	
	int rem=n; 
	while(rem>0) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1;
					rem--; 
				} 
			} 
		} 
	} 

	printf("The SAFE Sequence is as follows\n"); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[n - 1]); 

	return (0); 

} 

