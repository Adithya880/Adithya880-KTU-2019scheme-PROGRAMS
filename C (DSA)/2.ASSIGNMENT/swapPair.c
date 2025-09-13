#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function to create a new node
node* getnode(int data) 
{
    node* new = (node*)malloc(sizeof(node));
    if (!new) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->next = NULL;
    return new;
}

// Function to insert a node at the end of the list
node* insertEnd(node* header, int data) 
{
    node* new = getnode(data);
    if (header == NULL) {
        return new;
    }
    node* temp = header;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new;
    return header;
}

node* swapPair(node* header)
{   
    int c;
    if(header==NULL||header->next==NULL)
        return header;
    node* temp=header;
    while(temp!=NULL&& temp->next != NULL)
    {
        c=temp->data;
        temp->data=temp->next->data;
        temp->next->data=c;
        
        temp=temp->next->next;
       /* if(temp->next==NULL)
        break;*/
    }
    return header;
}


// Function to display the list
void display(node* header) 
{
    node* temp = header;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() 
{
    node* header = NULL;
    int n, data;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        header = insertEnd(header, data);
    }

    printf("\nlist:");
    display(header);

    header=swapPair(header);
    printf("\nlist after swapping:");
    display(header);
   
}
