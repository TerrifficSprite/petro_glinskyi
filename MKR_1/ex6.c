#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include "../library/lib.c"
#include <math.h>
int main(){
    do {
        draw(YELLOW);
        float x, f;
        printf("Введіть дійсне число x: ");
        scanf("%f", &x);
        if(x > 0)
            f = x*x + 4*x + 5;
        else
            f = 1/(x*x + 4*x + 5);
        printf("Результат: ");
        setColor(GREEN);
        printf("%.2f\n", f);
    }
    while (1);
}
