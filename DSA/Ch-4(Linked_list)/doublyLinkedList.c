//doubly linked list implementation
#include<stdio.h>
#include<stdlib.h>

int i,data;
struct doubly
{
    struct doubly* next;
    struct doubly* prev;
    int info;
};
typedef struct doubly Nodetype;
Nodetype *head=NULL;
Nodetype *temp=NULL;//this works

void Display();
void insertFront(int data) {
    Nodetype *newdoubly = (Nodetype*)malloc(sizeof(Nodetype));
    if(head==NULL){
        newdoubly->info = data;
        newdoubly->next = NULL;
        newdoubly->prev = NULL;
        head=newdoubly;
        printf("\nData was inserted at 1st successfully");
    }
    else{
        newdoubly->info = data;
        newdoubly->next = head;
        newdoubly->prev = NULL;
        head->prev=newdoubly;
        head=newdoubly;
    }
        
}

void insertAt(int p){
    Nodetype *newdoubly = (Nodetype*)malloc(sizeof(Nodetype));
    //Nodetype *temp;
    temp=head;
    for(i=0;i<p;i++)
        temp=temp->next;
    if (temp != NULL)
    {
        printf("\nEnter data:");
        scanf("%d",&data);
        newdoubly->info=data;
        newdoubly->next=temp;
        newdoubly->prev=temp->prev;
        temp->prev=newdoubly; 
    }
    else
        printf("\nInvalid position");  
}

void deleteFront(){
    Nodetype *temp;
    if(head != NULL){
        temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        free(temp);
    }
    else
        printf("\nList is empty");
}
void insertLast(){
    if (head == NULL)
        printf("\nList wasnt found");
    else{
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;
        printf("\nEnter data:");
        scanf("%d",&data);
        Nodetype *newdoubly = (Nodetype*)malloc(sizeof(Nodetype));
        newdoubly->info=data;
        newdoubly->prev=temp;
        newdoubly->next=NULL;
        temp->next=newdoubly;

    }
}
void deleteAt(int p){
    temp=head;
    Nodetype *temp1,*temp2;
    for(i=0;i<p;i++)
        
        temp=temp->next;

    if (temp != NULL){
        temp1=temp->prev;
        temp2=temp->next;
        temp1->next=temp2;
        temp2->prev=temp1;
        free(temp);
    }
    else
        printf("\nError");
}

void deleteLast(){
     if (head == NULL)
        printf("\nList wasnt found");
    else{
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->prev->next=NULL;
        free(temp);
    }
}
    

int main(){
    int choice,k,a=1;
    do{
        printf("\n\n1:Enter element at first");
        printf("\n2:Enter element at kth position");
        printf("\n3:Enter element at last");
        printf("\n4:Delete element at first");
        printf("\n5:Delete element at kth position");
        printf("\n6:Delete element at last");
        printf("\n7:Display");
        printf("\n8:Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d",&data);
            insertFront(data);
            break;
        
        case 2:
            printf("\nEnter position:");
            scanf("%d",&k);
            insertAt(k);
            break;

        case 3:
            insertLast();
            break;

        case 4:
            deleteFront();
            break;

        case 5:
            printf("\nEnter position:");
            scanf("%d",&k);
            deleteAt(k);
            break;
        
        case 6:
            deleteLast();
            break;

        case 7:
            Display();
            break;
        case 8:
            a=0;
            break;
        default:
            printf("\nInvalid input");
            break;
        }
    }while (a);
 return 0;
}

void Display(){
    Nodetype *temp = head;
    // Check for empty list. 
    if (head == NULL) { 
    	printf("List empty\n"); 
    	return;//bcz its void type the return 
    } 		 //statement will exit this function
    // Traverse the list 
    while (temp != NULL) { 
    	printf(%d"\t",temp->data); 
    	temp = temp->next; 
    } 
} 