/* 
LAB TASK 12B
QUESTION:
Task 12B. Write a program to implement the following Hash Functions:
i)	 Division Method ii) Multiplication Method, iii) Mid-square Method iv) Folding Method
NOTE: ASSUME THE TABLE SIZE TO BE <=100.
INPUT : ENTER 2 POSITIVE INTEGERS KEY VALUE AND TABLE SIZE.
OUTPUT: DISPAY THE HASH INDEX OF VARIOUS HASH FUNCTIONS AS PER THE GIVEN TEST CASE
SAMPLE TEST CASE :
case = t2
input=
768
15
output=
"
KEY = 768 AND Table size = 15
Hash Function - Hash Index values:
Division Method         : 3
Multiplication Method   : 9
Mid-Square Method       : 2
Folding Method          : 9"
*/
//Start writing program from here
#include <stdio.h>
#include <math.h>
int DIVMethod(int key, int tableSize);
int MULMethod(int key, int tableSize);
int MIDSQRMethod(int key, int tableSize);
int FOLDMethod(int key, int tableSize);

int main()
{
    int n,key, tableSize;
    //printf("Enter the key value: ");
    scanf("%d", &key);
   // printf("Enter hash table size: ");
    scanf("%d", &tableSize);
    printf("\nKEY = %d AND Table size = %d",key,tableSize);
    printf("\nHash Function - Hash Index values:");
    printf("\nDivision Method         : %d", DIVMethod(key, tableSize));
    printf("\nMultiplication Method   : %d", MULMethod(key, tableSize));
    printf("\nMid-Square Method       : %d", MIDSQRMethod(key, tableSize));
    printf("\nFolding Method          : %d", FOLDMethod(key, tableSize));
    return 0;
}

// (i) Division Method 
int DIVMethod(int key, int tableSize)
{
 return key % tableSize;
}

// (ii) Multiplication Method 
int  MULMethod(int key, int tableSize)
{
 double A = 0.61803;       //0.6180339887;   // Constant (0 < A < 1)
 double frac = key * A;
 frac = frac - (int)frac;
 return (int)(tableSize * frac);
}

// (iii) Mid-Square Method 
int MIDSQRMethod(int key, int tableSize)
{
 long square = key * key;
 int mid;
// Extract middle digits 
 square = square / 10;   // remove last digit
 mid = square % tableSize;
 return mid;
}

// (iv) Folding Method 
int FOLDMethod(int key, int tableSize)
{
 int sum;
 int ndig=log10(key)+1;
 if(ndig%2!=0)
 {
  sum=key%10;
  key=key/10;
 }
 else
 sum=0;
 while(key > 0) 
 {
  sum += key % 100;   // split into 2-digit parts
  key /= 100;
 }
 return sum % tableSize;
}
