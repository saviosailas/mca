// Left to Right Binary Exponentiation
#include <stdio.h>
#include <string.h>

int binaryexp(float base, int power)
{
    int binrev[100], bin[100], i, l, j, k, powers;
    double result;
    i++;
    powers = power;
    i = 0;

    while (power)
    {
        binrev[i] = power % 2;
        power = power / 2;
        i++;
        l = i;
    }
    for (k = 0; k < l; k++, i--)
        bin[k] = binrev[i - 1];
    printf("\n binary is \n");
    for (k = 0; k < l; k++)
        printf("\t%d \t", bin[k]);
    printf("\n");
    result = 1;
    for (j = 0; j < l; j++)
    {
        if (bin[j] == 1)
            result = result * result * base;
        if (bin[j] == 0)
            result = result * result;
    }

    printf("\n %f to the power %d using left to right binary exponentiation is \n\n\t%lf \n\n", base, powers, result);
}

void main()
{
    float x;
    int n;
    printf("\nKey in the base number X whose power is to be calculated using left to right binary exponentiation is required and the value of power / index \n\n");
    scanf("%f%d", &x, &n);
    printf("\n------X = %f............... power / index = %d\n", x, n);
    binaryexp(x, n);
}
