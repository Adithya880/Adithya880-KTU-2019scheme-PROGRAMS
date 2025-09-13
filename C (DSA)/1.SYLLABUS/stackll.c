#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
    int data;
    struct Stack* next;
}stack;

stack* getnode(int data)
{
    stack* new=(stack*)malloc(sizeof(stack));
    if(new==NULL)
    {
        printf("\nMmeory allocation failed");
        return NULL;
    }
    else
    {
        new->data=data;
        new->next=NULL;
        return new;
    }
}

stack* push(stack* top,int data)
{
    stack* new=getnode(data);
    new->next=top;
    top=new;
    return top;
}

int pop(stack** top)
{
    if((*top)==NULL)
    {
        printf("\nStack empty");
        return -1;
    }
    stack* temp=(*top);
    int data=temp->data;
    (*top)=temp->next;
    free(temp);
    return data;
}

void display(stack* top)
{
    if(top==NULL)
    {
        printf("\nList empty");
        return;
    }
    stack* temp=top;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void main()
{
  int c,data;
  stack* top=NULL;
  do
  {
     printf("\nEnter choice:\n");
     printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
     scanf("%d",&c);

     switch(c)
     {
      case 1: 
      printf("Enter data:");
      scanf("%d",&data);
      top=push(top,data);
      break;

      case 2: 
      data=pop(&top);
      if(data!=-1)
        printf("\nPopped element: %d",data);
      break;

      case 3:
      display(top);
      break;

      case 4:
      printf("Exiting..");
      exit(0);

      default:
      printf("Wrong choice!");
     }
  } 
  while (c!=4);
  
 
}