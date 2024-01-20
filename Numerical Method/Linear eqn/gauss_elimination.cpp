#include<iostream>
#include<iomanip>
using namespace std;

int i,j,k;

int main(){
    int n,pre;   
    cout<<"\nEnter no. of unknowns";
    cin>>n;
    cout<<"\nEnter the precision in whole number:";
    cin>>pre;
    float A[n+1][n+2],temp,x[n+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            cout<<"\nEnter element A["<<i<<"]["<<j<<"]: ";
            cin>>A[i][j];
        }
    }
    //upper triangle
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n + 1; j++) {
            if (i != j) {
                temp = A[j][i] / A[i][i];
                for (k = 1; k <= n + 1; k++) {
                    A[j][k] -= temp * A[i][k];
                }
            }
        }
    }

    // Back-substitution
    for (i = n; i >= 1; i--) {
        x[i] = A[i][n + 1];
        if(A[i][i]==0){
            cout<<"Error can't divide by zero";
            return -1;
        }
        for (j = i + 1; j <= n; j++)
            x[i] -= A[i][j] * x[j];
        x[i] = x[i] / A[i][i];
    }

    cout << "\nSolution is:\n";
    for (i = 1; i <= n; i++)
        cout <<setprecision(pre) <<"x" << i << "= " << x[i] << endl;
    
     
 return 0;
}