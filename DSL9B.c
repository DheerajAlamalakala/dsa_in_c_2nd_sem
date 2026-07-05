/* 
LAB TASK 9B
QUESTION: 9B-Demonstrate Merge sort using a C program.

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
MERGE SORT
Sorted List
-45	-8	-1	0	4	6 "
*/
//Start writing program from here
#include<stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[100];

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergesort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

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

    printf("\nMERGE SORT\n");

    mergesort(a, 0, n - 1);

    printf("Sorted List\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
