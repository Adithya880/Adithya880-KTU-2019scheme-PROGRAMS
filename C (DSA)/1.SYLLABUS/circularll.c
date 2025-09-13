#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} node;

// Creates a new node
node* getnode(int data) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("\nMemory allocation failed");
        return NULL;
    }
    new->data = data;
    new->next = new; // Circular: Points to itself initially
    return new;
}

// Inserts a node at the front
node* insertFront(node* header, int data) {
    node* new = getnode(data);
    if (header == NULL)
        return new; // Circular: First node points to itself

    node* temp = header;
    while (temp->next != header) { // Find the last node
        temp = temp->next;
    }
    new->next = header; // Circular: Update new node to point to the head
    temp->next = new;   // Circular: Last node points to new node
    return new;         // Return new node as head
}

// Inserts a node at the end
node* insertEnd(node* header, int data) {
    node* new = getnode(data);
    if (header == NULL)
        return new; // Circular: First node points to itself

    node* temp = header;
    while (temp->next != header) { // Find the last node
        temp = temp->next;
    }
    temp->next = new;   // Circular: Last node points to new node
    new->next = header; // Circular: New node points to head
    return header;      // Return the unchanged head
}

// Deletes the first node
node* deleteFront(node* header) {
    if (header == NULL) {
        printf("\nList is empty");
        return NULL;
    }

    if (header->next == header) { // Single node in the list
        free(header);
        return NULL;
    }

    node* temp = header;
    node* last = header;
    while (last->next != header) { // Find the last node
        last = last->next;
    }
    header = header->next; // Update head to the next node
    last->next = header;   // Circular: Last node points to the new head
    free(temp);            // Free the old head
    return header;
}

// Deletes the last node
node* deleteEnd(node* header) {
    if (header == NULL) {
        printf("\nList is empty");
        return NULL;
    }

    if (header->next == header) { // Single node in the list
        free(header);
        return NULL;
    }

    node* temp = header;
    node* prev = NULL;
    while (temp->next != header) { // Find the last node
        prev = temp;
        temp = temp->next;
    }
    prev->next = header; // Circular: Second-to-last node points to head
    free(temp);          // Free the last node
    return header;
}

// Displays the list
void display(node* header) {
    if (header == NULL) {
        printf("\nList is empty");
        return;
    }

    node* temp = header;
    do { // Circular: Traverse until back at the head
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != header);
    printf("(back to start)\n");
}

int main() {
    node* header = NULL;
    int data, c;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete at front\n");
        printf("4. Delete at end\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &data);
            header = insertFront(header, data); // Circular: Updated to handle looping
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &data);
            header = insertEnd(header, data); // Circular: Updated to handle looping
            break;
        case 3:
            header = deleteFront(header); // Circular: Updated to handle looping
            break;
        case 4:
            header = deleteEnd(header); // Circular: Updated to handle looping
            break;
        case 5:
            display(header); // Circular: Updated for circular traversal
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (c != 6);

    return 0;
}
