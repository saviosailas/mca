// Euclid’s algorithm for GCD

#include <stdio.h>

void main()
{
    int a, b, m, n, r, modcount = 0, assigncount = 0;

    printf("Key in the two numbers [first number should be greater than second number] whose GCD is to be calculated\n");

    scanf("%d %d", &a, &b);
    m = a;
    n = b;

    while (n > 0)
    {
        r = m % n;
        modcount++;
        m = n;
        n = r;
        assigncount = assigncount + 2;
    }

    printf("\n\tGCD of %d and %d is %d.\n\tThe mod function was called %d time[s].\n\tAssignment operation was done %d times.\n",
           a, b, m, modcount, assigncount);
}