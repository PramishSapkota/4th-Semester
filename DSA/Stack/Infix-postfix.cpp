//infix to postfix conversion
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
        //cout<<"Error =(";
        return 0;//this doesnt terminate the program
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
    for ( i = 0; i <len; i++)
    {
        if(ip[i]=='('){
            
            ostack[++otop]=ip[i];
            
        }
        else if(isalpha(ip[i])){
            
            pstack[++ptop]=ip[i];
            
        }
        else if(ip[i]==')')
        {
            while (otop >= 0 && ostack[otop] != '(')
            { /*otop>=0 for expressions like: a+b*c)i.e if'(' isnt in front
               and to check if operator stack i sempty or not*/
                pstack[++ptop] = ostack[otop--];
                
            }
            if (otop >= 0 && ostack[otop] == '(')
                otop--;
            else
            {
                cout<<"Invalid expression\n";
                return -1;
            }
        }
        else{
            while (otop>=0 && precedenceCheck(ostack[otop])>=precedenceCheck(ip[i])){
              
                pstack[++ptop] = ostack[otop--];
            }
            ostack[++otop]=ip[i];
        }
    }
    while (otop >= 0) {
        pstack[++ptop] = ostack[otop--];
    }
    cout << "Postfix expression: ";
    for (i = 0; i <= ptop; i++)
        cout << pstack[i];

    return 0;
}