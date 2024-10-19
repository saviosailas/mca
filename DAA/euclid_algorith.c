#include <stdio.h>

int main() {
    int num1, num2, sum;
    printf("ENter first number \n");
    scanf("%d", &num1);

    printf("Enter second number \t");
    scanf("%d", &num2);

    sum = num1 + num2;

    printf("The sum of %d and %d is %d", num1, num2, sum);
    return 0;

}