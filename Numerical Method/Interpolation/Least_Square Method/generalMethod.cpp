//code for general method of interpolation of nth degree
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
int i,j;

void gaussJordan(double **,int);
void print(double **,int);

void dataEnter(float *a,float *b,int n){
    for ( i = 0; i < n; i++){
        cout<<"\n\n Enter x"<<i<<":";
        cin>>a[i];
        cout<<"\n Enter y"<<i<<":";
        cin>>b[i];
    }
}
/*
double summation_x(float *x,int n,int p){//n=size ofx p=power
    double v=0;
    for ( i = 0; i < n; i++)
        v+=pow(x[i],p);
 return v;
}

double summation_xy(float *x,float *y,int p,int n){
    double v=0;
    for ( i = 0; i < n; i++)
        v+=pow(x[i],p)*y[i];
 return v;
}

void value(double **A,float *x,float *y,int n,int d){
    for ( i = 0; i < d; i++)
    {
        A[i][d]=summation_xy(x,y,i,n);
        for ( j = 0; j < d; j++)
            A[i][j]=summation_x(x,n,i+j);
    }
}
/*/
void value(double**matrix,float *x,float*y,int size,int degree){
   for(int i=0;i<degree;i++){
      for(int j=0;j<degree;j++){
         matrix[i][j]=0;
        for(int k=0;k<size;k++){
            matrix[i][j]=matrix[i][j]+pow(x[k],i+j);
        }
     }
   }
    for(int i=0;i<degree;i++){
    
     for(int k=0;k<size;k++)
        matrix[i][degree]+=pow(x[k],i)*y[k];
     
    }
}
//*/
void cleanup(double **A, int n) {
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}

int main(){
    int n,d;
    cout<<"\nEnter degree:";
    cin>>d;
    cout<<"\nEnter no. of data:";
    cin>>n;
    
    float *x=new float [n];
    float *y=new float [n];
    dataEnter(x,y,n);

    double **A=new double* [d+1];
    for ( i = 0; i < d+1; i++)
        A[i]= new double [d+2];
    
    value(A,x,y,n,d+1);
    cout<<"\n Augmented matrix is:";
    print(A,d+1);

    gaussJordan(A,d+1);
    cleanup(A,d+1);
    delete[] x;
    delete[] y;
 return 0;   
}

void print(double **A,int n){
    for ( i = 0; i < n; i++)
    {   cout<<"\n";
        for ( j = 0; j < n+1; j++)
        
            cout<<setprecision(4)<<A[i][j]<<"\t";
    }
}

void gaussJordan(double **A,int n){
    double temp;
    int k;
    for(i=0;i<n;i++){
        if (A[i][i]==0){
            cout<<"\n Cannot divide by 0.Program terminating";
            cleanup(A, n);
            return;
        }
        for(j=0;j<n;j++){
            if(j!=i)
            {
                temp=A[j][i]/A[i][i];
                for(k=0;k<n+1;k++)
                    A[j][k]=A[j][k]-temp*A[i][k];
            }
        }
    }
    cout<<"\n\nCurve is:";
    for (i = 0; i < n; i++) {
        
        cout  <<setprecision(5) << A[i][n] / A[i][i]<< " x^" << i<<"+";
    }
    cout<<"0";
}