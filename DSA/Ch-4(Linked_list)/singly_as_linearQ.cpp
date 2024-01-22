#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};
// node *head=NULL;
// node *temp=NULL;

class linked_list
{
private:
    int front,rear;
public:
    linked_list()
    {
        front =0;
        rear = -1;
        *head= NULL;
    }

    void add_node(int n)
    {
        node *newNode = new node;
        node *temp=head;
        newNode->data = n;
     //no need to check for full condn as
     //our list is dynamic so wont get full
        if(rear ==-1)
        {
            newNode->next = NULL;
            head=newNode;
        }
        else
        {
            while (temp->next !=NULL)
            {
                /* code */
            }
            
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    return 0;
}