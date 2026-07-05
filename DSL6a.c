/*
TASK - 6a - Develop a C code for preorder, inorder and postorder traversals of 
a Binary Search Tree using recursion.
i. insert ii. preorder iii. inorder iv. postorder v. exit.

case = t2
input= 1
45
1
23
1
67
1
12
2
3
4
5
output=
"
PREORDER TRAVERSAL OF BINARY SEARCH TREE
45 23 12 67 
INORDER TRAVERSAL OF BINARY SEARCH TREE
12 23 45 67 
POSTORDER TRAVERSAL OF BINARY SEARCH TREE
12 23 67 45 "

case = t5
input= 1   
0
1
-3
1
5
1
-10
1
2
1
8
2
3
4
5
output=
"
PREORDER TRAVERSAL OF BINARY SEARCH TREE
0 -3 -10 5 2 8 
INORDER TRAVERSAL OF BINARY SEARCH TREE
-10 -3 0 2 5 8 
POSTORDER TRAVERSAL OF BINARY SEARCH TREE
-10 -3 2 8 5 0 "

NOTE:
CHECK OUTPUTS FOR ALL THE GIVEN OPERATIONS
NOTE : JUST REMEMBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                if (root == NULL) {
                    printf("\nBST Empty");
                } else {
                    printf("\nPREORDER TRAVERSAL OF BINARY SEARCH TREE\n");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("\nBST Empty");
                } else {
                    printf("INORDER TRAVERSAL OF BINARY SEARCH TREE\n");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("\nBST Empty");
                } else {
                    printf("POSTORDER TRAVERSAL OF BINARY SEARCH TREE\n");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
