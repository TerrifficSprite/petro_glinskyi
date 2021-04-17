#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../rlutil/rlutil.h"
#include "../library/lib.c"
float Leng(float x1, float y1, float x2, float y2){
    if(x1 == x2 && y1 == y2)
        return -1;
    float len = fabs(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    return len;
}
int main(){
    do {
        int choose_it;
        float Ax, Bx, Cx, Dx, Ay, By, Cy, Dy;
        float AB, BC, CD;
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
        printf("Точка А, координата х: ");
        Ax = inputf(GREEN);
        printf("Точка А, координата y: ");
        Ay = inputf(GREEN);
        printf("\nТочка B, координата х: ");
        Bx = inputf(GREEN);
        printf("Точка B, координата y: ");
        By = inputf(GREEN);
        printf("\nТочка C, координата х: ");
        Cx = inputf(GREEN);
        printf("Точка C, координата y: ");
        Cy = inputf(GREEN);
        printf("\nТочка D, координата х: ");
        Dx = inputf(GREEN);
        printf("Точка D, координата y: ");
        Dy = inputf(GREEN);
        AB = Leng(Ax, Ay, Bx, By);
        BC = Leng(Bx, By, Cx, Cy);
        CD = Leng(Cx, Cy, Dx, Dy);
        setColor(YELLOW);
        printf("-------------------------\n");
        setColor(WHITE);
        if(AB == -1)
            printf("Точки А та В мають однакові координати\n");
        else{
            printf("Довжина відрізка АВ: ");
            setColor(GREEN); printf("%.2f\n", AB); setColor(WHITE);
        }
        if(BC == -1)
            printf("Точки B та C мають однакові координати\n");
        else{
            printf("Довжина відрізка BC: ");
            setColor(GREEN); printf("%.2f\n", BC); setColor(WHITE);
        }
        if(CD == -1)
            printf("Точки C та D мають однакові координати\n");
        else{
            printf("Довжина відрізка CD: ");
            setColor(GREEN); printf("%.2f\n", CD); setColor(WHITE);
        }
        // ---- Кінець обчислень ----- //
    }while (1);
    return 0;
}
