#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include "../library/lib.c"
#include <math.h>
// Сума непарніх елементів
float sum(int m, float arr[m]){
    float summa = 0;
    for(int i = 0; i < m; i++){
        if((int)arr[i] % 2 != 0)
            summa+=arr[i];
    }
    return summa;
}

// Ініціалізація масиву числами введеними з клавіатури
void init(int m, float *arr[m]){
    for(int i = 0; i < m; i++){
        printf("Введіть %d елемент масиву: ", i+1);
        scanf("%f", &arr[i]);
    }
}
// Вивід масиву на екран
void print_arr(int m, float arr[m], float summa){
    setColor(WHITE);
    for(int i = 0; i < m; i++){
        if(i == 0)
            printf("[");
        if(i != 0)
            printf(", ");
        printf("%.2f", arr[i]);
        setColor(WHITE);
        if(i == m-1)
            printf("]\n");
    }

    printf("Сума непарних елементів масиву: ");
    setColor(GREEN);
    printf("%.2f\n", summa);
}

int main(){
    do {
        draw(YELLOW);
        int n;
        float a;
        printf("Введіть довжину масиву n: ");
        scanf("%d", &n);
        float arr[n];
        init(n, arr);
        print_arr(n, arr, sum(n, arr));
    }
    while (1);
}


