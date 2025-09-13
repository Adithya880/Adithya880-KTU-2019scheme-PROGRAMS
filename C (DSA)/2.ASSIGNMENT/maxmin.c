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

int max(node* header)
{
    node* temp=header;
    int max=-999999;
    while(temp!=NULL)
    {
        if(temp->data>max)
            max=temp->data;
            
        temp=temp->next;
    }
    return max;
}

int min(node* header)
{
    node* temp=header;
    int min=999999;
    while(temp!=NULL)
    {
        if(temp->data<min)
            min=temp->data;
            
        temp=temp->next;
    }
    return min;
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

    printf("list:\n");
    display(header);

    printf("\nMax: %d",max(header));
    printf("\nMin: %d",min(header));

   
}
