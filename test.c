#include <stdio.h>
#include "../rlutil/rlutil.h"
#include <stdlib.h>
#include <time.h>
#include "library/lib.c"
#include "stdio.h"
#include "math.h"

int main() {
  int x;
  float n;

  printf("Введіть n: ");
  scanf("%f", &n);
  printf("Введіть x: ");
  scanf("%d", &x);

  float j, i, s, p = 0;
  for (i = 1; i <= n; i++) {
    for (s = 1, j = 1; j <= i; j++) {
      s *= i+x;
    }
    p += s;
  }
  printf("\n***Результати***\n");
  printf("Відповідь: ");
  setColor(GREEN);
  printf("%.f\n", p);
  setColor(WHITE);
  return 0;
}

    //printf("%d, ", random(-100, 100));
    //setColor(BLACK);
//printf("************************************\n");
//setColor(BLUE);
//printf("************************************\n");
//setColor(CYAN);
//printf("**************************************\n");
//setColor(LIGHTCYAN);
//printf("**************************************\n");
//setColor(MAGENTA);
//printf("************************************\n");
//setColor(DARKGREY);
//printf("************************************\n");
//setColor(LIGHTBLUE);
//printf("************************************\n");
//setColor(LIGHTGREEN);
//printf("************************************\n");
//setColor(LIGHTRED);
//printf("************************************\n");
//setColor(LIGHTMAGENTA);
//printf("************************************\n");
//setColor(YELLOW);
//printf("************************************\n");
//setColor(BROWN);
//printf("************************************\n");
//setColor(GREY);
//printf("************************************\n");
//}

// delete this

// delete this