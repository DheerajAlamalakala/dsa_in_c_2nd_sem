/*LAB TASK 10A
10A.Develop a C program for Tree sort.

INPUT FORMAT:
FIRST LINE CONTAINS "n" THE SIZE OF THE LIST.
SECOND LINE CONTAINS "n" integers seperated by a space.

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE
THE OUTPUT VALUES ARE SEPERATED BY A TRAILING SPACE.

Test Cases:
case = t6
input = 
7
-98 -567 -345 1000 -1000 54 202
output=
"
TREE SORT - SORTED LIST
-1000 -567 -345 -98 54 202 1000 "
*/
//Start writing program from here
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
}*root = NULL;

struct node* create( int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = data;
    newnode ->left = newnode ->right = NULL;
    return newnode;
}
struct node* insert(struct node *root,int data)
{
    if(root == NULL){
        return create(data);
    }
    if(data <= root ->data)
    root->left = insert(root ->left,data);
    else if(data >= root ->data)
    root->right = insert(root->right,data);
    return root;
}
void sort(struct node *root)
{
    if(root != NULL)
    {
        sort(root->left);
        printf("%d ",root->data);
        sort(root->right);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0 ; i<n; i++)
    {
        scanf("%d",&a[i]);
        root = insert(root,a[i]);
    }
    printf("\nTREE SORT - SORTED LIST\n");
    sort(root);
    return 0;
    
    
}
















