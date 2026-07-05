/*
DS LAB TASK 7A
7A. Implement the following operations on Binary Search Tree  i. Create  ii. Insert iii. Search
NOTE OPTIONS: (i)CREATE-INSERT (ii) SEARCH (iii)EXIT
Also check for "Invalid Option"
INPUT FORMAT: AS PER TEST CASE
OUTPUT FORMAT: AS PER THE TEST CASE

SAMPLE TEST CASES :
case = t5
input=
1
100
1
200
2
300
2
100
3
output=
"Binary Search Tree Operations
100 is inserted into BST.
200 is inserted into BST.
300 is not found in BST.
100 is found in BST."
*/
//Start writing program from here
// BST CREATE INSERT SEARCH
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*right,*left;
}*root = NULL;

struct node* getnode(int n)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->left = temp->right = NULL;
    return temp;
}
struct node * insert(struct node*root,int data)
{
    if(root == NULL)
    {
        root = getnode(data);
        return root;
    }
    else if(data <= root->data)
    root->left = insert(root->left,data);
    else
    root->right = insert(root->right,data);
    return root;
}
int search(struct node*root,int data)
{
    if(root == NULL)
    return 0;
    else if(root ->data == data)
    return 1;
    else if (root->data<data)
    return search(root->right,data);
    else
    return search(root->left,data);
}
int main()
{
    int ch,data,sc;
    printf("Binary Search Tree Operations\n");
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            scanf("%d",&data);
            root = insert(root,data);
            printf("%d is inserted into BST.\n",data);
            break;
            case 2:
            scanf("%d",&sc);
            if(root == NULL){
                printf("EMPTY BST - CANNOT SEARCH.\n");
                return 0;
            }else{
                int r = search(root,sc);
                if(r)
                printf("%d is found in BST.\n",sc);
                else
                printf("%d is not found in BST.\n",sc);
            }
            break;
            case 3:
            exit(0);
            default:
            printf("Invalid Choice.\n");
            
        }
    }
}
