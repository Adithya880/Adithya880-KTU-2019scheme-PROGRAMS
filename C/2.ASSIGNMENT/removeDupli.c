
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

void removeDuplicates(node* header)
{
    node* current=header;
    while(current!=NULL)
    {
        node* temp=current;
        while(temp!=NULL&temp->next!=NULL)
        {
            if(temp->next->data==current->data)
                temp->next=temp->next->next;    
            else
                temp=temp->next;
        }
        
        current=current->next;
    }
}

void main()
{
    node* header1=NULL;
    int n1,data1,i;
    printf("\nEnter the no: of  elements of list 1:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("\nEnter data:");
        scanf("%d",&data1);
        header1=insertEnd(header1,data1);
    }
    printf("\nlist 1:");
    display(header1);
    
    removeDuplicates(header1);
    
    printf("\nlist 1 after removing duplicates:");
    display(header1);
    
}