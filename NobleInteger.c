/* 
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/

#include<stdio.h>
#include<stdlib.h>

int compareTo(const void* a, const void*b)                                              // Comparator
{
    return (*(int*)a - *(int*)b);
}


int checkNobleInteger(int *givenArray, int size)
{
    
    qsort(givenArray,size,sizeof(givenArray[0]),compareTo);                             // Using qsort to sort array

    int i;
    
    if(givenArray[size -1 ] == 0)                                             // If 0 is last element, then array is of negative integer, hence condition satisfied
    {
        return 1;
    }
    
    for(i = 0 ; i < size ; i++)
    {
        if(givenArray[i] == size - 1 - i && givenArray[i] != givenArray[i+1])           // Checking for noble integer
        {
            return 1;                                                               
        }
    }

    return -1;
}


/*------------------------------------------MAIN BODY---------------------------------*/
int main()
{
    int size;
    scanf("%d",&size);
    int givenArray[size];
    int i;
    for(i = 0 ; i < size ; i++)
    {
        scanf("%d",&givenArray[i]);
    }

    printf("%d",checkNobleInteger(givenArray,size));

    return 0;
}