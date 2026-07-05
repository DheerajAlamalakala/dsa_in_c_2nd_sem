/* TASK 7:
7.Write a C program to implement the folowing operations on  CIRCULAR LINKED LIST
OPERATIONS:
1.Insert 2.Delete 3.Display 4.Search 5.Nodecount 6.Rev Display 7.Exit
Also check for "Invalid Choice"
INPUT FORMAT : 
FOR INSERT - READ VALUE AND POSITION
FOR DELETE - READ POSITION
FOR SEARCH - READ KEY
OUTPUT FORMAT:
DISPLAY AS PER TEST CASES.

TEST CASE :
CASE=T10
INPUT=
1
100 1
1
200 1
1
300 1
5
6
3
4
2500
4
200
2
2
2
10
1
1000 10
7

OUTPUT=
CLL OPERATIONS
100 is inserted into CLL at position 1
200 is inserted into CLL at position 1
300 is inserted into CLL at position 1
No of nodes in CLL = 3
CLL Reverse Display :100 ->200 -> 300 -> 
CLL elements are :300 ->200 ->100 ->
2500 is not found in CLL
200 is found in CLL
Deleted Node form CLL is 200 from position 2
Cannot Delete from CLL - Invalid Position or CLL Empty
Cannot Insert in CLL - Invalid Position

CHECK OUTPUT FOR ALL THE GIVEN OPERATIONS
NOTE : JUST REMEMEBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY. 
*/
//Start writing program from here

//IMPLEMENTING CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct CLLNode
{
    int data;
    struct CLLNode *next; 
} *start = NULL;
typedef struct CLLNode CNode;
void CLLDisplay();
int CLLCountNodes();
void CLLSearch(int x);
void CLLInsert(int v,int pos);
void CLLDelete(int pos);
void CLLRevDisplay(CNode *temp);
int CLLCountNodes()
{
    int count = 0;
    if(start == NULL)
        return 0;

    CNode *temp = start;
    do
    {
        count++;
        temp = temp->next;
    } while(temp != start);

    return count;
}
void CLLInsert(int v,int pos)
{
    int count = CLLCountNodes();
    if(pos < 1 || pos > count + 1)
    {
        printf("\nCannot Insert in CLL - Invalid Position");
        return;
    }
    CNode *newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = v;
    if(start == NULL)
    {
        newNode->next = newNode;
        start = newNode;
    }
    else if(pos == 1)
    {
        CNode *temp = start;
        while(temp->next != start)
            temp = temp->next;
        newNode->next = start;
        temp->next = newNode;
        start = newNode;
    }
    else
    {
        CNode *temp = start;
        for(int i=1;i<pos-1;i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("\n%d is inserted into CLL at position %d",v,pos);
}
void CLLDelete(int pos)
{
    int count = CLLCountNodes();
    if(start == NULL || pos < 1 || pos > count)
    {
        printf("\nCannot Delete from CLL - Invalid Position or CLL Empty");
        return;
    }
    CNode *temp = start;
    int val;
    if(pos == 1)
    {
        if(start->next == start)
        {
            val = start->data;
            free(start);
            start = NULL;
        }
        else
        {
            CNode *last = start;
            while(last->next != start)
                last = last->next;

            val = start->data;
            last->next = start->next;
            start = start->next;
            free(temp);
        }
    }
    else
    {
        CNode *prev = NULL;
        for(int i=1;i<pos;i++)
        {
            prev = temp;
            temp = temp->next;
        }
        val = temp->data;
        prev->next = temp->next;
        free(temp);
    }
    printf("\nDeleted Node form CLL is %d from position %d",val,pos);
}
void CLLDisplay()
{
    if(start == NULL)
    {
        printf("\nCLL Empty-Nothing to Display");
        return;
    }
    CNode *temp = start;
    printf("\nCLL elements are :");
    do
    {
        printf("%d ->",temp->data);
        temp = temp->next;
    } while(temp != start);
}
void CLLSearch(int x)
{
    if(start == NULL)
    {
        printf("\nCLL Empty - Cannot search");
        return;
    }
    CNode *temp = start;
    do
    {
        if(temp->data == x)
        {
            printf("\n%d is found in CLL",x);
            return;
        }
        temp = temp->next;
    } while(temp != start);
    printf("\n%d is not found in CLL",x);
}
void CLLRevDisplay(CNode *temp)
{
    static CNode *first = NULL;
    if(temp == start && first == NULL)
        first = temp;
    if(temp->next != first)
        CLLRevDisplay(temp->next);
    printf("%d ->",temp->data);
}
int main()
{
    int ch,val,p;
    printf("\nCLL OPERATIONS");
    while(1)
    {
        scanf("%d",&ch);
        switch(ch) 
        {
            case 1:
                scanf("%d %d",&val,&p);
                CLLInsert(val,p);
                break;
            case 2:
                scanf("%d",&p);
                CLLDelete(p);
                break;
            case 3:
                CLLDisplay();
                break;
            case 4:
                scanf("%d",&val);
                CLLSearch(val);
                break; 
            case 5:
                printf("\nNo of nodes in CLL = %d",CLLCountNodes());
                break;
            case 6:
                if(start==NULL)
                    printf("\nEMPTY CLL - NOTHING TO REV DISPLAY");
                else
                {
                    printf("\nCLL Reverse Display :");
                    CLLRevDisplay(start);
                }
                break;   
            case 7:
                exit(0);
            default:
                printf("\nInvalid Choice");
                break;
        }
    }
    return 0;
}
