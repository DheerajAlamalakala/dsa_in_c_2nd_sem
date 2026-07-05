/*
DS LAB TASK 1A
1a. Write a C program to implement STACK operations using array
Write a C program to implement the folowing operations on STACKS using arrays.
1.PUSH 2.POP 3.PEEP 4.PEAK 5.EXIT/STOP

NOTE: ASSUME MAX SIZE OF STACK AS 4
Also check for "Invalid Option"
INPUT FORMAT:OPERATIONS AS INTEGERS GIVEN IN NOTE AND TERMINATED ALWAYS BY EXIT OPERATION.
OUTPUT FORMAT: AS PER THE TEST CASE

TEST CASES:
case=t6
input=
1 10
1 20
2
3
4
5
output=
"STACK OPERATIONS USING ARARYS
10 is Pushed into stack[0]
20 is Pushed into stack[1]
20 is Popped from stack[1]
The elements of Stack are :10 
Top Most element of the Stack is 10"

case = t1
input=
2
3
4
5
output=
"STACK OPERATIONS USING ARARYS
Cannot POP - STACK UNDERFLOW
Nothing to display - Stack Empty
No PEAK - Stack Empty"

NOTE:
CHECK OUTPUTS FOR ALL THE GIVEN OPERATIONS
NOTE : JUST REMEMEBER EVERY TEST CASE MUST END WITH EXIT OPERATION SO THAT IT WILL STOP FINITELY. 
*/
//Start writing program from here
#include<stdio.h>
#define MAX 4
int stack[MAX];
int top =-1;
void push()
{
    int x;
    scanf("%d",&x);
    if(top==MAX-1)
    printf("Cannot PUSH - STACK OVERFLOW\n");
    else{
        top++;
        stack[top]=x;
        printf("%d is Pushed into stack[%d]\n",x,top);
    }
}
void pop()
{
    if(top==-1)
    printf("Cannot POP - STACK UNDERFLOW\n");
    else{
        printf("%d is Popped from stack[%d]\n",stack[top],top);
        top--;
    }
}
void peek()
{
    if(top==-1)
    printf("Nothing to display - Stack Empty\n");
    else{
        printf("The elements of Stack are :");
        for(int i=top; i>=0;i--)
        printf("%d ",stack[i]);
        printf("\n");
    }
}
void peak(){
    if(top==-1)
    printf("No PEAK - Stack Empty\n");
    else{
        printf("Top Most element of the Stack is %d\n",stack[top]);
    }
}
int main()
{
    int ch, a=1;
    printf("STACK OPERATIONS USING ARRAYS\n");
    
    while(a==1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:peak();
            break;
            case 5:{a=0;
            break;
            }
            default:printf("Invalid Choice\n");
        }
    }
    return 0;
}
