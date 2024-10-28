#include <stdio.h>

// MAY NOT BE CORRECT

/*
{
    if (a > 90000)
        a = 99999;
    if (b > 90000)
        b = 99999;
    return (a > b) ? b : a;
}
*/
int min(int a, int b)
{
    return (a < b) ? a : b; // Corrected logic to return minimum
}

int main() // Changed void to int
{
    int i, j, V, x, y, N;
    int Z[11][11], D[11][11][11];
    
    printf("\n \tKey in the count of vertices [ should be less than or equal to 10]:\n");
    scanf("%d", &N);
    
    printf("\n \tKey in row-wise the \t%d elements\t of the Distance Matrix \n\n\tKey in the value of the diagonal element as 0[zero]\n\n\tif there is no edge between a pair of vertices \n\tkey in 99999 as value of the distance [ edge weight ] between those two vertices \n\n", N * N);
    
    for (i = 0; i < N; i++) // Changed from 1 to 0
        for (j = 0; j < N; j++) // Changed from 1 to 0
            scanf("%d", &D[0][i][j]);
    
    printf("\n the elements of the initial Distance Matrix D[0] are\n");
    for (i = 0; i < N; i++) // Changed from 1 to 0
    {
        printf("\n");
        for (j = 0; j < N; j++) // Changed from 1 to 0
            printf("\t%d", D[0][i][j]);
        printf("\n");
    }
    
    printf("\n the Distance Matrices D[1] to D[%d] are\n", N);

    // Calculating the elements of the Distance Matrixes follows
    for (V = 1; V <= N; V++)
    {
        for (i = 0; i < N; i++) // Changed from 1 to 0
        {
            for (j = 0; j < N; j++) // Changed from 1 to 0
            {
                x = D[V - 1][i][j];
                y = D[V - 1][i][V - 1] + D[V - 1][V - 1][j]; // Adjusted index for V
                D[V][i][j] = min(x, y);
            }
        }
        
        // Setting diagonal elements inside this loop
        for (i = 0; i < N; i++) // Changed from 1 to 0
            D[V][i][i] = 0;
    }
    
    for (V = 1; V <= N; V++)
    {
        printf("\n \t\t\t\tD[%d]\n", V);
        for (i = 0; i < N; i++) // Changed from 1 to 0
        {
            printf("\n");
            for (j = 0; j < N; j++) // Changed from 1 to 0
            {
                printf("\t%d", D[V][i][j]);
            }
            printf("\n\n");
        }
    }
    
    // printing the all pair shortest distance between the vertices
    printf("\n The all pair shortest path between the vertices are given in the following Matrix D[%d]\n\n", V - 1);
    printf("\n \t\t\t\tD[%d] is\n\n", V - 1);
    
    for (j = 0; j < N + 1; j++) // Changed from <= to <
        Z[1][j] = j;
    
    for (i = 2; i <= N + 1; i++)
        Z[i][1] = i - 1;
    
    printf("\n");

    for (i = 2; i <= N + 1; i++)
        for (j = 2; j <= N + 1; j++)
            Z[i][j] = D[N - 1][i - 2][j - 2]; // Adjusted index for D
    
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
    
    return 0; // Added return statement
}