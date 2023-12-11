#include<iostream>
#define size 5
using namespace std;

class Stack{
    int top,A[size];
 public:
    Stack():top(-1){}
    
    void display();
    void push(){
        int data;
        if (top==size-1)
            cout<<"Stack is Full";
         else{
            cout<<"\n Enter the element:";
            cin>>A[++top];
        }   
    }
    void pop();
};
void Stack::pop(){
    if (top==-1)
        cout<<"\n Stack is empty";
    else
        cout<<"\n Popped value="<<A[top--];
}
int main()
{
    int choice;
    Stack *s=new Stack;
    int flag=1;
    do
    {
        cout << "\n\t-------------";
        cout << "\n 1:Push";
        cout << "\n 2:Pop";
        cout << "\n 3:Display"; // to see all elements in stack
        cout << "\n 4:Exit";
        cout << "\n Enter your choice:";
        cin >> choice;
        switch (choice)
        {
         case 1:
            s->push();
            break;

         case 2:
            s->pop();
            break;
        
         case 3:
            s->display();
            break;
        
         case 4:
            flag=0;
            break;
        
         default:
            cout << "\n Invalid Choice";
            cout << "\n Press 4 to exit";
            break;
        }
    } while (flag);
     
    delete s;
    
 return 0;
}
void Stack::display(){
    if (top==-1)
        cout<<"\n No items to be displayed";
    else{
        for (int i = top- 1; i >= 0; i--)
        {
            cout<<"\t"<<A[i];
        }
        
    }    
}