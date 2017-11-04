#include <stdio.h>
#include <stdint.h>
#define MAX 100

/* Enter data for 2 matrices */
void inputMatrix(float array[MAX], float rowA, float colA, float rowB, 
                 float colB);
/* Enter size of matrix */
void inputSize(float *rowA, float *colA, float *rowB, float *colB);
/* Calculate of 2 matrices and print result */
void sumMatrixAndOutput(float array[MAX], float rowA, float colA, 
                        float rowB, float colB);
/* Do matrix multiplication and print result */
void multiMatrixAndOutput(float array[MAX], float rowA, float colA,
                          float rowB, float colB);
/* Print result after summing 2 matrices */
void sumOutput(float array[MAX], float rowA, float colA, float rowB, 
               float colB);
/* Print result of matrix multiplication */
void multiOutput(float array[MAX], float rowA, float colA,
                 float rowB, float colB);
/* Swap 2 numbers */
void swap(float *a, float *b);

int main()
{
    float array[MAX], rowA, rowB, colA, colB;
    inputSize(&rowA, &colA, &rowB, &colB);
    inputMatrix(array, rowA, colA, rowB, colB);
    if (rowA == rowB == colA == colB == 1)
    {
        printf("We do not deal with multiplication  of matrix and scalar!\n");
    }
    else
    {
        sumMatrixAndOutput(array, rowA, colA, rowB, colB);
        multiMatrixAndOutput(array, rowA, colA, rowB, colB);
    }
    return 0;
}

void inputSize(float *rowA, float *colA, float *rowB, float *colB)
{
    /* Tell user to enter number of rows in matrix A */
    do
    {
        printf("Enter number of rows in matrix A: \n");
        scanf("%f", &(*rowA));
        /* Notify error to user */
        if (*rowA <= 0)
        {
            printf("Size of a matrix must be larger than 0!\n");
        }
        else if (*rowA - (int)*rowA != 0)
        {
            printf("Size of a matrix must be an integer!\n");
        }
    } while ((*rowA - (int)*rowA != 0) || (*rowA <= 0));
    /* Tell user to enter number of columns in matrix A */
    do
    {
        printf("Enter number of columns in matrix A: \n");
        scanf("%f", &(*colA));
        /* Notify error to user */
        if (*colA <= 0)
        {
            printf("Size of a matrix must be larger than 0!\n");
        }
        else if (*colA - (int)*colA != 0)
        {
            printf("Size of a matrix must be an integer!\n");
        }
    } while ((*colA - (int)*colA != 0) || (*colA <= 0));
    /* Tell user to enter number of rows in matrix B */
    do
    {
        printf("Enter number of rows in matrix B: \n");
        scanf("%f", &(*rowB));
        /* Notify error to user */
        if (*rowB <= 0)
        {
            printf("Size of a matrix must be larger than 0!\n");
        }
        else if (*rowB - (int)*rowB != 0)
        {
            printf("Size of a matrix must be an integer!\n");
        }
    } while ((*rowB - (int)*rowB != 0) || (*rowB <= 0));
    /* Tell user to enter number of columns in matrix B */
    do
    {
        printf("Enter number of columns in matrix B: \n");
        scanf("%f", &(*colB));
        /* Notify error to user */
        if (*colB <= 0)
        {
            printf("Size of a matrix must be larger than 0!\n");
        }
        else if (*colB - (int)*colB != 0)
        {
            printf("Size of a matrix must be an integer!\n");
        }
    } while ((*colB - (int)*colB != 0) || (*colB <= 0));
}
void inputMatrix(float array[MAX], float rowA, float colA, 
                 float rowB, float colB)
{
    /* Only matrices of the same size are valid for summing */
    uint8_t i;
    /* Enter data for matrix A */
    printf("Enter data for matrix A: ");
    for (i = 0; i < rowA * colA; ++i)
    {
        scanf("%f", &array[i]);
    }
    /* Enter data for matrix B */
    printf("Enter data for matrix B: ");
    for (i = rowA * colA; i < rowA * colA + rowB * colB; ++i)
    {
        scanf("%f", &array[i]);
    }
    printf("\n");
}
void sumMatrixAndOutput(float array[MAX], float rowA, float colA,
                        float rowB, float colB)
{
    /* Check if input is valid for matrix summing */
    if ((rowA != rowB) || (colA != colB))
    {
        /* Notify error to user */
        printf("Dimension error. Unable to do matrix addition!\n");
    }
    else
    {
        /* Matrix A starts at i = rowA * colA, result matrix starts at 
         * i = rowB * colB + rowA * colA */
        uint8_t i, j = rowA * colA, k = rowA * colA + rowB * colB;
        for (i = 0; i < rowA * colA; ++i)
        {
            array[k] = array[i] + array[j];
            j++;
            k++;
        }
        /* Print result */
        sumOutput(array, rowA, colA, rowB, colB);
        printf("\n \n");
    }
}
void sumOutput(float array[MAX], float rowA, float colA, float rowB, float colB)
{
    uint8_t i, j = rowA * colA + rowB * colB;
    printf("Result: A + B = \n");
    for (i = j; i < j + rowA * colA; ++i)
    {
        /* Newline after print 1 row of matrix */
        if ((i - j) % (uint8_t)colA == 0)
        {
            printf("\n");
        }
        printf("%.2f ", array[i]);
    }
}
void multiMatrixAndOutput(float array[MAX], float rowA, float colA,
                          float rowB, float colB)
{
    float sum = 0;
    uint8_t i, j, k;
    /* Check if input is valid for matrix multiplication */
    if ((colA != rowB) && (rowA != colB))
    {
        /* Notify error to user */
        printf("Dimension error. Unable to do matrix multiplication!\n");
    }
    else
    {
        /* In case AxB not valid but BxA valid for matrix multiplication
         * then we swap matrix A for matrix B
         * Ex: A: 4x3 matrix and B: 2x4 matrix */
        if ((rowA == colB) && (rowB != colB) && (colA != rowB))
        {
            printf("You mean B x A ?\n");
            swap(&rowA, &rowB);
            swap(&colA, &colB);
        }
        /* float type cannot be used for array subscript */
        uint8_t rA = rowA, rB = rowB, cA = colA, cB = colB;
        /* Matrix B starts at i = rowA * colA, result matrix */
        for (i = 0; i < rA; ++i)
        {
            for (j = 0; j < cB; ++j)
            {
                sum = 0;
                for (k = 0; k < rB; ++k)
                {
                    sum += array[i * cA + k] * array[k * cB + j + rA * cA];
                    /* Result matrix starts at 2 * rowA * colA + rowB * colB */
                    array[i * cB + j + 2 * rA * cA + rB * cB] = sum;
                }
            }
        }
        /* Print result */
        multiOutput(array, rowA, colA, rowB, colB);
        printf("\n \n");
    }
}
void multiOutput(float array[MAX], float rowA, float colA, float rowB, float colB)
{
    uint8_t i, j = 2 * rowA * colA + rowB * colB;
    /* In case AxB not valid but BxA valid for matrix multiplication
     * Ex: 4x3 matrix and 2x4 matrix */
    if ((rowB == colA) && (rowA != colA) && (colB != rowA))
    {
        printf("Result: B x A = \n");
    }
    else
    {
        printf("Result: A x B = \n");
    }
    for (i = j; i < j + rowA * colB ; ++i)
    {
        /* Newline after print 1 row of matrix */
        if ((i - j) % (uint8_t)colB == 0)
        {
            printf("\n");
        }
        printf("%.2f ", array[i]);
    }
}
void swap(float *a, float *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
