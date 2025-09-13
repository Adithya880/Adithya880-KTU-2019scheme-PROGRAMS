#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    struct Node* next;
    int data;
}node;

node* getnode(int data)
{
    node* new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("\nMmeory allocation failed");
        return NULL;
    }
    else
    {
        new->next=NULL;
        new->data=data;
        return new;
    }
}

node* insertFront(node* header,int data)
{
    node *new=getnode(data);
    if(header==NULL)
     return new;
    new->next=header;
    header=new;
    return header;
}

node* insertEnd(node* header,int data)
{
    node *new=getnode(data);
    if(header==NULL)
     return new;
    node* temp=header;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    return header;
}

node* insertAfterKey(node* header,int data,int key)
{
    node* new=getnode(data);
    node* temp=header;
    while(temp!=NULL&&temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
     {  
         header=insertEnd(header,data);
         printf("\nAdded at the end");
     }
     else
     {
         new->next=temp->next;
         temp->next=new;
     }
         return header;
}

node* deleteFront(node* header)
{
    if(header==NULL)
    {
        printf("\nList Empty");
        return NULL;
    }
    else
    {
          node* temp=header;
          header=temp->next;
          free(temp);
          return header;
    }
}

node* deleteEnd(node* header)
{
    if(header==NULL)
    {
        printf("\nList Empty");
        return NULL;
    }
    else if(header->next==NULL)
    {
        free(header);
        return NULL;
    }
    else
    {
        node* temp=header;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        return header;
    }
}

node* deleteAtKey(node* header,int key)
{
    if(header==NULL)
    {
        printf("\nList Empty");
        return NULL;
    }
    else
    {
        node* temp=header;
        node* prev=NULL;
        if(temp->data==key)
        {   
            header=temp->next;
            free(temp);
            return header;
        }
        while(temp!=NULL&&temp->data!=key)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\nKey not found");
        }
        else
        {
            prev->next=temp->next;
            free(temp);
        }
        return header;
    }
}

void display(node* header)
{
    if(header==NULL)
    {
        printf("\nList empty");
        return;
    }
    node* temp=header;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void main()
{   
    node* header=NULL;
    int data,key,c;
    do
    {
        printf("Enter your choice:\n");
		printf("1. Insert at front\n");
		printf("2. Insert at end\n");
		printf("3. Insert after key\n");
		printf("4. Delete at front\n");
		printf("5. Delete at end\n");
		printf("6. Delete by key\n");
		printf("7. Display List\n");
		printf("8. Exit\n");
		scanf("%d", &c);
		switch (c) {
		case 1:
			printf("Enter value to insert at front: ");
			scanf("%d", &data);
			header = insertFront(header, data);
			break;
		case 2:
			printf("Enter value to insert at end: ");
			scanf("%d", &data);
			header = insertEnd(header, data);
			break;
		case 3:
			printf("Enter key after which to insert: ");
			scanf("%d", &key);
			printf("Enter value to insert: ");
			scanf("%d", &data);
			header = insertAfterKey(header,data, key);
			break;
		case 4:
			header = deleteFront(header);
			break;
		case 5:
			header = deleteEnd(header);
			break;
		case 6:
			printf("Enter the key to delete: ");
			scanf("%d", &key);
			header = deleteAtKey(header, key);
			break;
		case 7:
			display(header);
			break;
		case 8:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	} 
	while (c != 8);
}
