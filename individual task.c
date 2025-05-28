#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//2 лабораторная работа 2 семестра 1 курса(индивидуальное задание)
int** createMatrixMemory(size_t rows, size_t cols)
{
    int** matrix = (int**)malloc(rows * sizeof(int*));//строки
    if (matrix) 
    {
        for (size_t i = 0; i < rows; i++) 
        {
            matrix[i] = (int*)malloc(cols * sizeof(int));//столбцы
            if (matrix[i] == NULL) 
            {
                for (int j = 0; j < i; j++) 
                {
                    free(matrix[j]);
                }
                free(matrix);
                return NULL;
            }
        }
        return matrix;
    }
    return NULL;
}
//1
int** createMatrix(size_t rows, size_t cols, int rangeA, int rangeB, int a, int b) 
{
    if (rangeA>rangeB)
    {
       int tmp=rangeA;
       rangeA=rangeB;
       rangeB=tmp;
    }
    int** matrix=createMatrixMemory(rows, cols);
    if (matrix==NULL)
    {
        return 0;
    }
    for (size_t i = 0; i < rows; i++) 
    {
        for (size_t j = 0; j < cols; j++) 
        {
            matrix[i][j] = rand() % (rangeB - rangeA + 1) + rangeA;
        }
    }
    a=rand() % (rows - 0)+ 1;
    for(size_t i = 0; i < a; i++)
    {
        b=rand() % (rows - 0);
        for(size_t j=0; j<cols; j++)
        {
            matrix[b][j]=0;
        }
    }

    return matrix;
}

//2
void freeMatrix(int** matrix, size_t rows) 
{
 
    for (size_t i = 0; i < rows; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
}

//3
void printMatrix(int** matrix, size_t rows, size_t cols) 
{
    if (matrix)
    {
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
               printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}
//4 
int** PartitionRow(int** matrix, size_t partitionRow1, size_t partitionRow2, size_t cols, int w)
{
    int** mt=createMatrixMemory(partitionRow2, cols);
    if(mt==NULL)
    {
        return 0;
    }
    for(size_t i=0; i<partitionRow2; i++)
    {
        w=i+partitionRow1;
        for(size_t j=0; j<cols; j++)
        {
            mt[i][j]=matrix[w][j];
        }
    }
    return mt;
}
//5
int** additionMatrix(int** mt1, int** mt2, size_t t, size_t partitionRow2, size_t cols, int w)
{
    if(w==partitionRow2)
    {
        for(size_t i=0; i<w; i++)
        {
            for(size_t j=0; j<cols; j++)
            {
                mt2[i][j]=mt2[i][j]+mt1[i][j];
            }
        }
        return mt2;
    }
    for(size_t i=0; i<w; i++)
    {
        for(size_t j=0; j<cols; j++)
        {
            mt1[i][j]=mt1[i][j]+mt2[i][j];
        }
    }
    return mt1;
}
int main() 
{
    size_t rows=7, cols=7, partitionRow1 = 0, partitionRow2=3, t=rows-partitionRow2;
    int rangeA=20, rangeB=5, a=0, b=0, w=0;
    
    int** matrix = createMatrix(rows, cols, rangeA, rangeB, a, b);
    if (matrix == NULL) 
    {
        freeMatrix(matrix,rows);
        printf("Failed to create matrix\n");
        return 0;
    }
    printf("Matrix:\n");
    printMatrix(matrix, rows, cols); 
    
    
    printf("Mt1:\n");
    int** mt1=PartitionRow(matrix, partitionRow1, partitionRow2, cols, w);
    printMatrix(mt1, partitionRow2, cols);
    printf("Mt2:\n");
    int** mt2=PartitionRow(matrix, partitionRow2 ,t, cols, w);
    printMatrix(mt2, t, cols);
    if (mt1==NULL || mt2==NULL)
    {
        freeMatrix(mt1, partitionRow2);
        freeMatrix(mt2, t);
        return 0;
    }
    
    
    printf("addition:\n");
    w=t;
    int q=partitionRow2;
    if(t>partitionRow2)
    {
        w=partitionRow2;
        q=t;
    }
    int** MT=additionMatrix(mt1, mt2, t, partitionRow2, cols, w);
    printMatrix(MT,q,cols);
    
    
    freeMatrix(matrix, rows);
    freeMatrix(mt1, partitionRow2);
    freeMatrix(mt2, t);
    
    return 0;
}