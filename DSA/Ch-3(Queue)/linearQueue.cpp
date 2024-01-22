#include<iostream>
#define size 10
using namespace std;

class Queue
{
 private:
    int front,rear,Q[size];
        
 public:
    Queue(){
        front=0;
        rear=-1;
    }
    void enqueue(){
        if (rear==size-1)
            cout<<"\nQueue is full";
        else{
            cout<<"\nEnter data:";
            cin>>Q[++rear];
        }
    }
    void dequeue(){
        if (rear<front)
            cout<<"\nQueue is empty";
        else
            cout<<"\nData="<<Q[front++];
    }
    void traverse(){
        if (rear<front)
            cout<<"\nQueue is empty";
        for(int i=front;i<=rear;i++)
            cout<<"\t"<<Q[i];
    }

};

int main()
{
    Queue *u=new Queue;
    int choice,flag=1;
    do
    {
        cout << "\n\n 1:Enqueue";
        cout << "\n 2:Dequeue";
        cout << "\n 3:Traverse";
        cout<<"\n 4:Exit";
        cout << "\n Enter your choice:";
        cin >> choice;
        switch (choice)
        {
         case 1:
            u->enqueue();
            break;

         case 2:
            u->dequeue();
            break;
            
         case 3:
            u->traverse();
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
    
    delete u;

 return 0;
}