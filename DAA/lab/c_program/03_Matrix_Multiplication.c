// Matrix Multiplication

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int A[10][10], B[10][10], C[10][10];
    int rA, cA, rB, cB;
    int i, j, k;
    int outerloopcount = 0, middleloopcount = 0, innerloopcount = 0, addncount = 0, multcount = 0;

    printf("Key in the row size and column size [maximum is 10 X 10] for the first matrix, say, A\n");
    scanf("%d %d", &rA, &cA);

    printf("Key in the row size and column size [maximum is 10 X 10] for the second matrix, say, B\n");
    scanf("%d %d", &rB, &cB);

    if (cA != rB)
    {
        printf("\nMatrices are incompatible for multiplication\n");
        exit(0);
    }

    printf("Key in row-wise the elements of the first [%d X %d] matrix A\n", rA, cA);
    for (i = 0; i < rA; i++)
        for (j = 0; j < cA; j++)
            scanf("%d", &A[i][j]);

    printf("\nFirst matrix A is:\n");
    for (i = 0; i < rA; i++)
    {
        for (j = 0; j < cA; j++)
            printf("\t%d\t", A[i][j]);
        printf("\n");
    }
    printf("\nKey in row-wise the elements of the second [%d X %d] matrix B\n", rB, cB);
    for (i = 0; i < rB; i++)
        for (j = 0; j < cB; j++)
            scanf("%d", &B[i][j]);

    printf("\nSecond matrix B is:\n");
    for (i = 0; i < rB; i++)
    {
        for (j = 0; j < cB; j++)
            printf("\t%d\t", B[i][j]);
        printf("\n");
    }
    for (i = 0; i < rA; i++)
    {
        outerloopcount++;
        for (j = 0; j < cB; j++)
        {
            middleloopcount++;
            C[i][j] = 0;
            for (k = 0; k < cA; k++)
            {
                innerloopcount++;
                C[i][j] += A[i][k] * B[k][j];

                addncount++;
                multcount++;
            }
        }
    }

    printf("\nThe matrix product is C = A X B and C is:\n");
    for (i = 0; i < rA; i++)
    {
        for (j = 0; j < cB; j++)
            printf("\t%d\t", C[i][j]);
        printf("\n");
    }
    printf("\nStatistics:\n");
    printf("[1] Outer loop was iterated for %d time(s).\n", outerloopcount);
    printf("[2] Middle loop was iterated for %d time(s).\n", middleloopcount);
    printf("[3] Inner loop was iterated for %d time(s).\n", innerloopcount);
    printf("[4] %d additions were done.\n", addncount);
    printf("[5] %d multiplications were done.\n", multcount);
}
