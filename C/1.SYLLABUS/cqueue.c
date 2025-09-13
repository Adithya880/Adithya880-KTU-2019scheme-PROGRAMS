#include<stdio.h>
#include<stdlib.h>
#define max 6

typedef struct Queue
{
    int a[max];
    int front,rear;
}queue;

void createQueue(queue* q)
{
    q->front=-1;
    q->rear=-1;
}

int ISempty(queue* q)
{
    return (q->front==-1&&q->rear==-1);
}

int ISfull(queue* q)
{
    return (q->rear+1)%max==q->front;
}

void enqueue(queue* q,int item)
{
    if(ISfull(q))
    {
        printf("\nQueue is full");
        return;
    }
    
    if(ISempty(q))
        q->front=q->rear=0;
    else
        q->rear=(q->rear+1)%max;
        
    q->a[q->rear]=item;
}

int dequeue(queue* q)
{
    if(ISempty(q))
    {
        printf("\nqueue is empty");
        return -1;
    }
    int item=q->a[q->front];
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front=(q->front+1)%max;
    return item;
}

void display(queue* q)
{
    if(ISempty(q))
    {
        printf("\nqueue is empty");
        return;
    }
    int i=q->front;
    while(i!=q->rear)
    {
        printf("%d ",q->a[i]);
        i=(i+1)%max;
    }
    printf("%d",q->a[q->rear]);
    printf("\n");
}

void main()
{
    queue q;
    createQueue(&q);
  int c,item;
  do
  {
     printf("\nEnter choice:\n");
     printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
     scanf("%d",&c);

     switch(c)
     {
      case 1: 
      printf("Enter item:");
      scanf("%d",&item);
      enqueue(&q,item);
      break;

      case 2: 
      item=dequeue(&q);
      if(item!=-1)
        printf("\nDequeued element: %d",item);
      break;

      case 3:
      display(&q);
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