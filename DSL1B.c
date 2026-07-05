/*
DS LAB TASK 1B
1b. Write a C program to implement QUEUE operations using array
Write a C program to implement the folowing operations on QUEUE using arrays.
NOTE : 1.ENQUEUE 2.DEQUEUE 3.DISPLAY 4.EXIT/STOP

NOTE: ASSUME MAX SIZE OF QUEUE AS 4
Also check for "Invalid Option"
INPUT FORMAT:OPERATIONS AS INTEGERS GIVEN IN NOTE AND TERMINATED ALWAYS BY EXIT OPERATION.
OUTPUT FORMAT: AS PER THE TEST CASE

TEST CASES:
case = t2
input = 
3
2
4
output = 
"QUEUE OPERATIONS USING ARRAY
Nothing to Display - QUEUE EMPTY
Cannot Dequeue - QUEUE UNDERFLOW"

case = t3
input = 
1 10
1 20
3
2
2
2
3
4
output =
"QUEUE OPERATIONS USING ARRAY
20 is added into Q[1]
The elements of QUEUE are : 10 20 
10 is dequeued from Q[0]
20 is dequeued from Q[1]
Cannot Dequeue - QUEUE UNDERFLOW
Nothing to Display - QUEUE EMPTY"

CHECK OUTPUT OF ALL THE GIVEN OPERATIONS
NOTE:JUST REMEMBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY. 
*/
//Start writing program from here
#include<stdio.h>
#define MAX 4
int front=-1,rear=-1;
int queue[MAX];
void enqueue()
{
    int a;
    scanf("%d",&a);
    if(rear ==MAX-1)
    printf("Cannot Enqueue - QUEUE OVERFLOW\n");
    else{
        if(front ==-1)
        front =0;
        rear++;
        queue[rear]=a;
        printf("%d is added into Q[%d]\n",a,rear);
    }
}
void dequeue()
{
    if(front ==-1)
    printf("Cannot Dequeue - QUEUE UNDERFLOW\n");
    else{
        printf("%d is dequeued from Q[%d]\n",queue[front],front);
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }
    
}
void display()
{
    if(rear==-1)
    printf("Nothing to Display - QUEUE EMPTY\n");
    else{
        int i;
        printf("The elements of QUEUE are : ");
        for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
        printf("\n");
    }
}
int main()
{
    int ch,a=1;
    printf("QUEUE OPERATIONS USING ARRAY\n");
    while(a==1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: a=0;
            break;
            default: printf("Invalid Choice");
        }
    }
}

