#include<stdio.h>
#include<stdlib.h>
#define max 5

int ISempty(int* front,int *rear)
{
  return ((*rear)==-1&&(*front)==-1);
}

int ISfull(int* front,int* rear)
{
  return ((*rear + 1) % max == *front);
}

void insert_front(int a[],int item,int*front,int*rear)
{
  if(ISfull(front,rear))
  {
    printf("\nQueue is full");
    return;
  }
  else
  {
    if((*rear)==-1&&(*front)==-1)
       (*rear)=(*front)=0;
    else if((*front)==0)
       (*front)=max-1;
    else
        (*front)--; 

    a[*front]=item;
  }
}

int delete_front(int a[],int*front,int*rear)
{
  if(ISempty(front,rear))
  {
    printf("\nQueue is empty");
    return -1;
  }
  else
  {
    int item=a[*front];
    if((*front)==(*rear))
       (*front)=(*rear)=-1;
    else
       (*front)=((*front)+1)%max; 

    return item;   
  }
}

void insert_rear(int a[],int item,int*front,int*rear)
{
  if(ISfull(front,rear))
  {
    printf("\nQueue is full");
    return;
  }
  else
  {
    if((*rear)==-1&&(*front)==-1)
       (*front)=(*rear)=0;
    else
       (*rear)=((*rear)+1)%max;

    a[*rear]=item;
  }
}

int delete_rear(int a[],int*front,int*rear)
{
  if(ISempty(front,rear))
  {
    printf("\nQueue is empty");
    return -1;
  }
  else
  {
    int item=a[*rear];
    if((*front)==(*rear))
       (*front)=(*rear)=-1;
    else if((*rear)==0)
       (*rear)=max-1;
    else
       (*rear)--; 

    return item;   
  }
}

void display(int a[],int* front,int* rear)
{  
  if(ISempty(front,rear))
  {
    printf("\nQueue is empty");
    return;
  }
  else
  {
    printf("Queue elements: ");
    int i=(*front);
    while(1)
    {
      printf("%d\t",a[i]);
      if(i==(*rear))
      break;
      i=(i+1)%max;
    }
  }
  
}

void main()
{
  int c,item,a[max],front=-1,rear=-1;
  do
  {
     printf("\nEnter choice:\n");
     printf("1.Insert front\n2.Delete front\n3.Insert rear\n4.Delete rear\n5.Display\n6.Exit\n");
     scanf("%d",&c);

     switch(c)
     {
      case 1: 
      printf("Enter item:");
      scanf("%d",&item);
      insert_front(a,item,&front,&rear);
      break;

      case 2: 
      item=delete_front(a,&front,&rear);
      if(item!=-1)
        printf("\nFront Dequeued element: %d",item);
      break;

      case 3: 
      printf("Enter item:");
      scanf("%d",&item);
      insert_rear(a,item,&front,&rear);
      break;

      case 4: 
      item=delete_rear(a,&front,&rear);
      if(item!=-1)
        printf("\nRear Dequeued element: %d",item);
      break;

      case 5:
      display(a,&front,&rear);
      break;

      case 6:
      printf("Exiting..");
      exit(0);

      default:
      printf("Wrong choice!");
     }
  } 
  while (c!=6);
}