#include<iostream>
#include<math.h>
// #include<cstdlib> //for exit -1
//#define f(x) (cos(x)-x*exp(x))//defining a function is better than macro so 
//using function bcz function is less error prone

using namespace std;

float f(float x)
{
    return cos(x)-x*exp(x);
    // return(1/(x-2));// for a discontinuous case
}


int main()
{
    float a,b;
    //Enter Guesses
    cout<<"\nEnter a:";
    cin>>a;
    cout<<"\nEnter b:";
    cin>>b;
    if(f(a)*f(b)>0)
        { 
            cout<<"\nInitial Guesses are wrong";
            cout<<"\nRun the program again with different guesses";
        
        }
    else if (f(a)*f(b)==0)
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
        
        cout <<"\n n=" << n << endl;
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