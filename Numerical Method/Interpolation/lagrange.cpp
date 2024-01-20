//Lagrange intrepolation program
#include<iostream>
using namespace std;
int i,j;

void dataEnter(float *a,float *b,int n){
    for ( i = 0; i < n; i++)
    {
        cout<<"\n Enter x"<<i<<": ";
        cin>>a[i];
        cout<<"\n Enter y"<<i<<": ";
        cin>>b[i];
    }
}

void interpolation(float *x,float *y,int data){
    float tmp,u;
    cout<<"\n Enter value to be interpolated:";
    cin>>u;
    int result=0;
    for ( i = 0; i <data; i++)
    {
        tmp=1;
        for ( j = 0; j < data &&j!=i; j++)
        {
            // if(j!=i)
                tmp*=(u-x[j])/(x[i]-x[j]);
        }
        result+=tmp*y[i];
    }

    cout<<"Value="<<result;
}

int main(){
    
   int data;
    cout<<"\n Enter no. of data: ";
    cin>>data;
    float *x=new float(data);
    float *y=new float(data);
    
    dataEnter(x,y,data);
    
    interpolation(x,y,data);
    
    
    // Deallocate dynamically allocated memory
    delete[] x;
    delete[] y;

 return 0;
}