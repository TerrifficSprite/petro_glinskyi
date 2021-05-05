#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include "../library/lib.c"
#include <math.h>
// Ініціалізація масиву випадковими елементами
void init(int n, float arr[n][n]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = cos(i*i + n);
        }
    }
}
// Вивід масиву на екран
void print_arr(int n, float arr[n][n]){
    printf("Утворена матриця:\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            float a = arr[i][j];
            if(a > 0)
                setColor(GREEN);
            else if(a < 0)
                setColor(RED);
            else
                setColor(WHITE);
            printf("%.3f\t", a);
        }
        printf("\n");
    }
}

// Додатні елементи
void calculate(int n, float arr[n][n]){
    int positive = 0, negative = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] > 0)
                positive++;
            else if (arr[i][j] < 0)
                negative++;
        }
    }
    setColor(WHITE);
    printf("Кількість додатніх елементів матриці: ");
    setColor(GREEN);    printf("%d\n", positive);
    setColor(WHITE);
    printf("Кількість від'ємних елементів матриці: ");
    setColor(RED);    printf("%d\n", negative);
}
int main(){
    do {
        draw(YELLOW);
        int n;
        float a;
        printf("Введіть довжину та висоту масиву n: ");
        scanf("%d", &n);
        float arr[n+1][n+1];
        init(n, arr);
        print_arr(n, arr);
        calculate(n, arr);
    }
    while (1);
}


