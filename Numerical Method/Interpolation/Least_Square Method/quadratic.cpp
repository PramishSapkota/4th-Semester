//least square method for quadratic interpolation
// #include <iomanip>
#include <iostream>
#include<cmath>
using namespace std;
int i;

void GaussJordan(float **A,int n){
    float temp;
    float *val=new float(n);
    int j,k;
    for(i=0;i<n;i++){
        if (A[i][i]==0){
            cout<<"\n Cannot divide by 0.Program terminating";
            return;
        }
        for(j=0;j<n+1 && j!=i;j++){
            //if(j!=i)
            {
                temp=A[j][i]/A[i][i];
                for(k=1;k<=n+1;k++)
                    A[j][k]=A[j][k]-temp*A[i][k];
            }
            
        }
    }
    
    for(i=1;i<n+1;i++){
        val[i]=A[i][n+1]/A[i][i];
    }
    cout<<"\nEquation is:\n"
    cout<<val[0]<<"x^2+"<<val[1]<<"x+"<<val[2];

    delete[] val;
}
void dataEnter(float *a,float *b,int n){
    for ( i = 0; i < n; i++)
    {
        cout<<"\n Enter (x,y):";
        cin>>a[i]>>b[i];
    }
}

int main(){
    int n;
    cout<<"\nEnter no. of data:";
    cin>>n;
    float *x=new float(n);
    float *y=new float(n);
    dataEnter(x,y,n);

    void leastSquare(float*,float*,int);
    leastSquare(x,y,n);

    
    //deallocation
    delete[] x;
    delete[] y;

 return 0;   
}

void leastSquare(float *x,float *y,int n){
    float sum_x=0,x2=0,x3=0,x4=0,xy=0,sum_y=0,x2y=0;
    for ( i = 0; i < n; i++)
    {
        sum_x+=x[i];
        x2+=x[i]*x[i];
        x3+=pow(x[i],3);
        x4+=pow(x[i],4);
        xy+=x[i]*y[i];
        sum_y+=y[i];
        x2y+=x[i]*x[i]*y[i];
        
        //dynamic allocation of 2d array
        float **A=new float* [3];//only creates rows
        for ( i = 0; i < n; i++)
            A[i]= new float [4];//creates columns
        /*adding data
     our normal equations are:  "Note:'[ ]' denotes summation"
        
        a[x^2]+b[x]+cn=[y]
        a[x^3]+b[x^2]+c[x]=[xy]
        a[x^4]+b[x^3]+c[x^2]=[x^(2)*y]
     */
        A[0][0]=x2; A[0][1]=sum_x;  A[0][2]=n ;     A[0][3]=sum_y;
        A[1][0]=x3; A[1][1]=x2;     A[1][2]=sum_x;  A[1][3]=xy;
        A[2][0]=x4; A[2][1]=x3;     A[2][2]=x2;     A[2][3]=x2y;
    
        GaussJordan(A,3);
        //deallocation of 2d array
        for ( i = 0; i < n; i++)
            delete[] A[i];
        delete[] A;
    }

}