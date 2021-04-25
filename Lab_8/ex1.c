#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../rlutil/rlutil.h"
#include "../library/lib.c"
//Ініціалізація глобальних констант
const int LOW = -100, HIGH = 100;
// Ініціалізація масиву випадковими елементами
void init_rand(int m, int *arr[m]){
    srand(time(0));
    for(int i = 0; i < m; i++){
            arr[i] = random(LOW, HIGH);
    }
}
// Ініціалізація масиву числами введеними з клавіатури
void init(int m, int *arr[m]){
    for(int i = 0; i < m; i++){
            printf("Введіть %d елемент масиву: ", i+1);
            arr[i] = inputd(GREEN);
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
        if(arr[i]%2 == 0)
            setColor(RED);
        printf("%d", arr[i]);
        setColor(WHITE);
        if(i == m-1)
            printf("]\n");
    }
}
// Обчислення середнього арифметичного
float calc(int m, int arr[m]){
    int n = 0, sum = 0;
    for (int i = 0; i < m; i++) {
        if(arr[i]%2 == 0){
            n++; sum+=i;
        }
    }
    if(n == 0)
        return -1;
    return (float)sum/n;
}
// Головна програма
int main(){
    do {
        const int LOW = -1000, HIGH = 1000;
        int flag = 0;
        int choose_it;
        srand(time(0));
        srand(time(0) * (LOW+rand()%HIGH));
        draw(YELLOW);
        printf("Виберіть спосіб розв'язання задачі:\n"
               "Задавати з клавіатури - 1\n"
               "Заповнити масив випадковими числами - 2\n"
               "Вийти - 3\n");
        setColor(LIGHTGREEN);
        scanf("%d", &choose_it);
        draw(YELLOW);
        printf("Введіть довжину масиву: ");
        const int m = inputd(GREEN);
        printf("--------------------------------\n");
        int array[m];
        switch (choose_it) {
        case 1:
            // ------- Заповнення з клавіатури ------- //
            init(m, array);
            // ------- Кінець заповнення з клавіатури  //
            break;
        case 2:
            // ------- Заповнення рандомом ----------- //
            init_rand(m, array);
            // ------- Кінець заповнення рандомом ---- //
            break;
        case 3: flag = 1; break;
        }
        if (flag)   break;
        // ------- Початок обчислень ------- //
        print_arr(m, array);
        setColor(RED);
        if(calc(m, array) == -1)
            printf("В масиві відсутні парні елементи!\n");
        else{
         setColor(WHITE);
            printf("Середнє арифметичне індексів парних елементів: ");
            setColor(GREEN);printf("%.2f\n", calc(m ,array)); setColor(WHITE);
        }
        // ------- Кінець обчислень ------- //
    }while (1);
    return 0;
}