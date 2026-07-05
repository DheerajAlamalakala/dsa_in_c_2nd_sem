/*3. Write a C program to implement Singly Linked List operations. 
Write a C program to implement the folowing operations on  SINGLE LINKED LIST
OPERATIONS:
1.Insert 2.Delete 3.Display 4.Search 5.NodeCount 6.Reverse Display 7.Exit
Also check for "Invalid Choice"
INPUT FORMAT :
FOR INSERT - ENTER POSITION AND VALUE
FOR DELETE - ENTER POSITION
FOR SEARCH - ENTER KEY TO FIND.

SAMPLE TEST CASES:
case=t1
input=
1
1 700
1 
2 900
1 
1 1100
3
4 700
4 100
2 2
5
6
2 20
1
10 100
7
output=
SLL ELEMENTS ARE
1100 ->700 ->900 ->
700 is found in SLL
100 is not found in SLL
Deleted element from SLL is 700
No of nodes in SLL = 2
SLL ELEMENTS IN REVERSE ORDER
900 1100
Position does not exist - Cannot delete from SLL
Position does not exist - Cannot insert into SLL


CHECK OUTPUT FOR ALL THE GIVEN OPERATIONS
NOTE : JUST REMEMEBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY. 
*/
//Start writing program from here

//sll implementation
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*start=NULL;
void SLLdisplay();
void SLLsearch(int x);
void SLLdeletePos(int pos);
void SLLinsertPos(int pos ,int val);
int SLLCountNodes();
void SLLreverse(struct node *temp);

int main()
{
    int ch,val,pos,x;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:scanf("%d %d",&pos,&val);
                   SLLinsertPos(pos,val);
                   break;
            case 2:scanf("%d",&pos);
                   SLLdeletePos(pos);
                   break;
            case 3:SLLdisplay();
                   printf("\n");
                   break;
            case 4:scanf("%d",&x);
                   SLLsearch(x);
                   break;
            case 5:printf("No of nodes in SLL = %d\n",SLLCountNodes());
                   break;
            case 6:if(start==NULL)
                     printf("\nEmpty SLL - Cannot Reverse Display");
                   else{
                     printf("SLL ELEMENTS IN REVERSE ORDER\n");
                     SLLreverse(start);
                   }
                     break;
            case 7:exit(0);
            default:printf("\nInvalid Choice");
        }
    }
}
void SLLdisplay()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("Empty SLL - Cannot display\n");
        return;
    }
    else
    {
        printf("SLL ELEMENTS ARE\n");
        for(temp = start;temp!=NULL;temp = temp->next)
        printf("%d ->",temp->data);
    }
}
void SLLsearch(int x)
{
    struct node *temp;
    if(start == NULL)
    {
        printf("SLL Empty - Cannot Search\n");
        return;
    }
    else
    {
        for(temp = start;temp != NULL;temp = temp ->next)
        {
            if(x==temp->data)
            {
                printf("%d is found in SLL\n",temp ->data);
                return;
            }
        }
        printf("%d is not found in SLL\n",x);
    }
}
int SLLCountNodes()
{
    struct node *temp;
    int count = 0;
    for(temp = start;temp != NULL;temp = temp ->next)
    count++;
    return count;
}
void SLLreverse(struct node*temp)
{
    if(temp == NULL)
    return;
    SLLreverse(temp->next);
    printf("%d ",temp->data);
}
void SLLinsertPos(int pos,int val)
{
    struct node*newnode,*temp=start;
    if(pos>0 && (pos <= SLLCountNodes() + 1))
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data= val;
        if(pos==1)
        {
            newnode->next=start;
            start= newnode;
        }
        else
        {
            for(int i = 1;i<=pos-2;i++)
            temp = temp->next;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    else
    {
        printf("Position does not exist - Cannot insert into SLL\n");
    }
}
void SLLdeletePos(int pos)
{
    struct node *delnode,*temp = start;
    if(pos>0 && pos<=SLLCountNodes())
    {
        if(pos==1)
        {
            delnode = start;
            start = start->next;
        }
        else
        {
            for(int i=1;i<=pos-2;i++)
            temp = temp->next;
            delnode = temp->next;
            temp->next = delnode->next;
        }
        printf("Deleted element from SLL is %d\n",delnode->data);
        free(delnode);
    }
    else
    printf("Position does not exist - Cannot delete from SLL\n");
}
