//singly linked list as linear queue
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head=NULL;
// node *temp=NULL;

class linked_list
{
 public:
    ~linked_list(){//destructor
        node* current = head;
        node* next;
		while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }
    void enq(int n)
    {
        node *newNode = new node;
        node *temp=head;
        newNode->data = n;
     //no need to check for full condn as
     //our list is dynamic so wont get full
        if(head==NULL)
        {
            newNode->next = NULL;
            head=newNode;
        }
        else
        {
            while (temp->next !=NULL)
                temp=temp->next;
            
            temp->next=newNode;
            newNode->next=NULL;
        }
    }
    void dq(){
        if (head==NULL)
        {
            cout<<"\nQueue is empty";
            return;
        }
        else{
            temp=head;
            cout<<"\nData="<< head->data;
            head=head->next;
            delete temp;
        }
    }
    void traverse(){
        node *temp=head;
        if (head==NULL)
        {
            cout<<"\nQueue is empty";
            return;
        }
        else{
            while (temp !=NULL)
            {
                cout<<"\n"<<temp->data;
                temp=temp->next;
            }
        }
    }
};

int main()
{
    linked_list a;
    int choice,c=1,value;
    do
    {
       cout<<"\n\n1:Enqueue\n2:Dequeue\n3:Traverse";
       cout<<"\n4:Exit\nEnter your choice:";
       cin>>choice;
       switch (choice)
       {
       case 1:
            cout<<"Enter data: ";
            cin>>value;
            a.enq(value);
        break;

        case 2:
            a.dq();
        break;

        case 3:
            a.traverse();
            break;
        case 4:
            c=0;
        break;
       
       default:
            cout<<"\nInvalid input";
        break;
       }
    } while (c);
 return 0;
}