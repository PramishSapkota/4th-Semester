//For Newton Raphson Method
#include<iostream>
#include<math.h>
using namespace std;

float a,b,E;
int count=0;
float f(float x)
{
    return sin(x)-exp(x);
    
}

float f_(float x)
{
    return cos(x)-exp(x);
    
}

int main()
{
    cout<<"\nEnter a:";
    cin>>a;
    cout<<"\nEnter Tolerable error:";
    cin>>E;
    do
    {
        if (fabs(f_(a))<E){
            cout<<"Mathematical Error";
            return -1;
        }
        else {
            b=a-f(a)/f_(a);
            a=b;
            count++;
            if (count>500){
                cout<<"\n Solution doesnt exist";
                return -1;
            }
        }
    } while (fabs(f(b))>=E);
    
    cout<<b;
 return 0;
}