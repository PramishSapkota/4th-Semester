#include<iostream>
using namespace std;

int main()
{
    int n;
    here:
    cout<<"\n Enter a number:";
    cin>>n;
    if (n<0){
        cout<<"\nEnter a positive number or a zero";
        goto here;
    }
    
    //declaring factorial function
    double fact(int);
    
    // o/p in factorial notation
    cout<<"\n"<<n<<"!="<<fact(n);
    
    // cout<<"\nFactorial="<<fact(n);

 return 0;
}

double fact(int n){
    if (n == 0 || n == 1)//0!=1
        return 1;
    return n * fact(n - 1);
}