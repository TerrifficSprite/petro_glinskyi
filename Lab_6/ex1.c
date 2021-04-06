#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include "../library/lib.c"
#include <time.h>
#include <stdlib.h>
int main(){
    do {
        int sum = 0;
        int choose_it, n, m, max;
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
        printf("Введіть кількість рядків: ");
        n = inputd(GREEN);
        printf("Введіть кількість стовпчиків: ");
        m = inputd(GREEN);
        int arr[n][m];
        printf("Заповніть матрицю:\n");
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                printf("a[%d][%d]: ", i, j);
                arr[i-1][j-1] = inputd(GREEN);
            }
            printf("\n");
        }
        printf("Утворена матриця:\n");
        for(int i = 0; i < n; i++){
            int max = 0;
            for(int j = 0; j < m; j++){
                if(arr[i][j] > arr[i][max])
                    max = j;
                else if(arr[i][j] == arr[i][max]){
                    int r = 0+rand()%100;
                    if(r > 50)
                        max = j;
                }
            }
            for(int k = 0; k < m; k++){
                if(k == max)
                    setColor(LIGHTBLUE);
                printf("%d\t", arr[i][k]);
                setColor(WHITE);
            }
            sum+=arr[i][max];
            printf("\n");
        }
        printf("Сума найбільших елементів кожного рядка: ");
        setColor(GREEN);
        printf("%d\n", sum);
        // ---- Кінець обчислень ----- //
    }while (1);
   return 0;
}