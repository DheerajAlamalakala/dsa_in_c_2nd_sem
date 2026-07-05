/* 
LAB TASK 9C
QUESTION: 9C- Design a C program for Radix Sort.

INPUT FORMAT:
FIRST LINE CONTAINS "n" THE SIZE OF THE LIST
SECOND LINE CONTAINS "n" integers seperated by a space

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE.
THE VALUES ARE DISPLAYED BY A TRAILING SPACE.

Test Cases:
case = t1
input = 6
502 674 175 542 874 245
output = 
"UNSORTED LIST
502	674	175	542	874	245	
RADIX SORT
SORTED LIST
175	245	502	542	674	874 "	
*/
//Start writing program from here
#include <stdio.h>

void radixSort(int a[], int n)
{
    int bkt[10][100], bktCount[10];
    int i, j, k, rem, pass, divisor = 1;
    int big = a[0];

    for(i = 1; i < n; i++)
    {
        if(a[i] > big)
            big = a[i];
    }

    int NOP = 0;
    while(big > 0)
    {
        NOP++;
        big /= 10;
    }

    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 10; i++)
            bktCount[i] = 0;

        for(i = 0; i < n; i++)
        {
            rem = (a[i] / divisor) % 10;
            bkt[rem][bktCount[rem]] = a[i];
            bktCount[rem]++;
        }

        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bktCount[k]; j++)
            {
                a[i] = bkt[k][j];
                i++;
            }
        }

        divisor *= 10;
    }
}

int main()
{
    int n, i;

    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("UNSORTED LIST\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nRADIX SORT\n");

    radixSort(a, n);

    printf("SORTED LIST\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
