//bubble sort
#include<iostream>
using namespace std;
int i,j;
int main()
{
    void enter(int*,int);
    void sort(int*,int);
    void print(int*,int);
    int n;
    cout<<"\nEnter no. of data:";
    cin>>n;

    int* arr = new int[n-1];
    enter(arr,n-1);
    cout<<"\nData before sorting:\n";
    print(arr,n-1);
    
    sort(arr,n-1);
    cout<<"\nData after sorting:\n";
    print(arr,n-1);
 return 0;
}

void enter(int* a,int s){
    for(i=0;i<=s;i++){
        cout<<"\nEnter A["<<i<<"]: ";
        cin>>a[i];
    }
}

void sort(int* a,int s){
    int temp;
    for ( i = 0; i <=s; i++)
    {
        for ( j = i+1; j <=s; j++)
        {
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        
    }
}

void print(int* a,int s){
    for(i=0;i<=s;i++)
        cout<<a[i]<<"\t";
}