/*
DS LAB TASK 7B
7b.	Implement the following operations on Binary Search Tree
i.	Delete	ii. Display (INORDER)
NOTE THE OPTIONS: 1.INSERT 2.DELETE 3.DISPLAY-INORDER 4.EXIT
Also check for "Invalid Option"
NOTE : USE THE PREXISTING INSERT FUNCTION GIVEN IN THE CODE AS CASE 1 IN LOGIC IMPLEMENTATION.
INPUT FORMAT: AS PER TEST CASE
OUTPUT FORMAT: AS PER THE TEST CASE

SAMPLE TEST CASES :
case = t8
input=
1
50
1
67
1
34
3
2
50
3
2
67
4
output=
"
The elements of BST - INORDER :34->50->67->
50 is found and deleted from BST
The elements of BST - INORDER :34->67->
67 is found and deleted from BST"
*/
//Start writing program from here

#include<stdio.h>
#include<stdlib.h>

int flag = 0;

struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};

struct BSTnode *root = NULL;

struct BSTnode* insert(struct BSTnode *root,int val)
{
    if(root==NULL)
    {
        struct BSTnode *newnode;
        newnode = (struct BSTnode*)malloc(sizeof(struct BSTnode));

        newnode->data = val;
        newnode->left = newnode->right = NULL;

        return newnode;
    }

    else if(val < root->data)
    {
        root->left = insert(root->left,val);
    }

    else
    {
        root->right = insert(root->right,val);
    }

    return root;
}

struct BSTnode* minValueNode(struct BSTnode* node)
{
    struct BSTnode* current = node;

    while(current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

struct BSTnode* deletion(struct BSTnode *root,int val)
{
    if(root == NULL)
        return root;

    if(val < root->data)
    {
        root->left = deletion(root->left,val);
    }

    else if(val > root->data)
    {
        root->right = deletion(root->right,val);
    }

    else
    {
        flag = 1;

        if(root->left == NULL)
        {
            struct BSTnode *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            struct BSTnode *temp = root->left;
            free(root);
            return temp;
        }

        struct BSTnode *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deletion(root->right,temp->data);
    }

    return root;
}

void display(struct BSTnode *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%d->",root->data);
        display(root->right);
    }
}

int main()
{
    int ch,val;

    while(1)
    {
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:

                scanf("%d",&val);
                root = insert(root,val);
                break;

            case 2:

                scanf("%d",&val);

                if(root == NULL)
                {
                    printf("\nEmpty BST - Cannot delete");
                    break;
                }

                flag = 0;

                root = deletion(root,val);

                if(flag)
                    printf("\n%d is found and deleted from BST",val);
                else
                    printf("\n%d is not found in BST - So cannot delete",val);

                break;

            case 3:

                if(root == NULL)
                {
                    printf("\nEmpty BST - Nothing to Display");
                }
                else
                {
                    printf("\nThe elements of BST - INORDER :");
                    display(root);
                }

                break;

            case 4:

                return 0;

            default:

                printf("\nInvalid Option");
        }
    }
}
