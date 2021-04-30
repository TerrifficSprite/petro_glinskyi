#include <stdio.h>
#include "../../rlutil/rlutil.h"
int main(){
    int month;
    printf("Введіть порядковий номер місяця: ");
    scanf("%d", &month);
    if(month > 12 || month < 1){
        setColor(RED);
        printf("Місяця з таким порядковим номером не існує!");
        return 0;
    }
    printf("Місяць з порядковим номером %d - ", month);
    setColor(GREEN);
    switch (month) {
    case 1:
        printf("Січень");
        break;
    case 2:
        printf("Лютий");
        break;
    case 3:
        printf("Березень");
        break;
    case 4:
        printf("Квітень");
        break;
    case 5:
        printf("Травень");
        break;
    case 6:
        printf("Червень");
        break;
    case 7:
        printf("Липень");
        break;
    case 8:
        printf("Серпень");
        break;
    case 9:
        printf("Вересень");
        break;
    case 10:
        printf("Жовтень");
        break;
    case 11:
        printf("Листопад");
        break;
    case 12:
        printf("Грудень");
        break;
    }
    return 0;
}
