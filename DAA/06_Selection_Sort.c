// Selection sort

#include <stdio.h>

void swap(int *f, int *s)
{
    int t = *f;
    *f = *s;
    *s = t;
}

int main()
{
    int A[10], i, j, n;
    int cmpcount = 0, swapcount = 0, outerloopcount = 0, innerloopcount = 0, minpos;

    printf("Key in the count of elements to be sorted (Maximum 10)\n");
    scanf("%d", &n);

    printf("Key in the %d elements\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nThe elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++)
    {
        outerloopcount++;
        minpos = i;
        for (j = i + 1; j < n; j++)
        {
            innerloopcount++;
            cmpcount++;
            if (A[j] < A[minpos])
            {
                minpos = j;
            }
        }
        if (minpos != i)
        {
            swapcount++;
            swap(&A[minpos], &A[i]);
        }
    }

    printf("\nThe sorted list is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", A[i]);
    }
    printf("\n");

    printf("\nThere were %d inner loop iterations, %d outer loop iterations, %d comparisons, and %d swaps\n\n",
           innerloopcount, outerloopcount, cmpcount, swapcount);

    return 0;
}