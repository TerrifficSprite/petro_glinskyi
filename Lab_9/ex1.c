#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../rlutil/rlutil.h"
#include "../library/lib.c"
// Вивід масиву на екран
void print_arr(int m, int arr[m]){
    setColor(WHITE);
    printf("Введений масив:\n");
    for(int i = 0; i < m; i++){
        if(i == 0)
            printf("[");
        if(i != 0)
            printf(", ");
        printf("%d", arr[i]);
        setColor(WHITE);
        if(i == m-1)
            printf("]\n");
    }
}
int main(){
    do {
        int flag = 0, combo = 0;
        int choose_it;
        int *first, *second, *third;
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
            // ------- Заповнення з клавіатури ------- //
            for(int i = 0; i < m; i++){
                printf("Введіть %d елемент масиву: ", i+1);
                arr[i] = inputd(GREEN);
            }
            // ------- Кінець заповнення з клавіатури  //
            break;
        case 2:
            flag = 1;
            break;
        }
        if (flag == 1)
            break;
        // ------- Початок обчислень ------- //
        setColor(YELLOW);
        printf("------------------------------------\n");
        print_arr(m, arr);
        for(int i = 0; i < m - 2; i++){
            if(arr[i] > arr[i+1])
                if(arr[i+1] > arr[i+2]){
                    setColor(WHITE);
                    combo++;
                    first = &arr[i];
                    second = &arr[i+1];
                    third = &arr[i+2];
                    printf("Ділянка №%d, числа: ", combo);
                    setColor(GREEN); printf("%d, %d, %d\n", *first, *second, *third);
                }
        }
        // ------- Кінець обчислень ------- //
    }while (1);
    return 0;
}