#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} node;

node* getnode(int data)
{
    node* new=(node*)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("\nMmeory allocation failed");
        return NULL;
    }
    new->prev=NULL;
    new->next=NULL;
    new->data=data;
    return new;
}

node* insertFront(node* header,node** tail,int data)
{
    node* new=getnode(data);
    if(header==NULL)
        header=*tail=new;
    else
    {
        new->next=header;
        header->prev=new;
        header=new;
    }
    return header;
}

node* insertEnd(node* header,node** tail,int data)
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
        new->prev=temp;
        *tail=new;
        return header;
    }
}

node* insertAfterKey(node* header,node** tail,int data,int key)
{
    node* new=getnode(data);
    if(header==NULL)
     return new;
    else
    {
        node* temp=header;
        while(temp!=NULL&&temp->data!=key)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {   
            header=insertEnd(header,tail,data);
            printf("\nAdded at the end");
        }
        else
        {
            new->next=temp->next;
            new->prev=temp;
            if (temp->next != NULL)
               temp->next->prev = new;
            else
                *tail = new; // Update tail
                
            temp->next = new;
        }
        return header;
    }
}

node* deleteFront(node* header,node** tail)
{
    if (header == NULL) 
    {
        printf("List is empty, nothing to delete.\n");
        return header;
    }
    else
    {   
        node* temp=header;
        header = header->next;
        if (header != NULL) {
            header->prev = NULL;
        } else {
            *tail = NULL; // If list is empty, update tail to NULL
        }
        free(temp);
        return header;
    }
}

node* deleteEnd(node* header,node** tail)
{
    if (header == NULL) 
    {
        printf("List is empty, nothing to delete.\n");
        return header;
    }
    else
    {
        node* temp=header;
        if (temp->next == NULL) 
        { // Only one node
            free(temp);
            return NULL;
        }
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        *tail = temp->prev; // Update tail to the new last node
        free(temp);
        return header;
    }
}

node* deleteAtKey(node* header,node** tail,int key)
{
    if (header == NULL) 
    {
        printf("List is empty, nothing to delete.\n");
        return header;
    }
    node* temp = header;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        printf("Key not found, no deletion possible.\n");
    } 
    else 
    {
        if (temp->prev != NULL) 
            temp->prev->next = temp->next;
        else 
            header = temp->next;
            
        if (temp->next != NULL) 
            temp->next->prev = temp->prev;
        else 
            *tail = temp->prev; // Update tail if deleting the last node
        free(temp);
    }
    return header;
}

void display(node* header) 
{
    node* temp = header;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{   
    node* header=NULL;
    node* tail=NULL;
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
			header = insertFront(header,&tail,data);
			break;
		case 2:
			printf("Enter value to insert at end: ");
			scanf("%d", &data);
			header = insertEnd(header,&tail,data);
			break;
		case 3:
			printf("Enter key after which to insert: ");
			scanf("%d", &key);
			printf("Enter value to insert: ");
			scanf("%d", &data);
			header = insertAfterKey(header,&tail,data, key);
			break;
		case 4:
			header = deleteFront(header,&tail);
			break;
		case 5:
			header = deleteEnd(header,&tail);
			break;
		case 6:
			printf("Enter the key to delete: ");
			scanf("%d", &key);
			header = deleteAtKey(header,&tail, key);
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
