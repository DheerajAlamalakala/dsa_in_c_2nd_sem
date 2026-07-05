/*2a. Write a C program to implement INFIX TO POSTFIX conversion.
INPUT FORMAT: READ THE POSTFIX EXPRESSION AS A STRING
OUTPUT FORMAT: DISPLAY THE RESULTANT POSTFIX EXPRESSION AS PER TEST CASE.
NOTE: CHECK ALL INVALID CASES
1.Invalid Infix Expression - Missing close braces
2.Stack underflow - Open Brace Missing
3.Incorrect Infix Expression - Invalid Symbols

SAMPLE TEST CASES:
case=t8
input=a+b-c)
output=
"Given Infix expression is : a+b-c)
Stack underflow - Open Brace Missing"

case=t9
input=a+b*c-(d+e)
output=
"Given Infix expression is : a+b*c-(d+e)
Postfix expression  is : abc*+de+-"
*/
//Start writing program from here

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '^')
        return 3;
    return 0;
}

int main()
{
    char exp[100],postfix[100];
    int i = 0,j = 0;
    char x;
    scanf("%s", exp);
    printf("Given Infix expression is : %s\n",exp);
   
    while(exp[i] != '\0')
    {
        if(isalnum(exp[i]))
        {
            postfix[j++] = exp[i];
        }
        else if(exp[i] == '(')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            while((x = pop()) != '(')
            {
                if(top!=-1)
                postfix[j++]= x;
                else{
                    printf("Stack underflow - Open Brace Missing");
                    return 1;
                }
            }
               
        }
        else if(exp[i]=='%'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='^')
        {
            while(priority(stack[top]) >= priority(exp[i]))
                postfix[j++] = pop();

            push(exp[i]);
        }
        else
        {
            printf("Incorrect Infix Expression - Invalid Symbols");
            return 1;
        }

        i++;
    }

    while(top != -1)
    {
        if(stack[top]=='('){
            printf("Invalid Infix Expression - Missing close braces");
            return 1;
        }
        else
        postfix[j++] = pop();
    }
    postfix[j]='\0';
    printf("Postfix expression  is : ");
    printf("%s",postfix);


    return 0;
}
