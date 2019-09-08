/* 

Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list. 
Remove leading zero's in the output.

Input =  0 0 0 9 9 
Output = 1 0 0; ( 99 + 1)

Input = 9 9 9 9;
Output = 1 0 0 0 0; ( 9999 + 1)

Input = 1 2 3;
Output = 1 2 4; ( 123 + 1)

*/

#include<stdio.h>
#include<stdlib.h>


int* addOne(int *givenArr, int size, int *len)                                      // Addition function
{
    int tempSize = size - 1;
    int i;
    int carry = 0;

    do {
        if(carry > 0)                                                       // Checking for carry value and adding it
        {
            givenArr[tempSize] += carry;
            if(givenArr[tempSize] >= 10)
            {
                carry = givenArr[tempSize] / 10;
                givenArr[tempSize] %= 10;
            }
            else
            {
                carry = 0;
            }
            tempSize--;
        }
        else                                                                // Adding 1 to the last element. This will run first and once in all cases.
        {
            givenArr[tempSize] += 1;
            if(givenArr[tempSize] >= 10)
            {
                carry = givenArr[tempSize] / 10;
                givenArr[tempSize] %= 10;
            }
            else
            {
                carry = 0;
            }
            tempSize--;            
        }        
    } while(carry > 0 && tempSize != -1);

    int *resultArray = (int *)malloc((size)*sizeof(int));                   // Array to store incremented number


    int countZero = 0;
    for(i = 0 ; i < size; i++)                                              // Counting leading 0's
    {
        if(givenArr[i] != 0)
        {
            break;
        }
        countZero++;
    }

    int index = 0;

/* Adding elements in the resultant array */
    if(carry > 0)
    {
        resultArray = (int *)realloc(resultArray, (size+1)*sizeof(int));
        resultArray[index++] = carry;
    }

    i = countZero < size ? countZero : 0;

    for(i ; i < size ; i++)
    {
        resultArray[index++] = givenArr[i];
    }


    *len = index;                                                   // storing the size of resultant array
    return resultArray;
}



/*--------------------------------Main Body--------------------------*/
int main()
{
    int size;
    scanf("%d",&size);
    int i;
    int givenArr[size];

    for(i = 0 ; i < size ;i++)
    {
        scanf("%d",&givenArr[i]);
    }

    int len;
    int *resultArray = addOne(givenArr,size,&len);

    for(i = 0 ; i < len ; i++)
    {
        printf("%d ",resultArray[i]);
    }
    return 0;
}
