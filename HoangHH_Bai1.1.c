#include <stdio.h>
#include <stdint.h>
#define MAX 100

/*
    Input array
*/
void Input(int array[MAX], uint8_t N)
{
    uint8_t i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
}
/*
    Output array
*/
void Output(int array[MAX], uint8_t N)
{
    uint8_t i;
    for (i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
}
/*
    Count ODD numbers in array
*/
uint8_t numberOfOdds(int array[MAX], uint8_t N)
{
    uint8_t count = 0, i;
    for (i = 0; i < N; i++)
    {
        if (array[i]%2 != 0)
        {
            count++;
        }
    }
    return count;
}
/*
    Count EVEN numbers in array
*/
uint8_t numberOfEvens(int array[MAX], uint8_t N)
{
    uint8_t count = 0, i;
    for (i = 0; i < N; i++)
    {
        if (array[i]%2 == 0)
        {
            count++;
        }
    }
    return count;
}
/*
    Create an array of ODD numbers
*/
void genOddArray(int array[MAX], int oddArray[MAX], uint8_t N)
{
    uint8_t i, j = 0;
    for (i = 0; i < N; i++)
    {
        if (array[i]%2 != 0)
        {
            oddArray[j] = array[i];
            j++;
        }
    }
}
/*
    Create an array of EVEN numbers
*/
void genEvenArray(int array[MAX], int evenArray[MAX], uint8_t N)
{
    uint8_t i, j = 0;
    for (i = 0; i < N; i++)
    {
        if (array[i]%2 == 0)
        {
            evenArray[j] = array[i];
            j++;
        }
    }
}
/*
    Sort array from  the SMALLEST number to the LARGEST number
*/
void Sort1(int array[MAX], uint8_t N)
{
    uint8_t i, j;
    for (i = 0; i < numberOfOdds(array, N) - 1; ++i)
    {
        for (j = i + 1; j < numberOfOdds(array, N); ++j)
        {
            if (array[i] >= array[j])
            {
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
}
/*
    Sort array from the LARGEST number to the SMALLEST number
*/
void Sort2(int array[MAX], uint8_t N)
{
    uint8_t i, j;
    for (i = 0; i < numberOfEvens(array, N) - 1; ++i)
    {
        for (j = i + 1; j < numberOfEvens(array, N); ++j)
        {
            if (array[i] <= array[j])
            {
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
}
/*
    Merge array A with array B so that array A = array B + array A
*/
void mergeArray(int array[MAX], int a[MAX], int b[MAX], uint8_t N)
{
    uint8_t N1 = numberOfOdds(array, N);
    uint8_t N2 = numberOfEvens(array, N);
    uint8_t i, j = N1;
   for (i = 0; i < N2; ++i)
   {
       a[j] = b[i];
       j++;
   }
}
/*
    Calculate sum of numbers at ODD position in the array
*/
int sumOfOddPos(int array[MAX], int N)
{
    int sum = 0;
    uint8_t i;
    for (i = 0; i < N; ++i)
    {
        if ((i + 1) %2 != 0)
        {
            sum += array[i];
        }
    }
    return sum;
}
/*
    Calculate sum of numbers at EVEN position in the array
*/
int sumOfEvenPos(int array[MAX], int N)
{
    int sum = 0;
    uint8_t i;
    for (i = 0; i < N; ++i)
    {
        if ((i + 1) %2 == 0)
        {
            sum += array[i];
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int array[MAX], oddArray[MAX], evenArray[MAX];
    uint8_t N, N1, N2;
    scanf("%d", &N);
    Input(array, N);
    genOddArray(array, oddArray, N);
    genEvenArray(array, evenArray, N);
    Sort1(oddArray, numberOfOdds(array, N));
    Sort2(evenArray, numberOfEvens(array, N));
    /*
        Merge oddArray with evenArray so that oddArray = evenArray + oddArray
    */
    mergeArray(array, oddArray, evenArray, N);
    printf("Sorted array: ");
    Output(oddArray, numberOfEvens(array, N) + numberOfOdds(array, N));
    printf("\n");
    printf("Sum of numbers at odd positions is: %d", sumOfOddPos(oddArray, numberOfOdds(array, N) + numberOfEvens(array, N)));
    printf("\n");
    printf("Sum of numbers at even positions is: %d", sumOfEvenPos(oddArray, numberOfOdds(array, N) + numberOfEvens(array, N)));
    return 0;
}
