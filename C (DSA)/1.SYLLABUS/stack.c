#include<stdio.h>
#include<stdlib.h>
#define max 6

typedef struct Stack
{
    int a[max];
    int top;
}stack;

void createStack(stack* s)
{
    s->top=-1;
}

int ISempty(stack* s)
{
    return s->top==-1;
}

int ISfull(stack* s)
{
    return s->top==max-1;
}

void push(stack* s,int item)
{
    if(ISfull(s))
    {
        printf("\nStack is full");
        return;
    }
    s->top++;
    s->a[s->top]=item;
}

int pop(stack* s)
{
    if(ISempty(s))
    {
        printf("\nStack is empty");
        return -1;
    }
    int item=s->a[s->top];
    s->top--;
    return item;
}

void display(stack* s)
{
    if(ISempty(s))
    {
        printf("\nStack is empty");
        return;
    }
    for(int i=s->top;i>=0;i--)
    {
        printf("%d ",s->a[i]);
    }
    printf("\n");
}

void main()
{
    stack s;
    createStack(&s);
  int c,item;
  do
  {
     printf("\nEnter choice:\n");
     printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
     scanf("%d",&c);

     switch(c)
     {
      case 1: 
      printf("Enter item:");
      scanf("%d",&item);
      push(&s,item);
      break;

      case 2: 
      item=pop(&s);
      if(item!=-1)
        printf("\nPopped element: %d",item);
      break;

      case 3:
      display(&s);
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