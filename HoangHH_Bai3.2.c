#include <stdio.h>
#include <stdint.h>
/* Calculate sum of S = 1/2 + 3/4 + (2n+1)/(2n+2) and print result */
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
	float n, sum = 0, i;
	do
    {
        /* Tell user to enter n */
        printf ("Enter n: ");
        scanf("%f", &n);
    } while (inputIsInvalid(n) == 0);
    /* Calculation */
    for (i = 0; i <= n; ++i)
    {
        sum += (2 * i + 1) / (2 * i + 2);
    }
    printf("Result: 1/2 + 3/4 + 5/6 + ... + (2n+1)/(2n+2) = %.4f \n", sum);
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
