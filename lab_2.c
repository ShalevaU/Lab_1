#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//2 лабораторная работа 2 семестра 1 курса
//1
int** createMatrix(size_t rows, size_t cols, int rangeA, int rangeB) 
{
    if (rangeA>rangeB)
    {
       int tmp=rangeA;
       rangeA=rangeB;
       rangeB=tmp;
    }
    if (rows==0 || cols==0)
    {
        return 0;
    }
    int** matrix = (int**)malloc(rows * sizeof(int*));//строки
    if (matrix == NULL) 
    {
        return 0;
    }

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

    for (size_t i = 0; i < rows; i++) 
    {
        for (size_t j = 0; j < cols; j++) 
        {
            matrix[i][j] = rand() % (rangeB - rangeA + 1) + rangeA;
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

int main() 
{
    size_t rows=3, cols=3;
    int rangeA=5, rangeB=20;

    int** matrix = createMatrix(rows, cols, rangeA, rangeB);
    if (matrix == NULL) 
    {
        printf("Failed to create matrix\n");
        return 0;
    }

    printf("Matrix:\n");
    printMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);

    return 0;
}
