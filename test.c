#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include "../library/lib.c"
#include <math.h>
// Ініціалізація масиву випадковими елементами
void init(int n, float **arr[n][n]){
    srand(time(0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            float a = cos(1);
            arr[i][j] = &a;
        }
    }
}
// Вивід масиву на екран
void print_arr(int n, float arr[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            float a = arr[i][j];
            printf("%.2f\t", a);
        }
        printf("\n");
    }
}

int main(){
    do {
        draw(YELLOW);
        int n;
        float a;
        printf("Введіть довжину та висоту масиву n: ");
        scanf("%d", &n);
        float arr[n][n];
        init(n, arr);
        print_arr(n, arr);
    }
    while (1);
}


