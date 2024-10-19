
#include <stdio.h>
void main()
{
  int A[10], i, j, n, t, cmpcount = 0, swapcount = 0, outerloopcount = 0, innerloopcount = 0, swapcheck = 0;
  printf("key in the element to be sorted [ Maximim 10 ] \n");
  scanf("%d", &n);
  printf("Key in the %d elements \n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);

  printf("\nThe keyed in the elements are \n");
  for (i = 0; i < n; i++)
    printf("%d\t", A[i]);
  printf("\n");

  // sorting
  for (i = 0; i <= n - 2; i++)
  {
    if (i != 0 && swapcheck == 0)
      break;
    outerloopcount++;
    for (j = 0; j <= n - i - 2; j++)
    {
      innerloopcount++;
      cmpcount++;
      swapcheck = 0;
      if (A[j] > A[j + 1])
      {
        swapcheck = 1;
        swapcount++;
        t = A[j];
        A[j] = A[j + 1];
        A[j + 1] = t;
      }
    }
  }

  printf("\nThe sorted list is \n");
  for (i = 0; i <= n - 1; i++)
    printf("\t%d", A[i]);
  printf("\n");
  printf("\n\tThere were %d innerloop interations, %d outerloop iterations, %d comparisons and %d swaps. \n\n", innerloopcount, outerloopcount, cmpcount, swapcount);
}