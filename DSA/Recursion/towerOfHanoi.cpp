#include <iostream>
using namespace std;

void towers(int,char,char,char);
int count=0;//counter for number of steps

int main(){
    int n;
    cout<<"\nEnter number of disks:";
    cin>>n;
    towers(n,'A','C','B');
    cout<<"\n\n Total no. of steps="<<count;
 return 0;
}

void towers(int n,char source,char dest,char aux){
    if(n==1){
        cout<<"\nMove disc 1 from "<<source<<" to "<<dest;
        count++;
        return;
    }
    
    count++;

    //n-1 to auxilary
    towers(n-1,source,aux,dest);
    cout<<"\nMove disc "<<n<<" from "<<source<<" to "<<dest;
    
    //n-1 from auxillary to destination
    towers(n-1,aux,dest,source);
    return;
}