#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct stacktop
{
    int s[size];
    int top;
}st;

void push(st *p, int item){
    if (p->top==size-1){
        printf("Stack is full");
        
    }
    else{
        p->top=p->top+1;
        p->s[p->top]=item;
    }    
}


void pop(st*p){
    int del;
    if (p->top==-1)
        printf("\n Stack empty");
    else
        del=p->s[p->top];
        p->top--;
        printf("Popped item=%d",del);
}

void display(st *p)
{
    int i;
    if(p->top==-1)
        {
            printf("\n There is no data item to display\n");
        }
        else
        {
            for(i=p->top; i>=0; i--)
            {
                printf("%d\t",p->s[i]);
            }
        }
}

int main(){
    int element,choice;
    st *s;
    s->top = -1; 
    int flag=1;
    do
    {
        printf("\n\t-------------");
        printf("\n 1:Push");
        printf("\n 2:Pop");
        printf("\n 3:Display");//to see all elements in stack
        printf("\n 4:Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
         case 1:
            printf("\n Enter a element:");
            scanf("%d",&element);
            push(s,element);
            break;

         case 2:
            pop(s);
            break;
        
         case 3:
            display(s);
            break;
        
         case 4:
            flag=0;
            break;
        
         default:
            printf("\n Invalid Choice");
            printf("\n Press 4 to exit");
            break;
        }
    } while (flag);
    
  return 0;  
} 