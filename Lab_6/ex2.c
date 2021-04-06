#include <stdio.h>
#include "../../rlutil/rlutil.h"
#include "../library/lib.c"
#include <time.h>
#include <stdlib.h>
int main(){
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
        printf("Задайте довжину та висоту квадратної матриці: ");
        n = inputd(GREEN);
        float arr[n][n];
        srand(time(0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i-1][j-1] = randomf(-100, 100);
            }
        }
        // ----- Діагоналі ----- //
        float d_1 = 0, d_2 = 0;
        for(int i = 0; i < n; i++){
            d_1+=arr[i][i];
            d_2+=arr[i][n-1-i];
        }
        // ---- Кінець Діагоналі //
        printf("Задана матриця:\n");
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                if(k == n-1-i && i == n-1-i)
                    setColor(MAGENTA);
                else if(i == k)
                    setColor(BLUE);
                else if(k == n-1-i)
                    setColor(RED);
                printf("%.2f\t", arr[i][k]);
                setColor(WHITE);
            }
            printf("\n");
        }
        printf("Сума елементів головної діагоналі: "); setColor(BLUE);
        printf("%.2f\n", d_1); setColor(WHITE);
        printf("Сума елементів бокової діагоналі: "); setColor(RED);
        printf("%.2f\n", d_2); setColor(WHITE);
        if(d_1 > d_2){
            setColor(GREEN);
            printf("Транспонована матриця:\n");
            setColor(WHITE);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    printf("%.2f\t", arr[j][i]);
                }
                printf("\n");
            }
        }
        else{
            setColor(GREEN);
            printf("Матрицю транспонувати непотрібно\n");
        }
        // ---- Кінець обчислень ----- //
    }while (1);
    return 0;
}