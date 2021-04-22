#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../rlutil/rlutil.h"
#include "../library/lib.c"
int random_num(int min, int max){
    int rand_num, r;
    if(min <= 0){
        max+=1;
        r = abs(min);
        rand_num = (min+r)+rand()%(max+r);
        rand_num -=r;
    }
    else{
        do {
            rand_num = min+rand()%max;
            if(rand_num >= min && rand_num <= max)
                break;
        }
        while (1);
    }
    return rand_num;
}
void init(int *arr, int n, int MIN, int MAX){
    for(int i = 0; i < n; i++){
        arr[i] = random_num(MIN, MAX);
    }
}
void display_arr(int *arr, int n, int max_module){
    setColor(WHITE);
    for(int i = 0; i < n; i++){
        if(i == 0)
            printf("[");
        if(i != 0)
            printf(", ");
        if(i == max_module)
            setColor(RED);
        if(arr[i] == 0)
            setColor(BLUE);
        printf("%d", arr[i]);
        setColor(WHITE);
        if(i == n-1)
            printf("]\n");
    }
}
int zero_el(int *arr, int n){
    int num_of_zeros = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] == 0)
            num_of_zeros++;
    }
    return num_of_zeros;
}
int module_max(int* arr, int n){
    int index_max = 0;
    for (int i = 0; i < n; i++) {
        if(abs(arr[index_max]) < abs(arr[i]))
            index_max = i;
    }
    return index_max;
}
//
int dobutok(int *arr, int n, int max_el){
    int d = 1;
    for (int i = max_el+1; i < n; i++) {
        d*=arr[i];
    }
    return d;
}
int main(){
    const int MIN = -10, MAX = 10, N = 10;
    int arr[N];
    srand(time(0));
    do {
        int choose_it, n;
        srand(time(0));
        setColor(WHITE);
        draw(YELLOW);
        printf("Перейти до обчислень чи вийти з програми?\n"
               "Перейти до обчислень - 1\n"
               "Вийти - 2\n");
        choose_it = inputd(GREEN);
        draw(YELLOW);
        if(choose_it == 2)
            break;
        else if(choose_it != 1)
            continue;
        // ---- Початок обчислень ---- //
        init(arr, N, MIN, MAX);
        int max = module_max(arr, N);
        display_arr(arr, N, max);
        setColor(WHITE);
        printf("Кількість нульових елементів масиву: ");
        setColor(BLUE); printf("%d\n", zero_el(arr, N)); setColor(WHITE);
        printf("Максимальне за модулем число: ");
        setColor(RED); printf("%d", arr[max]); setColor(WHITE);
        printf(", його індекс: ");
        setColor(RED); printf("%d\n", max); setColor(WHITE);
        printf("Добуток елементів масиву, розташованих після максимального за модулем елемента: ");
        setColor(GREEN); printf("%d\n", dobutok(arr, N, max));
        // ---- Кінець обчислень ----- //
    }while (1);
    return 0;
}
