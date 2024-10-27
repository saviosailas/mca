// Floyd Warshall

#include <stdio.h>

int min(int a, int b)
{
    if (a < 90000)
        a = 99999;
    if (b < 90000)
        b = 99999;
    return (a > b) ? b : a;
}

void main()
{
// #include <stdio.h>
    int i, j, V, x, y, N;
    int Z[11][11], D[11][11][11];
    printf("\n \tKey in the count of vertices [ should be less than or equal to 10]:\n");
    scanf("%d", &N);
    printf("\n \tKey in row-wise the \t%d elements\t of the Distance Matrix \n\n\tKey in the value of the diagonal element as 0[zero]\n\n\tif there is no edge between a pair of vertices \n\tkey in 99999 as value of the distance [ edge weight ] between those two vertices \n\n", N * N);
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            scanf("%d", &D[0][i][j]);
    printf("\n the elements of the initial Distance Matrix D[0] are\n");
    for (i = 1; i <= N; i++)
    {
        printf("\n");
        for (j = 1; j <= N; j++)
            printf("\t%d", D[0][i][j]);
        printf("\n");
    }
    printf("\n the Distance Matrices D[1] to D[%d] are\n", N);

    // Calculating the elements of the Distance Matrixes follows
    for (V = 1; V <= N; V++)
    {
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                x = D[V - 1][i][j];
                y = D[V - 1][i][V] + D[V - 1][V][j];
                D[V][i][j] = min(x, y);
                D[V][1][1] = D[V][2][2] = D[V][3][3] = D[V][4][4] = D[V][5][5] = 0;
            }
        }
    }
    for (V = 1; V <= N; V++)
    {
        printf("\n \t\t\t\tD[%d]\n", V);
        for (i = 1; i <= N; i++)
        {
            printf("\n");
            for (j = 1; j <= N; j++)
            {
                printf("\t%d", D[V][i][j]);
            }
            printf("\n\n");
        }
    }
    // printing the all pair shortest distance between the vertices
    printf("\n The all pair shortest path between the vertices are given in the following Matrix D[%d]\n\n", V - 1);
    printf("\n \t\t\t\tD[%d] is\n\n", V - 1);
    for (j = 1; j <= N + 1; j++)
        Z[1][j] = j - 1;
    for (i = 2; i <= N + 1; i++)
        Z[i][1] = i - 1;
    printf("\n");

    for (i = 2; i <= N + 1; i++)
        for (j = 2; j <= N + 1; j++)
            Z[i][j] = D[N][i - 1][j - 1];
    printf("\t");
    for (j = 2; j <= N + 1; j++)
        printf("\tV%d", Z[1][j]);
    printf("\n\n");
    for (i = 2; i <= N + 1; i++)
    {
        printf("\n");
        printf("\tV%d", Z[i][1]);
        for (j = 2; j <= N + 1; j++)
            printf("\t%d", Z[i][j]);
        printf("\n");
    }
    printf("\n");
}