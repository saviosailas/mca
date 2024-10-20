// Matrix chain multiplication and how to place the parantheses

#include<stdio.h>
#include<limits.h>

#define infinity 999999999

long int m[20][20];
int s[20][20];
int d[20], i, j, n;

void print_optimal(int i, int j)
{
    if (i==j)
        printf("A%d", i);
    else{
        printf("(");
        print_optimal(i, s[i][j]);
        print_optimal(s[i][j] + 1, j);
        printf(")");
    }
}

void matmultiply(void)
{
    long int q;
    int k;
    for (i=n; i>0; i--)
    {
        for (j=i; j<=n; j++)
        {
            if(i==j)
                m[i][j] = 0;
            else
            {
                for(k=i; k<j; k++)
                {
                    q=m[i][k]+m[k+1][j];
                    if(q<m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
}

int MatrixChainOrder(int d[], int i, int j)
{
    if( i== j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
    for (k=i; k<j; k++)
    {
        count = MatrixChainOrder(d, i, k) + MatrixChainOrder(d, k+1, j + d[i-1]*d[j]);
        if (count < min)
            min = count;
    }
    // Return minimum count
    return min;
}

void main() 
{
    int k;
    printf("\nKey in the count of matrtices\t");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
        {
            m[i][j] = 0;
            m[i][j] = infinity;
            s[i][j] = 0;
        }
    printf ("\n\nKey in the dimensions\n");
    for(k=0; k<=n; k++)
    {
        printf("d%d: ", k);
        scanf("%d", &d[k]);
    }
    matmultiply();
    printf("\nMinimum cost elements m[i][j] are\n");
    for(i=1; i<=n; i++)
    {
        printf("\n\n\t");
        for(j=i; j<=n; j++)
            printf("m[%d][%d]: %ld\t", i, j, m[i][j]);
    }
    // cost matrix
    printf("\n\nMinimum cost diagonal matrix is\n");
    for(i=1; i<=n; i++)
    {
        printf("\n\n");
        for(j=1; j<=n; j++)
            printf("\t%ld", m[i][j]);
    }
    printf("\n\nMinimum number of multiplications is : %d", MatrixChainOrder(d,1,n));
    i=1, j=n;
    printf("\nMultiplication sequence for the %d matrices is", n);
    print_optimal(i, j);
    printf("\n\n");
}