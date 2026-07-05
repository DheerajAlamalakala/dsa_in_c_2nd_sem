/*
DS LAB TASK 5
5. Write a C program to implement Double Linked List operations – create, insert, delete and display.

PERFORM THE BELOW DLL OPERATIONS:
1.Insert 2.Delete 3.Display 4.Search 5.Reverse Display 6.Exit
Also check for "Invalid Choice"
NOTE : FOR INSRET FIRST READ POSITION THEN LATER READ THE VALUE IF THE POSITION IS IN VALID RANGE. 

INPUT FORMAT: AS PER TEST CASES.
OUTPUT FORMAT AS PER TEST CASES.

SAMPLE TEST CASES:

case = t8
input = 
1
10
2
1
34
3
4
200
5
6
output =
IMPLEMENTING OPERATIONS ON DOUBLE LINKED LIST.
Position does not exist - Cannot insert into DLL
Position does not exist - Cannot delete from DLL
Invalid Choice
Empty DLL - Cannot Display.
DLL Empty - Cannot Search
Empty DLL - Cannot Perform Reverse Display.

CASE=T9
INPUT=
1
1
100
1
2
200
1
3
300
4
300
3
4
250
6
OUTPUT=
IMPLEMENTING OPERATIONS ON DOUBLE LINKED LIST.
300 is found in DLL
THE DLL ELEMENTS :
100 ->200 ->300 ->
250 is not found in DLL

CHECK OUTPUT FOR ALL THE GIVEN OPERATIONS INCLUDING INVALID CASES
NOTE : JUST REMEMEBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY.
       PREFER A "\n" BEFORE EVERY PRINTF STATEMENT.
*/
//Start writing program from here



#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void insert();
void delete_node();
void display();
void search();
void reverse_display();
int main()
{
    int choice;

    printf("IMPLEMENTING OPERATIONS ON DOUBLE LINKED LIST.\n");

    while (1)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_node();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            reverse_display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
struct node *head = NULL;
int count()
{
    int c = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
void insert()
{
    int pos, val, i;
    scanf("%d", &pos);
    int n = count();
    if (pos < 1 || pos > n + 1)
    {
        printf("Position does not exist - Cannot insert into DLL\n");
        return;
    }
    scanf("%d", &val);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (pos == 1)
    {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
    }
}
void delete_node()
{
    int pos, i;
    scanf("%d", &pos);
    int n = count();
    if (pos < 1 || pos > n)
    {
        printf("Position does not exist - Cannot delete from DLL\n");
        return;
    }
    struct node *temp = head;
    if (pos == 1)
    {
        int deleted=temp->data;
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Deleted element from DLL is %d\n",deleted);
    }
    else
    {
        for (i = 1; i < pos; i++)
            temp = temp->next;
          int deleted = temp->data;
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        free(temp);
         printf("Deleted element from DLL is %d\n",deleted);
    }
}
void display()
{
    if (head == NULL)
    {
        printf("Empty DLL - Cannot Display.\n");
        return;
    }
    struct node *temp = head;
    printf("THE DLL ELEMENTS :\n");
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void search()
{
    int key, found = 0;
    scanf("%d", &key);
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("%d is found in DLL\n", key);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found)
        printf("%d is not found in DLL\n",key);
}
void reverse_display()
{
    if (head == NULL)
    {
        printf("Empty DLL - Cannot Perform Reverse Display.\n");
        return;
    }

    struct node *temp = head;
    printf("DLL REVERSE DISPLAY\n");
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
