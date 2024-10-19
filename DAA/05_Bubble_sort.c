// Bubble sort

#include <stdio.h>

void main()
{
    int A[10], i, j, n, t;
    int cmpcount = 0, swapcount = 0, outerloopcount = 0, innerloopcount = 0, swapcheck = 0;

    printf("Key in the count of elements to be sorted [Maximum 10] \n");
    scanf("%d", &n);

    printf("Key in the %d elements\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nThe keyed-in elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++)
    {
        swapcheck = 0;
        outerloopcount++;
        for (j = 0; j < n - i - 1; j++)
        {
            innerloopcount++;
            cmpcount++;

            if (A[j] > A[j + 1])
            {
                swapcheck = 1;
                swapcount++;
                t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
        }
        if (swapcheck == 0)
        {
            break;
        }
    }

    printf("\nThe sorted list is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");

    printf("\nThere were %d inner loop iterations, %d outer loop iterations, %d comparisons, and %d swaps\n\n",
           innerloopcount, outerloopcount, cmpcount, swapcount);
}