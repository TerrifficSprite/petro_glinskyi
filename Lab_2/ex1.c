#include <stdio.h>
int main(){
    int a, b;
    float c;
    printf(" Введіть перше число: ");
    scanf("%d", &a);
    printf("Введіть друге число: ");
    scanf("%d", &b);
    c = b % a;
    printf("Залишок від ділення 2-го числа на 1-е: %.0f\n", c);
    c = a / b;
    printf("Ціла частина від ділення 1-го числа на 2-е: %.0f\n", c);
    c = a * b;
    printf("Добуток першого і другого чисел: %.0f\n", c);
    return 0;
}