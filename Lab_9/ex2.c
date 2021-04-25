#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../rlutil/rlutil.h"
#include "../library/lib.c"
// Глобальні константи
const int LOW = -10, HIGH = 10;
// Ініціалізація масиву
void init(int m, int *arr[m]){
    for(int i = 0; i < m; i++){
        arr[i] = random(LOW, HIGH);
    }
}
// Вивід масиву на екран
void print_arr(int m, int arr[m]){
    setColor(WHITE);
    for(int i = 0; i < m; i++){
        if(i == 0)
            printf("[");
        if(i != 0)
            printf(", ");
        // тут ставити особі характеристики
        if(arr[i] == 0)
            setColor(RED);
        printf("%d", arr[i]);
        setColor(WHITE);
        if(i == m-1)
            printf("]\n");
    }
}
// Функція знаходить чи є нуль
int find_zero(int m, int *arr, int *d){
    for(int i = 0; i < m; i++){
        if(arr[i] == 0){
            d = 1;
            return 1;
        }

    }
    return 0;
}
// Функція для визначення номера мінімального елемента
int min_index(int m, int arr[m]){
    int min = 0;
    for(int i = 0; i < m; i++){
        if(arr[i] < arr[min])
            min = i;
    }
    return min;
}
// Функція для визначення добутку елементів масиву
int dobutok(int m, int arr[m]){
    int dob = 1;
    for(int i = 0; arr[i] != 0; i++)
        dob=dob*arr[i];
    return dob;
}

int main(){
    do {
        int flag = 0;
        int choose_it;
        srand(time(0));
        draw(YELLOW);
        printf("Перейти до обчислень чи вийти з програми?\n"
               "Перейти до обчислень - 1\n"
               "Вийти - 2\n");
        setColor(LIGHTGREEN);
        scanf("%d", &choose_it);
        if(choose_it != 1 && choose_it != 2){
            setColor(RED);
            printf("Ви ввели невірне значення!\n");
            continue;
        }
        draw(YELLOW);
        printf("Введіть довжину масиву: ");
        const int m = inputd(GREEN);
        int arr[m];
        switch (choose_it) {
        case 1:
            // ------- Заповнення рандомом ------- //
            init(m, arr);
            // ------- Кінець заповнення рандомом  //
            break;
        case 2:
            flag = 1;
            break;
        }
        if (flag == 1)
            break;
        // ------- Початок обчислень ------- //
        int d = 0;
        print_arr(m, arr);
        printf("Номер мінімального елемента масиву: %d\n", min_index(m, arr));
        if(find_zero(m, arr, d))
            printf("Добуток елементів масиву,"
                   "розташованих до першого нульового елемента: %d\n", dobutok(m, arr));
        else{
            setColor(RED);
            printf("В масиві немає нулів!\n");
        }
        // ------- Кінець обчислень ------- //
    }while (1);
    return 0;
}