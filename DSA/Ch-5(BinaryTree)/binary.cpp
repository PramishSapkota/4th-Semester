#include<iostream>
using namespace std;

class Node
{
 private:
        int item;
        Node *left,*right;
 public:
    Node(){left=NULL;
    right=NULL;}
     Node(int data){
        this->item=data;
        this->left=NULL;
        this->right= NULL;
    } 
    // Node(Node* p,int data ) {
    //     if(p==NULL)
    //         Node(data);
    //     else{
    //         if()
    //     }
    //}
};

class Tree{
    
 public:
    Node* root;
    Tree():root(NULL){}
    void insert(Node* p,int data ) {
        if(p==NULL)
            Node(data);
            root=p;
            cout<<"done";
        // else{
        //     if()
        // }
    }
    ~Tree(){//for cleanup

    }
};

int main()
{
    Tree t;
    t.insert(root,5);
 return 0;
}