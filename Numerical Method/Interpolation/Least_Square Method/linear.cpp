//least square method for linear interpolation
#include <iostream>
#include<iomanip>
using namespace std;
int i;

int main(){
    int n;
    cout<<"\nEnter no. of data:";
    cin>>n;
    float *x=new float(n);
    float *y=new float(n);
    
    void dataEnter(float*,float*,int);
    dataEnter(x,y,n);
    
    void leastSquare(float*,float*,int);
    leastSquare(x,y,n);
    //deallocation
    delete[] x;
    delete[] y;
 
 return 0;
}

void dataEnter(float *a,float *b,int n){
    for ( i = 0; i < n; i++)
    {
        cout<<"\n Enter x"<<i;
        cin>>a[i];
        cout<<"\nEnter y"<<i;
        cin>>b[i];
    }
}

void leastSquare(float *x,float *y,int n){
    float sum_x=0,x2=0,xy=0,sum_y=0,det_A,det_B,det;

    for ( i = 0; i < n; i++)
    {
        sum_x+=x[i];
        x2+=x[i]*x[i];
        xy+=x[i]*y[i];
        sum_y+=y[i];
    }
 //let our soln be of form y=ax+b
    //using cramers rule
    det_A=sum_y*sum_x- xy*n;
    det_B=xy*sum_x- x2*sum_y;
    det=sum_x*sum_x- x2*n;
    cout<<"\nInterpolated Equation is:\n";
    cout<<setprecision(4)<<det_A/det<<"x+"<<setprecision(4)<<det_B/det;
    
}