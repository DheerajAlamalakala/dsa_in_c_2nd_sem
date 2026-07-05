/* 
LAB TASK 12A
QUESTION:
Task 12A. Implement a C program for the following operations on Hashing:
i. insert ii. delete iii. search iv. Display
v Exit
Also Check for Invalid Case.
Note: Initilaize the Hash Table with -1.
Also Use MAX size as 5.
Test Cases:
case=t4
input=
1
16
1
67
1
56
1
20
1
78
4
3
20
3
55
2
16
3
67
5
output=
Operations on Hash Table
16 is inserted at H[1]
67 is inserted at H[2]
Collision at H[1] in  Hash table - Cannot Insert 56
20 is inserted at H[0]
78 is inserted at H[3]
Hash Table
H[0] = 20
H[1] = 16
H[2] = 67
H[3] = 78
H[4] = -1
20 is found in Hash Table
55 is not found in Hash Table
16 is found in the Hash table at H[1] and deleted from it.
67 is found in Hash Tab
*/
//Start writing program from here
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int H[MAX] = {-1,-1,-1,-1,-1},res;
void hashinsert(int v)
{
    res = (v % MAX);
    if(H[res] == -1)
    {
        H[res] = v;
        printf("\n%d is inserted at H[%d]",v,res);
    }
    else{
        printf("\nCollision at H[%d] in Hash table - Cannot Insert %d",res,v);
    }
}
void hashdelete(int v)
{
    res = (v % MAX);
    if(H[res] == v)
    {
        printf("\n%d is found in the Hash table at H[%d] and deleted from it.",v,res);
        H[res] = -1;
    }
    else
    {
        printf("\n%d is not found in the Hash table - Cannot Delete",v);
    }
}
void hashsearch(int v)
{
    res = v % MAX;
    if(H[res] == v)
    printf("\n%d is found in Hash Table",v);
    else
    printf("\n%d is not found in Hash Table",v);
}
void display()
{
    int i;
    printf("\nHash Table");
    for(i = 0; i<MAX; i++)
    printf("\nH[%d] = %d",i,H[i]);
}
int main()
{
    int ch,v;
    printf("\nOperations on Hash Table:");
    while(1)
    {
        scanf("%d",&ch);
        switch(ch){
            case 1 :
            scanf("%d",&v);
            hashinsert(v);
            break;
            case 2:
            scanf("%d",&v);
            hashdelete(v);
            break;
            case 3:
            scanf("%d",&v);
            hashsearch(v);
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            default: printf("\nInvalid choice");
        }
    }
}
