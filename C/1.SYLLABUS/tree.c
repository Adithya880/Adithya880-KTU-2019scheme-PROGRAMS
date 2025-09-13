#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Stack structure
typedef struct Stack {
    TreeNode* data[MAX];
    int top;
} Stack;

// Queue structure
typedef struct Queue {
    TreeNode* data[MAX];
    int front, rear;
} Queue;

// Stack operations
void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, TreeNode* node) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = node;
}

TreeNode* pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->data[(s->top)--];
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

// Queue operations
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, TreeNode* node) {
    if (q->rear == MAX) {
        printf("Queue overflow\n");
        return;
    }
    q->data[q->rear++] = node;
}

TreeNode* dequeue(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue underflow\n");
        return NULL;
    }
    return q->data[q->front++];
}

int isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

// Create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    TreeNode* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }

    Queue queue;
    initQueue(&queue);
    enqueue(&queue, root);

    while (!isQueueEmpty(&queue)) {
        TreeNode* current = dequeue(&queue);

        // Insert in the left child if it's empty
        if (current->left == NULL) {
            current->left = newNode;
            break;
        } else {
            enqueue(&queue, current->left);
        }

        // Insert in the right child if it's empty
        if (current->right == NULL) {
            current->right = newNode;
            break;
        } else {
            enqueue(&queue, current->right);
        }
    }

    return root;
}



// Iterative In-order traversal
void inOrderTraversal(TreeNode* root) {
    Stack stack;
    initStack(&stack);
    TreeNode* current = root;

    while (!isStackEmpty(&stack) || current != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Iterative Pre-order traversal
void preOrderTraversal(TreeNode* root) {
    Stack stack;
    initStack(&stack);
    if (root == NULL) return;

    push(&stack, root);

    while (!isStackEmpty(&stack)) {
        TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

// Iterative Post-order traversal using two stacks
void postOrderTraversal(TreeNode* root) {
    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    if (root == NULL) return;

    push(&stack1, root);

    while (!isStackEmpty(&stack1)) {
        TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    while (!isStackEmpty(&stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

// Level-order traversal (BFS) using queue
void levelOrderTraversal(TreeNode* root) {
    Queue queue;
    initQueue(&queue);
    
    if (root == NULL) return;

    enqueue(&queue, root);

    while (!isQueueEmpty(&queue)) {
        TreeNode* current = dequeue(&queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }
}

// Delete a node from the binary search tree
TreeNode* deleteNode(TreeNode* root, int data) {
    TreeNode* parent = NULL;  // To track the parent of the current node
    TreeNode* current = root; // To traverse the tree
    
    // Step 1: Find the node to be deleted and its parent
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // If the node was not found
    if (current == NULL) {
        printf("Node with data %d not found.\n", data);
        return root;
    }

    // Step 2: Handle deletion cases

    // Case 1: Node has no children (leaf node)
    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            free(root);  // If the root is the node to be deleted
            return NULL;
        }
        if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    }
    
    // Case 2: Node has one child
    else if (current->left == NULL || current->right == NULL) {
        TreeNode* child = (current->left != NULL) ? current->left : current->right;
        
        if (current == root) {
            free(root);  // If the root is the node to be deleted
            return child;
        }
        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(current);
    }
    
    // Case 3: Node has two children
    else {
        TreeNode* successorParent = current;
        TreeNode* successor = current->right;

        // Find the in-order successor (smallest node in the right subtree)
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace current node's data with successor's data
        current->data = successor->data;

        // Remove the successor (which has at most one child)
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        free(successor);
    }

    return root;
}

// Menu-driven interface
void menu() {
    TreeNode* root = NULL;  // Corrected to be a pointer
    int choice, data;

    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Level-order Traversal\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);  // Pass root directly
                break;
            case 2:
                printf("In-order Traversal: ");
                inOrderTraversal(root);  // Pass root directly
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preOrderTraversal(root);  // Pass root directly
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postOrderTraversal(root);  // Pass root directly
                printf("\n");
                break;
            case 5:
                printf("Level-order Traversal: ");
                levelOrderTraversal(root);  // Pass root directly
                printf("\n");
                break;
            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);  // Pass root directly
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
