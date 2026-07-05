/*DS LAB
TASK 2B Write a C program to evalulate a postfix expression.
INPUT FORMAT:
Enter a mathematical expression in postfix notation.
Ensure that operands(numbers)and operators(+, -, *, /) are not separated by spaces.
OUTPUT FORMAT: 
Result after evaluation of the Postfix Expression.
or
Error codes for invalid expressions as per test cases.

Test Cases:

Case=t8
Input=ab*c-d+
25
7
14
6
Output=
"Result of Postfix expression ab*c-d+ = 167"

Case=t2
Input=ab*c-d+
25
7
14
6
Output=
"Result of Postfix expression ab*c-d+ = 167"

case=t4
input=
ab$
2
0
output=
"Invalid symbols in the Postfix Expression"

*/
//Start writing program from here
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int a)
{
    if(top==MAX-1)
    {
        printf("overflow");
        exit(0);
    }else{
        stack[++top]=a;
    }
}
int pop()
{
    if(top==-1){
        printf("Stack underflow - Missing Operands");
        exit(0);
    }else{
        return stack[top--];
    }
}

int main()
{
    char s[20];
    int n1,n2,n3,a;
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(isalpha(s[i]))
        {
            scanf("%d",&a);
            push(a);
        }
        else if(isdigit(s[i])){
            push(s[i]-'0');
        }
        else{
            if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'){
                printf("Invalid symbols in the Postfix Expression");
                exit(0);
            }
            n2 = pop();
            n1= pop();
            if(s[i]=='+')
            n3=n1+n2;
            else if(s[i]=='-')
            n3=n1-n2;
            else if(s[i]=='*')
            n3=n1*n2;
            else if(s[i]=='/')
            n3=n1/n2;
           
            push(n3);
        }
        
    }
    if(top==0){
    printf("Result of Postfix expression %s = %d",s,stack[top]);
    }else{
        printf("Invalid or Incomplete  Postfix expression");
    }
}
