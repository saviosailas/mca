#include <stdio.h>
void swap(int *f, int *s)
{
    int t = *f;
    *f = *s;
    *s = t;
}
void main()
{
    int a[10], i, j, n, cmpcount = 0, swapcount = 0, outerloopcount = 0, innerloopscount = 0, minpos;
    printf("Key in the count of elements to be sorted  [Maximum 10]\n");
    scanf("%d", &n);
    printf("Key in the %d elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\n The keyed in elements are \n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    // sorting

    for (i = 0; i < n - 1; i++)
    {
        outerloopcount++;
        minpos = i;
        for (j = i + 1; j < n; j++)
        {
            innerloopscount++;
            cmpcount++;
            if (a[j] < a[minpos])
            {
                minpos = j;
            }
        }

        if (minpos != i)
        {
            swapcount++;
            swap(&a[minpos], &a[i]);
        }
    }
    printf("\nThe sorted list is \n");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    printf("\n");
    printf("\n\tThere were %d innerloop interations, %d outerloop iterations, %d comparisons and %d swaps. \n\n", innerloopscount, outerloopcount, cmpcount, swapcount);
}
