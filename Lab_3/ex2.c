#include <stdio.h>
int main(){
    int a, i = 1, sum = 0, n = 0;
    do {
        printf("Виберіть цикл для обчислення.\nfor - 1\nwhile - 2\ndo while - 3\n");
        scanf("%d", &a);
        switch (a) {
        case 1: // Цикл for
            for(int i = 1; i < 80; i+=2, n++)
                sum+=i;
            break;
        case 2: // Цикл while
            while (i < 80){
                if(i % 2 != 0) {
                    sum += i;
                    n++;
                }
                i++;
            }
            break;
        case 3: // Цикл do while
            do {
                if(i % 2 != 0) {
                    sum += i;
                    n++;
                }
                i++;
            }
            while (i < 80);
            break;
        default:
            printf("Виберіть число 1, 2 або 3\n");
            continue;
        }
        sum/=n;
        printf("Середнє арифметичне всіх непарних чисел у діапазоні 1 - 80: %d. "
               "Обчислено циклом ", sum);
        switch (a) {
        case 1:
            printf("for");
            break;
        case 2:
            printf("while");
            break;
        case 3:
            printf("do while");
        }
        break;
    }
    while (1);
    return 0;
}