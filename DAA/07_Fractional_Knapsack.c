// Fractional Knapsack problem

#include <stdio.h>

struct item
{
    int id;
    int w;
    int p;
    float value;
};

void main()
{
    int i, j, w, p, tw = 0, capacity, itemcount;
    float tv = 0, partp;

    struct item K[50];

    printf("\nKey in count of items [ maximum 50] and the maximum capacity of the bag\n\t");
    scanf("%d%d", &itemcount, &capacity);

    printf("Key in, row-wise [one line per item], the serial number, the weight and the profit for each of the %d items\n", itemcount);

    for (i = 0; i < itemcount; i++)
        scanf("%d%d%d", &K[i].id, &K[i].w, &K[i].p);

    for (i = 0; i < itemcount; i++)
        K[i].value = (float)K[i].p / K[i].w;

    struct item KK;

    for (i = 0; i < itemcount - 1; i++)
    {
        for (j = 0; j < itemcount - 1 - i; j++)
        {
            if (K[j + 1].value > K[j].value)
            {
                KK = K[j + 1];
                K[j + 1] = K[j];
                K[j] = KK;
            }
        }
    }

    printf("The %d items arranged in non-descending order of the ratio Value = [ Profit/Weight ] is as under\n", itemcount);
    printf("\n\tValue\tItem serial number\tWeight\tProfit\n");

    for (i = 0; i < itemcount; i++)
        printf("\n\t%0.2f \t\t %d \t\t %d \t %d \n", K[i].value, K[i].id, K[i].w, K[i].p);

    printf("\n");
    printf("The solution to the Fractional Knapsack problem\n\n");

    for (i = 0; i < itemcount; i++)
    {
        if (K[i].w + tw <= capacity)
        {
            tw += K[i].w;
            tv += K[i].p;

            printf("\nSelected Item %d [whole]\t\tWeight %d \t Profit %d \t\tCumulative Weight\t%d\tCumulative Value \t%0.2f\n\n", K[i].id, K[i].w, K[i].p, tw, tv);
        }
        else
        {
            w = capacity - tw;
            partp = (float)w * (float)K[i].p / (float)K[i].w;
            tw += w;
            tv += partp;
            printf("\nSelected Item %d [part]\t\tWeight %d \t Profit %0.2f \t\tCumulative Weight\t%d\tCumulative Value \t%0.2f\n\n", K[i].id, w, partp, tw, tv);
            break;
        }
    }

    printf("\nThus the Knapsack with a capacity of %d can hold items worth a Cumulative Total Value of \t%0.2f\n\n", tw, tv);

    printf("\n");
}
