#include<iostream>
#include<math.h>
using namespace std;

int count=0;
float e,c,a,b;
float f(float x)
{
    return cos(x)-x*exp(x);
    // return(1/(x-2));// for a case
    
}

int main(){
    cout<<"\nEnter a:";
    cin>>a;
    cout<<"\nEnter b:";
    cin>>b;
    cout<<"\nEnter Tolerable error:";
    cin>>e;
    do
    {
        if (fabs(f(a)-f(b))<e){
            cout<<"Error";
            return -1;
        }
        else{
            c=(a*f(b)-b*f(a))/(f(b)-f(a));
            a=b;
            b=c;
            count++;
            if (count>500){
                cout<<"\n Solution doesnt exist";
                return -1;
            }
        }
    } while (fabs(f(c))>e);
    
    cout<<"Solution is:"<<c;
    
 return 0;
}
