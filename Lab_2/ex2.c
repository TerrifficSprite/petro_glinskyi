#include <stdio.h>
#define a 2
#define b -2
#define c 22
float y;
int main()
{
    y = (float)(a * b * c)/(a + b + c) - (a - b - c)/(float)(a * b * c);
    printf("%.2f", y);
    return 0;
}