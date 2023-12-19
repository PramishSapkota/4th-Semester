#include<iostream>
#include<ctype.h>
#define ssize 50
#define psize 50
using namespace std;

int precedenceCheck(char c){
    switch (c)
    {
    case '^':
    case '$':
        return 3;
        break;

    case '*':
    case '/':
        return 2;
        break;

    case '+':
    case '-':
        return 1;
        break;
    
    default:
        cout<<"Error =(";
        return -1;
        break;
    }
}

int main(){
    char ostack[ssize],pstack[psize];
    int i,j,otop=-1,ptop=-1,len,l;
    string ip;
    cout<<"Enter infix expression: ";
    cin>>ip;
    len=ip.size();
    l=len;
    for ( i = 0; i <len; i++)
    {
        if(ip[i]=='('){
            ostack[++otop]=ip[i];
            l++;
        }
        else if(isalpha(ip[i])){
            pstack[++ptop]=ip[i];
            l++;
        }
        else if(ip[i]==')')
        {
            l++;
            while (otop >= 0 && opstack[otop] != '(')
            {
                poststack[++ptop] = opstack[otop];
                otop--;
            }
            if (otop >= 0 && opstack[otop] == '(')
                otop--;
            else
            {
                printf("Invalid expression\n");
                return 1;
            }
        }

        
    }
    
        
    


 return 0;
}