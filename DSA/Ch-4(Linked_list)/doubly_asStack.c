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
Nodetype *temp=NULL;
   
void insert(){
    Nodetype *newdoubly = (Nodetype*)malloc(sizeof(Nodetype));
    if(head==NULL){
        printf("\nEnter data:");
        scanf("%d",&data);
        newdoubly->info = data;
        newdoubly->next = NULL;
        newdoubly->prev = NULL;
        head=newdoubly;
        printf("\nData was inserted at 1st successfully");
    }
    else{
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;
        printf("\nEnter data:");
        scanf("%d",&data);
        newdoubly->info=data;
        newdoubly->prev=temp;
        newdoubly->next=NULL;
        temp->next=newdoubly;

    }
}

void delete(){
     if (head == NULL)
        printf("\nList wasnt found");
    else{
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->prev->next=NULL;
        printf("\nDeleted Value= %d",temp->info);
        free(temp);
    }
}

void Display(){
    Nodetype *temp = head; 
    if (head == NULL) { 
    	printf("List empty\n"); 
    	return;//exit(0)
    } 		 
    while (temp != NULL) { 
    	printf(%d"\t",temp->data); 
    	temp = temp->next; 
    } 
}    
int main(){
    int choice,k,a=1;
    do{
        printf("\n\n1:Enter element");
        printf("\n2:Delete element");
        printf("\n3:Display");
        printf("\n4:Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            Display();
            break;
        case 4:
            a=0;
            break;
        default:
            printf("\nInvalid input");
            break;
        }
    }while (a);
 return 0;
}