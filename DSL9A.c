/* 
LAB TASK 9A
QUESTION: 9a-Develop a C program for Quick sort.

INPUT FORMAT:
FIRST LINE CONTAINS "n" THE SIZE OF THE LIST.
SECOND LINE CONTAINS "n" integers seperated by a space.

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE
THE OUTPUT VALUES ARE SEPERATED BY A TRAILING SPACE.

Test Cases:
case = t1
input = 6
-1 6 -45 -8 0 4
output = 
"Unsorted List
-1	6	-45	-8	0	4	
QUICK SORT
Sorted List
-45	-8	-1	0	4	6 "
*/
//Start writing program from here
#include <stdio.h>

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
    int n, i;
    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Unsorted List\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    quickSort(a, 0, n - 1);

    printf("\nQUICK SORT\n");
    printf("Sorted List\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}
