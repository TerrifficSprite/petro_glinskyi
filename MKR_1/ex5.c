#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include "../library/lib.c"
#include <math.h>
int main(){
    do {
        draw(YELLOW);
        float a, b, f, z;
        printf("Введіть дійсне число а: ");
        scanf("%f", &a);
        printf("Введіть дійсне число b: ");
        scanf("%f", &b);
        draw(YELLOW);
        z = pow(a, 2) + 2*a*b + 3 * pow(b, 2) + a + b;
        if(z == 0){
            setColor("RED");
            printf("Для заданих чисел а та b виконується ділення на 0");
            continue;
        }
        f = (pow(a, 2) - pow(b, 2))/z;
        printf("Результат: ");
        setColor(GREEN);
        printf("%.2f\n", f);
    }
    while (1);
}
