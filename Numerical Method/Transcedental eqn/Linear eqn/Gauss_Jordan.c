#include<stdio.h>
#include<conio.h>
#define SIZE 10

int main()
{
	float a[SIZE][SIZE],ratio;
	int i,j,k,n;
		
		 printf("Enter number of unknowns: ");
		 scanf("%d", &n);
		
        here:		 
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n+1;j++)
			  {
				printf("\nEnter element a[%d][%d] = ",i,j);
				scanf("%f", &a[i][j]);
			  }
		 }
		
		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("\nEnter the values again without 0 in diagonal element");
				   goto here;
              }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=n+1;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 
         printf("\nSolution:\n");
		 for(i=1;i<=n;i++)
		 {
		  	printf("x[%d] = %0.3f\n",i,a[i][n+1]/a[i][i]);
		 }
		
 return(0);
}