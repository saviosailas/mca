//Fractional knapsack probelm
#include<stdio.h>
struct item{
    int id;
    int w;
    int p;
    float value;
    
};
void main()
{
    int i,j,w,p,tw=0,capacity,itemcount;
    float tv=0,partp;
    struct item K[50];
    printf("\nKey in count of items[Maximum 50] and the maximum capacity of the bag\n\t");
    scanf("%d%d",&itemcount,&capacity);
    printf("Key in,row-wise[oneline per item],.the serial number,the weight and the profit for each of the %d items\n",itemcount);
    for(i=0;i<itemcount;i++)
    scanf("%d%d%d",&K[i].id,&K[i].w,&K[i].p);
    for(i=0;i<itemcount;i++)
    K[i].value=(float)K[i].p/K[i].w;
    struct item KK;
    for (i=0;i<itemcount-1;i++)
    {
        for(j=0;j<itemcount-1;j++)
        {
            if(K[j+1].value>K[j].value)
            {
                KK=K[j+1];
                K[j+1]=K[j];
                K[j]=KK;
            }
        }
    }
    printf("The %d items arranged in non-decendeing orders of the ratio value =[profit/weight]is as under\n",itemcount);
    printf("\n\tvalue\titem serial number\tweight\tprofit\n");
    for(i=0;i<itemcount;i++)
    printf("\n\t%0.2f\t\t%d\t\t%d\t%d\n",K[i].value,K[i].id,K[i].w,K[i].p);
    printf("\n");
    printf("The solutions to the fractional Knapsack problem \n\n");
    for(i=0;i<itemcount;i++)
    {
        if(K[i].w+tw<=capacity)
        {
            tw+=K[i].w;
            tv+=K[i].p;
            printf("\nSelected item%d [whole]\t\tweight%d\tprofit%d\t\tCumulative weight\t%d\tCumulative value\t%0.2f\n\n",K[i].id,K[i].w,K[i].p,tw,tv);
        }
        else
        {
            w=capacity-tw;
            partp=(float)w*(float)K[i].p/(float)K[i].w;
            tw+=w;
            tv+=partp;
            printf("\nSelected items%d [part]\t\tweight%d\tprofit%0.2f\t\tCumulative weight\t\t%d\tCumulative value\t%0.2f\n\n",K[i].id,w,partp,tw,tv);
            break;
        }
    }
    printf("\nThus the Knapsack with a capacity of %d can hold items worth a Cumulative total value of \t%0.2f\n\n",tw,tv);
    printf("\n");
}