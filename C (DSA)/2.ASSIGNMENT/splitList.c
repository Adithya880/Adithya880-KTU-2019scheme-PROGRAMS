
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
            printf("%d(%d) ->",temp->data,temp->pos);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

node* oddSplit(node* header,node* header1)
{
    node* temp=header;
    while(temp!=NULL)
    {
        if(temp->pos % 2 !=0)
            header1=insertEnd(header1,temp->data,temp->pos);
        temp=temp->next;
    }
    return header1;
}

node* evenSplit(node* header,node* header2)
{
    node* temp=header;
    while(temp!=NULL)
    {
        if(temp->pos % 2 ==0)
        header2=insertEnd(header2,temp->data,temp->pos);
        temp=temp->next;
    }
    return header2;
}

void main()
{
    node* header=NULL;
    node* header1=NULL;
    node* header2=NULL;
    int n,data,i,pos;
    printf("\nEnter the no: of  elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter data:");
        scanf("%d",&data);
        pos=i+1;
        header=insertEnd(header,data,pos);
    }
    
    header1=oddSplit(header,header1);
    header2=evenSplit(header,header2);
    printf("\nOriginal list:");
    display(header);
    printf("\nOdd List:");
    display(header1);
    printf("\nEven list:");
    display(header2);
}