
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    int pos;
    struct Node* next;
}node;

node* getnode(int data,int pos)
{
    node* new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("\nMemory allocation failed");
        return NULL;    
    }
    new->data=data;
    new->pos=pos;
    new->next=NULL;
    return new;
    
}

node* insertEnd(node* header,int data,int pos)
{
    node* new=getnode(data,pos);
    if(header==NULL)
        return new;
    else
    {
        node* temp=header;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        return header;
    }
}

void display(node* header)
{
    if(header==NULL)
        printf("\nList empty");
    else
    {
        node* temp=header;
        while(temp!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int search(node* header,int key)
{
    node* temp=header;
    while(temp!=NULL&&temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\nElement not found");
        return -1;
    }
    else
    {
        return temp->pos;
    }
}

void main()
{
    node* header=NULL;
    int n,data,i,pos,key,position;
    printf("\nEnter the no: of  elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter data:");
        scanf("%d",&data);
        pos=i+1;
        header=insertEnd(header,data,pos);
    }
    
    
    printf("\nlist:");
    display(header);
    
    printf("\nEnter key to search: ");
    scanf("%d",&key);
    
    position=search(header,key);
    if(position!=-1)
    printf("\nPosition: %d",position);
    
}