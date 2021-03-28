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
        printf("Круг поміститься у квадраті");
    else{
        setColor(RED);
        printf("Круг в квадраті не поміститься");
    }
    return 0;
}