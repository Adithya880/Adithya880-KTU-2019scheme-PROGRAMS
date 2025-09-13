
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node;

node* getnode(int data)
{
    node* new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("\nMemory allocation failed");
        return NULL;    
    }
    new->data=data;
    new->next=NULL;
    return new;
    
}

node* insertEnd(node* header,int data)
{
    node* new=getnode(data);
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

node* merge(node* header1,node* header2,node* header3)
{
        
    node* temp1=header1;
    node* temp2=header2;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data<=temp2->data)
        {
            header3=insertEnd(header3,temp1->data);
            temp1=temp1->next;
        }
        
        else
        {
            header3=insertEnd(header3,temp2->data);
            temp2=temp2->next;
        }
        
    }
    while(temp1!=NULL)
    {
        header3=insertEnd(header3,temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        header3=insertEnd(header3,temp2->data);
        temp2=temp2->next;
    }
    return header3;
}

void main()
{
    node* header1=NULL;
    node* header2=NULL;
    node* header3=NULL;
    int n1,n2,data1,data2,i;
    printf("\nEnter the no: of  elements of list 1:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("\nEnter data:");
        scanf("%d",&data1);
        header1=insertEnd(header1,data1);
    }
    
    
    printf("\nEnter the no: of  elements of list 2:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("\nEnter data:");
        scanf("%d",&data2);
        header2=insertEnd(header2,data2);
    }
    
    printf("\nlist 1:");
    display(header1);
    printf("\nlist 2:");
    display(header2);
    header3=merge(header1,header2,header3);
    printf("\nMerged list:");
    display(header3);
}