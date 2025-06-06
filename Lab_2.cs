﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//2 лабораторная работа 2 семестра 1 курса
//1
int** CreateMatrix(size_t rows, size_t cols, int rangeA, int rangeB)
{
    if (rangeA > rangeB)
    {
        int tmp = rangeA;
        rangeA = rangeB;
        rangeB = tmp;
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
void FreeMatrix(int** matrix, size_t rows)
{
    if (matrix)
    {
        for (size_t i = 0; i < rows; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    }
}

//3
void PrintMatrix(int** matrix, size_t rows, size_t cols)
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
    size_t rows = 3, cols = 3;
    int rangeA = -20, rangeB = 5;

    int** matrix = CreateMatrix(rows, cols, rangeA, rangeB);
    if (matrix == NULL)
    {
        printf("Failed to create matrix\n");
        return 0;
    }

    printf("Matrix:\n");
    PrintMatrix(matrix, rows, cols);

    FreeMatrix(matrix, rows);

    return 0;
}