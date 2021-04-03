#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include <math.h>
int main(){
    int a, y, z;
    float x;
    printf("Введіть число а: ");
    scanf("%d", &a);
    printf("Введіть число у: ");
    scanf("%d", &y);
    printf("Введіть число z: ");
    scanf("%d", &z);

    if((y * y - 2 * a) < 0){
        setColor(RED);
        printf("Для заданих значень а та у береться корінь з від'ємного числа!");
        return 0;
    }
    x = (float)(y * y - 2 * a) + pow(cos(z), 2);
    setColor(GREEN);
    printf("Результат обчислення: %.2f", x);
    return 0;
}