/*
TASK 8A. Implement the following operations on BINARY SEARCH TREE using a C program.
TASK 8-BST OPERATIONS - Countnodes Height Minimum node Maximum node
(i) CREATE/INSERT (ii) COUNT NODES (iii) HEIGHT (iV) MINIMUM (v) MAXIMUM  (vi) Exit

INPUT FORMAT: AS PER TEST CASE
OUTPUT FORMAT: AS PER TEST CASE
LEAF NODES ARE AT HEIGHT 0.
SAMPLE TEST CASES
case = T7
input=
1
10
1
5
1
0
1
-5
1
-10
3
5
2
4
6
output=
"
Binary Search Tree Operations
HEIGHT OF BST = 4
MAXIMUM VALUE IN BST = 10
NODES IN BST = 5
MINIMUM VALUE IN BST = -10"

NOTE:
CHECK OUTPUTS FOR ALL THE GIVEN OPERATIONS
NOTE : JUST REMEMBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node *newNode =
        (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node *root, int data)
{
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);

    else if(data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int countNodes(struct node *root)
{
    if(root == NULL)
        return 0;

    return 1 +
           countNodes(root->left) +
           countNodes(root->right);
}

int height(struct node *root)
{
    if(root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

int minimum(struct node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root->data;
}

int maximum(struct node *root)
{
    while(root->right != NULL)
        root = root->right;

    return root->data;
}

int main()
{
    struct node *root = NULL;

    int choice, value;

    printf("\nBinary Search Tree Operations");

    while(1)
    {
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:

                printf("\nNODES IN BST = %d",
                       countNodes(root));
                break;

            case 3:

                if(root == NULL)
                    printf("\nBST EMPTY - NO HEIGHT");
                else
                    printf("\nHEIGHT OF BST = %d",
                           height(root));

                break;

            case 4:

                if(root == NULL)
                    printf("\nBST EMPTY - NO MINIMUM");
                else
                    printf("\nMINIMUM VALUE IN BST = %d",
                           minimum(root));

                break;

            case 5:

                if(root == NULL)
                    printf("\nBST EMPTY - NO MAXIMUM");
                else
                    printf("\nMAXIMUM VALUE IN BST = %d",
                           maximum(root));

                break;

            case 6:

                exit(0);

            default:

                printf("\nINVALID CHOICE");
        }
    }

    return 0;
}
