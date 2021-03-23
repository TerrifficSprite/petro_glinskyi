#include <stdio.h>
#include <math.h>
#include "../../rlutil/rlutil.h"

int main(){
    const float a = 1, b = 2, dx = 0.025;
    printf("Результати обчислення функції y=log2(x) на проміжку [1,2] з кроком 0.025\n"
           "x\ty=log2(x)\n");
    for(float i = a; i < b; i+=dx)
        printf("%.3f\t%.3f\n", i, log2(i));
    return 0;
}