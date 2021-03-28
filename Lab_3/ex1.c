#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include <math.h>
int main(){
    int a, b;
    float c, y;
    printf("Введіть ціле число а: ");
    scanf("%d", &a);
    printf("Введіть ціле число b: ");
    scanf("%d", &b);
    printf("Введіть дійсне число c: ");
    scanf("%f", &c);
    if(c > 0)
        y = sqrt(b - a) + 2 * sqrt(c);
    if(c == 0)
        y = b/(c - 6 * a);
    if(c < 0)
        y = b + 12 * pow(c, 3);
    setColor(GREEN);
    printf("Результат обчислення скороченою формою if: %.2f. ", y);
    if(c > 0)
        y = sqrt(b - a) + 2 * sqrt(c);
    else if(c < 0)
        y = b + 12 * pow(c, 3);
    else
        y = b/(c - 6 * a);
    setColor(GREEN);
    printf("\nРезультат обчислення повною формою if else: %.2f. ", y);
    return 0;
}