#include <stdio.h>
#include "../../rlutil/rlutil.h"
void draw(){
    setColor(YELLOW);
    printf("************************************\n");
    setColor(WHITE);
}
int main(){
    do {
        const int n = 9;
        int num, minus_num = 0, sum = 0, choose_it, flag = 0;
        float ser = 0;
        int arr[n];
        setColor(WHITE);
        draw();
        printf("Перейти до обчислень чи вийти з програми?\n"
               "Перейти до обчислень - 1\n"
               "Вийти - 2\n");
            setColor(GREEN);
            scanf("%d", &choose_it);
        draw();
        switch (choose_it) {
        case 1:
            // -------Початок обчислень------- //
            for(int i = 0; i < n; i++){
                setColor(WHITE);
                printf("Введіть значення елементу з індексом %d: ", i);
                setColor(GREEN);
                scanf("%d", &arr[i]);
                if(arr[i] < 0)
                    minus_num++;
                sum+=arr[i];
            }
            setColor(WHITE);
            draw();
            printf("Сума всіх елементів масиву: "); setColor(GREEN); printf("%d\n", sum);
            setColor(WHITE);
            ser = (float)sum / n;
            printf("Середнє арифметичне всіх елементів масиву: "); setColor(GREEN);
            printf("%.2f\n", ser);
            setColor(WHITE);
            printf("Кількість від'ємних елементів масиву: "); setColor(GREEN);
            printf("%d\n", minus_num);
            setColor(WHITE);
            if(minus_num > ser)
                for(int i = 0; i < n; i++)
                    arr[i] += 10;
            else
                for(int i = 0; i < n; i++)
                    arr[i] = 0;
                printf("Новий масив: ");
                setColor(GREEN);
                for(int i = 0; i < n; i++)
                    if(i == 0)
                        printf("[%d", arr[i]);
                    else if (i == n-1)
                        printf(", %d]", arr[i]);
                    else
                        printf(", %d", arr[i]);
            printf("\n");
            setColor(WHITE);
            // ------- Кінець обчислень ------- //
            break;
        case 2:
            flag = 1;   break;
        }
        if (flag)   break;
    }while (1);
    return 0;
}