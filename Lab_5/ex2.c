#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../rlutil/rlutil.h"

void draw(){
    setColor(YELLOW);
    printf("************************************\n");
    setColor(WHITE);
}
int main(){
    do {
        const int n = 10, LOW = -1000, HIGH = 1000;
        int flag = 0, less_than_7 = 0, first_el = -1, last_el = -1, sum = 0;
        int choose_it, nums[n], rand_num;
        srand(time(0));
        srand(time(0) * (LOW+rand()%HIGH));
        draw();
        printf("Виберіть спосіб розв'язання задачі:\n"
               "Задавати з клавіатури - 1\n"
               "Заповнити масив випадковими числами - 2\n"
               "Вийти - 3\n");
        setColor(LIGHTGREEN);
        scanf("%d", &choose_it);
        draw();
        switch (choose_it) {
        case 1:
            // ------- Заповнення з клавіатури ------- //
            for(int i = 0; i < n; i++){
                setColor(WHITE);
                printf("Введіть %d елемент масиву: ", i+1);
                setColor(LIGHTGREEN);
                scanf("%d", &nums[i]);

            }
            // ------- Кінець заповнення з клавіатури  //
            break;
        case 2:
            // ------- Заповнення рандомом ----------- //

            for(int i = 0; i < n; i++){
                rand_num = (rand() * 0.00615 - 101);
                nums[i] = rand_num;
            }
            // ------- Кінець заповнення рандомом ---- //
            break;
        case 3: flag = 1; break;
        }
        if (flag)   break;
        // ------- Початок обчислень ------- //
        setColor(WHITE);
        printf("Утворений масив: ");
        for (int i = 0; i < n; i++) {
            if(nums[i] < 7)
                less_than_7++;
            if(first_el == -1 && nums[i] > 0)
                first_el = i;
            if(nums[i] > 0)
                last_el = i;
        }
        setColor(GREY);
        for (int i = 0; i < n; ++i) {
            if(i != 0)
                printf(", ", nums[i]);
            if(i == 0)
                printf("[");
            if(i == first_el)
                setColor(RED);
            else if(i == last_el)
                setColor(GREEN);
                printf("%d", nums[i]);
            setColor(GREY);
            if(i == n-1)
                printf("]\n");
        }

        setColor(LIGHTRED);

        if(last_el == -1){
            printf("В масиві відсутні додатні елементи!\n");
            continue;
        }
        else if(last_el == first_el){
            printf("В масиві тільки 1 додатний елемент!\n");
            continue;
        }
        for(int i = first_el+1; i < last_el; i++)
            sum+=nums[i];
        setColor(WHITE);
        printf("Перший додатний елемент масиву: "); setColor(RED);
        printf("%d\n", nums[first_el]); setColor(WHITE);
        printf("Останній додатний елемент масиву: "); setColor(GREEN);
        printf("%d\n", nums[last_el]); setColor(WHITE);
        printf("Кількість елементів масиву, менших за число сім: ");
        setColor(LIGHTGREEN);    printf("%d\n", less_than_7);
        setColor(WHITE);
        printf("Сума елементів масиву, що розташовані "
               "між першим й останнім додатними елементами: ");
        setColor(LIGHTGREEN);    printf("%d\n", sum);
        // ------- Кінець обчислень ------- //
    }while (1);
    return 0;
}
