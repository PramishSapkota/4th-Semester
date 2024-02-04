#include<iostream>
#include<iomanip>
using namespace std;
int i;

void getData(float*A,int n){
    for ( i = 0; i < n; i++){
        cout<<"\n Enter y"<<i<<":";
        cin>>A[i];
    }
}

void trapezoidal(float*y,int n){
    float a,b,h;
    int s;
    cout<<"\nEnter upper bound:";
    cin>>b;
    cout<<"\nEnter lower bound:";
    cin>>a;
    cout<<"\nEnter no of steps:";
    cin>>s;
    h=(b-a)/s;
    cout<<"\nh="<<h;
    float temp=0,result=0;
    for ( i = 1; i <n-1; i++)
    {
        temp+=y[i];
    }
    result=h*(y[0]+y[n-1]+2*temp)/2;

    cout<<"\nIntegration="<<setprecision(4)<<result;

}
int main()
{
    int n;
    cout<<"Enter no of data:";
    cin>>n;
    float *A=new float[n];
    getData(A,n);

    trapezoidal(A,n);

 return 0;
}