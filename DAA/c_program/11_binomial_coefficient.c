// binomial coeffiecient C(n, k) by dynamic approach

#include<stdio.h>

int bc(int n, int k)
{
    int C[n+1][k+1], i, j;
    for (i = 0; i <= n; i++)
    {
        for (j=0; j<=((i<k) ? i : k); j++)
        {
            if(j == 0 || j == i)
            {
                C[i][j] =1;
                printf("C(%d, %d) is %d\t", i, j, C[i][j]);
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                printf("C(%d, %d) is %d\t", i, j, C[i][j]);
            }
        }
        printf("\n\n");
    }
    return C[n][k];
}

void main()
{
    int n, k;
    printf("Key in the values for n and k [ k should be less than or equal to n ]\n");
    scanf("%d%d", &n, &k);
    printf("\n\n");
    printf("Hence the value of C(%d, %d) is %d \n\n", n, k, bc(n, k));
    printf("\n\n");
}