/*LAB TASK 10B
TASK 10B- Demonstrate Heap sort using a C program
INPUT FORMAT:
FIRST LINE CONTAINS "n" THE SIZE OF THE LIST.
SECOND LINE CONTAINS "n" integers seperated by a space.

OUTPUT FORMAT:
DISPLAY UNSORTED LIST,SORTING METHOD NAME AND SORTED LIST AS PER THE TEST CASE
THE OUTPUT VALUES ARE SEPERATED BY A TRAILING SPACE.

Test Cases:
case = t6
input=10
0 9 8 7 6 5 4 3 2 1  
output = 
"
UNSORTED LIST
0 9 8 7 6 5 4 3 2 1 
HEAP SORT
SORTED LIST
0 1 2 3 4 5 6 7 8 9 "

*/
//Start writing program from here
#include<stdio.h>
 void swap(int *a, int *b)
 {
     int temp = *a;
     *a=*b;
     *b=temp;
 }
void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left< n && arr[left]>arr[largest])
    largest = left;
    if(right<n && arr[right]>arr[largest])
    largest = right;
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[], int n)
{
    for(int i = n/2 -1 ; i>=0;i--)
    heapify(arr,n,i);
    for(int i = n-1; i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void printarr(int arr[], int n)
{
    printf("\n");
    for(int i =0; i<n;++i)
    printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("\nUNSORTED LIST");
    printarr(arr,n);
    printf("HEAP SORT");
    heapsort(arr,n);
    printf("\nSORTED LIST");
    printarr(arr,n);
    return 0;
}















