//program to evaluate postfix expression
#include<iostream>
#include<math.h>
#include<ctype.h>//for testing and manipulating character
using namespace std;

int vstack[100],tos=-1;
void push(int);
int pop();

int main()
{
    int l,i,value[100];
    char ch;
    float a,b;
    string inf;
    cout<<"\n Enter a valid postfix expression: ";
    cin>>inf;
    l=inf.size();
    for ( i = 0; i < l; i++)
    {
        if(isalpha(inf[i])){
            cout<<"\nEnter value of "<<inf[i]<<": ";
            cin>>value[i];
            push(value[i]);
        }   
        else{
            b=pop();
            a=pop();
            switch (inf[i])
            {
                case '+':
                    push(a+b);
                    break;
                
                case '-':
                    push(a-b);
                    break;
                
                case '*':
                    push(a*b);
                    break;

                case '/':
                    push(a/b);
                    break;

                case '$':
                case '^':
                    push(pow(a,b));
                    break;
                default:
                    cout<<"Invalid Symbol";
                    break;
            }
        }
    }
    cout<<"\n\nResult="<<pop();
 return 0;
}

void push(int d){
    vstack[++tos]=d;
}

int pop(){
    return vstack[tos--];
}