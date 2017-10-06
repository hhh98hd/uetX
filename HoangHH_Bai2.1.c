#include <stdio.h>
#include <stdint.h>
#define MAX 100
/**
 *  Only square matrices of the same size are valid for both summing 
 *  and multiplication.
 */
/* Input data for matrix */
void inputMatrix(int matrix[MAX], int size)
{
    int i;
    for (i = 0; i < size * size; ++i)
    {
        scanf("%d", &matrix[i]);
    }
}
/* Print matrix */
void outputMatrix(int matrix[MAX], int size)
{
    uint8_t i;
    for (i = 0; i < size * size; ++i)
    {
        /* Newline after finish each row of matrix */
        if (i % size == 0)
        {
            printf("\n");
        }
        printf("%.2f  ", matrix[i]);
    }
}
/* Transpose matrix */
void trnMatrix(int mat[MAX], int row, int col)
{
    int i, j, index1, index2;
    int result[MAX];
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            index1 = i * col + j;
            index2 = j * row + i;
            result[index2] = mat[index1];
        }
    }
    for (i = 0; i < row * col; ++i)
    {
        mat[i] = result[i];
    }
}
/* Calculate sum of 2 matrices and print result */
void sumMatrixAndOutput(int matrixA[MAX],int matrixB[MAX], int size)
{
    uint8_t i;
    int result[MAX];
    /* Calculate result */
    for (i = 0; i < size * size; ++i)
    {
        result[i] = matrixA[i] + matrixB[i];
    }
    /* Print result */
    outputMatrix(result, size);
}
/* Multiply 2 matrices and print result */
void multiMatrixAndOutput(int matA[MAX], int matB[MAX],
                          uint8_t rowA, uint8_t rowB,
                          uint8_t rowB, uint8_t colB)
{
    uint8_t i, j, k;
    /* Multiplication */
    float result[MAX], sum;
    for (i = 0; i < rowA; ++i)
    {
        for (j = 0; j < colB; ++j)
        {
            sum = 0;
            for (k = 0; k < rowB; ++k)
            {
                sum += matA[i * colA + k] * matB[k * colB + j];
                result[i * colB + j] = sum;
            }
        }
    }
    /* Print result */
    outputMatrix(result, size);
}
int main()
{
	int matrixA[MAX], matrixB[MAX];
    int size;
    /* Make sure that size is valid */
    do
    {
        printf("Enter size: ");
        scanf("%d", &size);
        if (size <= 0)
        {
            printf("Dimension error !\n");
        }
    } while (size <= 0);
    /* Enter data for matrices */
    printf("Enter data of matrix A: \n");
    inputMatrix(matrixA, size);
    printf("Matrix A: \n");
    outputMatrix(matrixA, size);
    printf("\n \n");
    printf("Enter data of matrix B: \n");
    inputMatrix(matrixB, size);
    printf("Matrix B: \n");
    outputMatrix(matrixB, size);
    printf("\n \n");
    /* Print result */
    printf("Result: \n \n");
    printf("A + B =  ");
    sumMatrixAndOutput(matrixA, matrixB, size);
    printf("\n");
    printf("A x B =  ");
    multiMatrixAndOutput(matrixA, matrixB, size);
    return 0;
}
