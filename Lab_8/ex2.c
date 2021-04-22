#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../rlutil/rlutil.h"
#include "../library/lib.c"
//Ініціалізація глобальних констант
const int LOW = -100, HIGH = 100;
// Ініціалізація масиву випадковими елементами
void init_rand(int m, int n, int **arr[m][n]){
    srand(time(0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = random(LOW, HIGH);
        }
    }
}
// Вивід масиву на екран
void print_arr(int m, int n, int arr[m][n]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

// Сортування масиву
void sort_arr(int m, int n, int **arr[m][n]){
    int i, j, k;
    int nums[m];
    //Пройтися по кожному стовпцю
    for(i = 0; i < n; i++){
        // Пройтися по кожному елементу стовпця
        for(j = 0; j < m; j++){
            nums[j] = arr[j][i];
        }
        // Сортувати елементи
        for(j = 0; j < m; j++){
            for(k = 0; k < m-1; k++){
                if(nums[k] < nums[k+1]){
                    int temp = nums[k];
                    nums[k] = nums[k+1];
                    nums[k+1] = temp;
                }
            }
        }
        for(k = 0; k < m; k++)
            arr[k][i] = nums[k];
    }
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
        printf("Введіть кількість рядків: ");
        const int m = inputd(GREEN);
        printf("Введіть кількість стовпців: ");
        const int n = inputd(GREEN);
        setColor(RED);
        if(m == n)
            printf("Матриця повинна бути прямокутною!\n", flag = 2);
        int array[m][n];
        if (flag == 2) continue;
        setColor(YELLOW);
        printf("------------------------------------\n");
        switch (choose_it) {
        case 1:
            // ------- Заповнення з клавіатури ------- //
            init_rand(m, n, array);
            // ------- Кінець заповнення з клавіатури  //
            break;
        case 2:
            flag = 1; break;
        }
        if (flag == 1)   break;
        // ------- Початок обчислень ------- //
        setColor(RED);
        printf("Згенерована матриця:\n"); setColor(WHITE);
        print_arr(m, n, array);
        sort_arr(m, n, array);
        setColor(BLUE);
        printf("\nВідсортована матриця:\n"); setColor(WHITE);
        print_arr(m, n, array);
        // ------- Кінець обчислень ------- //
    }while (1);
    return 0;
}