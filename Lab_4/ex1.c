#include <stdio.h>
#include "../../rlutil/rlutil.h"
int main(){
    int x, y, z, num;
    float t, num_2, c;
    do {
        setColor(WHITE);
        printf("\n");
        printf("Введіть число x: ");
        scanf("%d", &x);
        printf("Введіть число y: ");
        scanf("%d", &y);
        printf("Введіть число z: ");
        scanf("%d", &z);
        num = (1 + x*x);
        num_2 = (x-1/(float)(num));
        setColor(RED);
        if(z == 0)
            printf("Для заданого числа z виконується ділення на 0. Введіть інші "
                   "значення");
        else if(num == 0 || num_2 == 0)
            printf("Для заданого числа x виконується ділення на 0. Введіть інші "
                   "значення\n");
        else
            break;
    }
    while (1);
    t = (1 + z) * ((x + (float)(y/z)) / num_2);
    setColor(GREEN);
    printf("Результат: %.2f", t);
    return 0;
}