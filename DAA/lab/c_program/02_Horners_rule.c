// Comparison of Horner’s rule and brute force method

#include <stdio.h>

void main()
{
    int P, x, degree, coeff[10], i, loopmultaddcount = 0;
    int p[10], k, pbrute = 0, brutemultcount = 0;

    printf("Key in the degree of polynomial\n");
    scanf("%d", &degree);

    printf("Key in the %d coefficients starting from that for degree %d\n", degree + 1, degree);
    for (i = 0; i <= degree; i++)
    {
        scanf("%d", &coeff[i]);
    }

    printf("The coefficients are\n");
    for (i = 0; i <= degree; i++)
    {
        printf("%d\t", coeff[i]);
    }
    printf("\n");

    printf("Key in the value for X\n");
    scanf("%d", &x);

    // Horner's method
    P = coeff[0];
    for (i = 1; i <= degree; i++)
    {
        P = P * x + coeff[i];
        loopmultaddcount++;
    }

    // Brute force method
    for (k = 0; k <= degree; k++)
    {
        p[k] = coeff[k];
        for (i = 1; i <= degree - k; i++)
        {
            p[k] = p[k] * x;
            brutemultcount++;
        }
    }

    for (i = 0; i <= degree; i++)
    {
        pbrute = pbrute + p[i];
    }

    printf("\n\tP(x) at x= %d is P(%d)=%d.\n\tIn the Horner's method:\n\t\t[1] The loop was iterated %d time[s].\n\t\t[2] There were %d multiplication operations.\n\t\t[3] There were %d addition operations.\n",
           x, x, P, loopmultaddcount, loopmultaddcount, loopmultaddcount);

    printf("\n\tIn the brute force method:\n\t\t[1] P(x) at x= %d is P(%d)=%d.\n\t\t[2] There were %d multiplications as against %d in the Horner's method.\n\n",
           x, x, pbrute, brutemultcount, loopmultaddcount);
}