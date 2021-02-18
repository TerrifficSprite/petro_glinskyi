#include <stdio.h>
int main(){
    int x, y;
    float f;
    printf(" Введіть перше число: ");
    scanf("%d", &x);
    printf("Введіть друге число: ");
    scanf("%d", &y);
    f = (float)(x * x + x * y - y * y)/(float)(1 + x * x + y * y);
    printf("%f", f);
    return 0;
}