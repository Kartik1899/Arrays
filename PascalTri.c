/* Pascal Triangle */
#include<stdio.h>
#include<stdlib.h>

int** getPascal(int size)
{
    int i,j;

    int **pTri = (int **)malloc(size * sizeof(int *));          // Dynamically allocating 2d Array 
    for(i = 0 ; i < size ; i++)
    {
        pTri[i] = (int *)malloc((i+1) * sizeof(int));
        j++;
    }


    pTri[0][0] = 1;                                            // Initializing Pascal Triangle

    for(i = 1 ; i < size ; i++)
    {
        pTri[i][0] = 1;                                       // First and last element of every row is always 1
        pTri[i][i] = 1;
        for(j = 1; j < i; j++)
        {
            pTri[i][j] = pTri[i-1][j-1] + pTri[i-1][j];
        }

    }
    return pTri;
}


/*----------------------MAIN BODY------------------*/
int main()
{
    int size;
    scanf("%d",&size);

    int **pascalTriangle = getPascal(size);
    int i,j;
    for(i = 0 ; i < size ; i++)
    {
        for(j = 0; j <= i ; j++)
        {
            printf("%d ",pascalTriangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}