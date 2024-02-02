#include<iostream>
using namespace std;


int main()
{
    int n,i,j,k;
    cout<<"Enter no. of unknowns:";
    cin>>n;
    float A[n+1][n+2],temp;
    here:
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            cout<<"\nEnter element A["<<i<<"]["<<j<<"]: ";
            cin>>A[i][j];
        }
    }
     
    for(i=1;i<=n;i++){
        if (A[i][i]==0)
        {
            cout<<"\nEnter the values again without 0 in diagonal element";
            goto here;
        }
        
        for(j=1;j<=n+1;j++){
            if(i!=j){
                temp=A[j][i]/A[i][i];
                for(k=1;k<=n+1;k++)
                    
                    A[j][k]=A[j][k]-temp*A[i][k];
            }
            
        }
    }
    cout<<"\nSolution is";
    for(i=1;i<n+1;i++){
        cout<<"\nx"<<i<<"="<<A[i][n+1]/A[i][i];
    }
    
 return 0;
}