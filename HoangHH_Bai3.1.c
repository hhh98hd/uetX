#include <stdio.h>
#include <stdint.h>

/* Calculate S = 1^3 + 2^3 + ... + n^3 and print result */
void sum();
/* Check if input of user is valid for calculation */
uint8_t inputIsInvalid(float n);

int main()
{
    sum();
    return 0;
}

void sum()
{
    float n;
    long long sum;
    do
    {
        /* Tell user to enter n */
        printf ("Enter n: ");
        scanf("%f", &n);
    } while (inputIsInvalid(n) == 0);
    /* We can prove that S = (n * (n + 1) / 2)^2 */
    sum = 0.25 * n * n * (n + 1) * (n + 1);
    /* Print result */
    printf("Result: 1^3 + 2^3 + ... + n^3 = %d", sum);
}
uint8_t inputIsInvalid(float n)
{
    /* n is invalid for calculation if n <= 0 or n is non-integer */
    if ((n <= 0) || (n - (int)n != 0))
    {
        /* Notify errors to user */
        if (n <= 0)
        {
            printf("n must be larger than 0! \n");
        }
        /* Check if n is an integer */
        if (n - (int)n != 0)
        {
            printf("n must be an integer!\n");
        }
        /* Return 0 if n is invalid */
        return 0;
    }
    else
    {
        /* Return 1 if n is valid */
        return 1;
    }
}
