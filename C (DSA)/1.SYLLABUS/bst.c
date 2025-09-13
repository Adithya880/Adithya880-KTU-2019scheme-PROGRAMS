/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
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
    if (newNode == NULL) return root;

    if (root == NULL) {
        return newNode; // The tree was empty
    }

    TreeNode* current = root;
    TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            // Value already exists in the tree
            free(newNode);
            return root; 
        }
    }

    // Insert the new node as a child of the parent
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

// Non-Recursive Search Function
TreeNode* search(TreeNode* root, int data) {
    TreeNode* current = root;

    while (current != NULL) {
        if (data == current->data) {
            return current; // Node found
        } else if (data < current->data) {
            current = current->left; // Search left subtree
        } else {
            current = current->right; // Search right subtree
        }
    }

    return NULL; // Node not found
}
// Function to find the node with minimum value
TreeNode* findMin(TreeNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the node with maximum value
TreeNode* findMax(TreeNode* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node from the BST
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

// In-order traversal (Left, Root, Right)
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Pre-order traversal (Root, Left, Right)
void preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order traversal (Left, Right, Root)
void postOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

// Main function to demonstrate BST operations
int main() {
    TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. In-order Traversal\n");
        printf("7. Pre-order Traversal\n");
        printf("8. Post-order Traversal\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                TreeNode* found = search(root, data);
                if (found != NULL) {
                    printf("Data %d found in the tree.\n", data);
                } else {
                    printf("Data %d not found in the tree.\n", data);
                }
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 4:
                if (root == NULL) {
                    printf("The tree is empty.\n");
                } else {
                    TreeNode* minNode = findMin(root);
                    printf("The minimum value in the tree is: %d\n", minNode->data);
                }
                break;
            case 5:
                if (root == NULL) {
                    printf("The tree is empty.\n");
                } else {
                    TreeNode* maxNode = findMax(root);
                    printf("The maximum value in the tree is: %d\n", maxNode->data);
                }
                break;
            case 6:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Pre-order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 8:
                printf("Post-order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
