#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k;
    cout<<"\nEnter order of matrix:";
    cin>>n;
    float A[n+1][n+1],temp;
    float B[n+1][n+1];//identity matrix
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            cout<<"\nEnter element A["<<i<<"]["<<j<<"]: ";
            cin>>A[i][j];
        }
    }
    
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            if (i==j)
                B[i][j]=1;
            else
                B[i][j]=0;
                      
        }
    }
   for(i=1;i<n+1;i++){
    if (A[i][i]==0)
        {
            cout<<"\nEnter the values again without 0 in diagonal element";
            return -1;
        }
        for(j=1;j<n+1;j++){
            if(i!=j){
                temp=A[j][i]/A[i][i];
                for(k=1;k<n+1;k++)
                {
                    
                    A[j][k]=A[j][k]-temp*A[i][k];
                    B[j][k]=B[j][k]-temp*A[i][k];
                    
                }
            }
            
        }
    }
    cout<<"\nInverse matrix is";
    for(i=1;i<n+1;i++){
        cout<<"\n";
        for (j = 1; j<n+1; j++)
        {
            cout<<B[i][j]/A[i][i]<<"\t";
        }
        
    }

 return 0;
}