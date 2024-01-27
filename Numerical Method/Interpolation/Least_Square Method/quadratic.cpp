//least square method for linear interpolation
#include <iostream>
using namespace std;
int i,j;

void dataEnter(float *a,float *b,int n){
    for ( i = 0; i < n; i++)
    {
        cout<<"\n Enter (x,y):";
        cin>>a[i];
        cin>>b[i];
    }
}