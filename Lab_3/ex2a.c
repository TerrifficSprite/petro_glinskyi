#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include <math.h>

int main(){
    float r, a, s, p;
    printf("Введіть радіус круга: ");
    scanf("%f", &r);
    printf("Введіть довжину сторони квадрата: ");
    scanf("%f", &a);
    s = M_PI * (r * r);
    p = M_PI * (a * a) / 4;
    setColor(GREEN);
    if(s <= p)
        printf("Можна вписати");
    else
        printf("Не можна вписати");

    return 0;
}