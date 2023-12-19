#include<iostream>
#include<math.h>
// #include<cstdlib> //for exit -1
//#define f(x) (cos(x)-x*exp(x))
using namespace std;

float f(float x)
{
    return cos(x)-x*exp(x);
}


int main()
{
    float a,b;
    here:
    //Enter Guesses
    cout<<"\nEnter a:";
    cin>>a;
    cout<<"\nEnter b:";
    cin>>b;
    if(f(a)*f(b)>0)
        { 
            cout<<"\n Initial Guesses are wrong";
            cout<<"\n Try again with another guesses";
            goto here;
        
        }
    else if (f(a)*f(b)==00)
        {
            if (f(a)==0)
                cout<<"\n Required value="<<a;
            
            if (f(b)==0)
                cout<<"\n Required value="<<b;
        }
    else
    {
        float E,n,c;
        int count=0;
        cout<<"\n Enter tolerable error:";
        cin>>E;
        n=(log(fabs(b-a))-log (E))/log(2);
        
        cout << endl << "n=" << n << endl;
        do
        {
            c=(a+b)/2;
            if (f(c)*f(a)<0)
                b=c;
            else 
                a=c;
            count++;
            if(count>(2*n))
            {
                cout<<"disContinous";
                return (-1);
            }
        } while (fabs(f(c))>E);
        cout<<"\n Soln is:"<<c<<endl;
        cout<<"Steps="<<count;
        
    }
    
 return 0;
}