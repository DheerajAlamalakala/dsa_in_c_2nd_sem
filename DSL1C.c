/*
DS LAB TASK 1C
1c. Write a C programto implement Circular Queue operations using arrays
Write a C program to implement the folowing operations on CIRCULAR QUEUE
NOTE : 1.ENQUEUE 2.DEQUEUE 3.DISPLAY 4.EXIT/STOP

NOTE: ASSUME MAX SIZE OF QUEUE AS 4
Also check for "Invalid Option"
INPUT FORMAT:OPERATIONS AS INTEGERS GIVEN IN NOTE AND TERMINATED ALWAYS BY EXIT OPERATION.
OUTPUT FORMAT: AS PER THE TEST CASE

TESTCASES:

case = t1 
input = 1 
10
1
20
1
30
1
40
1
50
4
output = " QUEUE IS FULL " 

case = t4
input = 1                                                                               
10                                                                              
20   
4
output =
" INVALID CHOICE "


CHECK OUTPUT OF ALL THE GIVEN OPERATIONS
NOTE:JUST REMEMBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY. 
*/
//Start writing program from here
#include<stdio.h>
#define MAX 4
int front = -1,rear = -1;
int queue[MAX];
void enqueue()
{
    int n;
    scanf("%d",&n);
    if((rear==MAX-1 && front == 0)||(rear == front - 1))
    printf(" QUEUE IS FULL \n");
    else{
        if(front==-1){
            rear++;
            front++;
        }
        else if(rear == MAX-1)
        {
            rear=0;
        }
        else
        rear++;
        queue[rear]=n;
    }
}
void dequeue()
{
    int x;
    if(front == -1)
    printf("QUEUE IS UNDERFLOW \n");
    else{
        if(front==rear){
            printf("DELETED ELEMENT IN QUEUE = %d\n",queue[front]);
            front = rear = -1;
        }
        else if(front == MAX-1)
            front = 0;
        else
        printf("DELETED ELEMENT IN QUEUE = %d\n",queue[front++]);
    }
}
void display()
{
    int i;
    if(front==-1)
    printf(" QUEUE IS EMPTY ");
    else{
        if(front<=rear){
            for(i=front;i<=rear;i++)
            printf("%d  ",queue[i]);
        }
        else{
            for(i=front;i<=MAX-1;i++)
            printf("%d  ",queue[i]);
            for(i=0;i<=rear;i++)
            printf("%d  ",queue[i]);
        }
    }
    printf("\n");
}
int main()
{
    int ch,a=1;
    while(a==1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4:a=0;
            break;
            default:printf(" INVALID CHOICE \n");
        }
    }
}
