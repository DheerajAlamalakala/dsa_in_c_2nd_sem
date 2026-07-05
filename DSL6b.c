/*
TASK 6b. Design a C program for level order traversal of a Binary Search Tree.
case = t1
input =
2
3
output = 
Level Order Traversal of BST :
Binary Search Tree is Empty

case = t2
input =
1
10
1
20
1
30
1
5
2
3
output =
Level Order Traversal of BST :
10 5 20 30 
*/
//start writing program from here
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
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

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

struct node* queue[100];

int front = -1;
int rear = -1;

void enqueue(struct node *temp)
{
    if(rear == 99)
        return;

    if(front == -1)
        front = 0;

    rear++;

    queue[rear] = temp;
}

struct node* dequeue()
{
    struct node *temp;

    if(front == -1 || front > rear)
        return NULL;

    temp = queue[front];

    front++;

    return temp;
}

void levelOrder(struct node *root)
{
    struct node *temp;

    if(root == NULL)
    {
        printf("Binary Search Tree is Empty\n");
        return;
    }

    front = rear = -1;

    enqueue(root);

    while(front != -1 && front <= rear)
    {
        temp = dequeue();

        printf("%d ", temp->data);

        if(temp->left != NULL)
            enqueue(temp->left);

        if(temp->right != NULL)
            enqueue(temp->right);
    }

    printf("\n");
}

int main()
{
    struct node *root = NULL;

    int choice, value;

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

                printf("Level Order Traversal of BST :\n");

                levelOrder(root);

                break;

            case 3:

                return 0;

            default:

                printf("Invalid choice\n");
        }
    }

    return 0;
}
