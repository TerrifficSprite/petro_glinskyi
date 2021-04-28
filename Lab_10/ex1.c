#include <stdio.h>
#include "../rlutil/rlutil.h"
#include "../library/lib.c"
int main(){
    do {
        int space_flag = 0;
        int first_el = -1, last_el = -1, max = 0, now = 0;
        char str[100];
        draw(YELLOW);
            printf("Введіть рядок символів: ");
            fgets(str, 100, stdin);
            int j = 0;
            for (int i = 0; str[i] != '\0'; i++) {
                if(i == 0)
                    first_el = i;
                if(str[i] == ' ' || str[i+1] == '\0'){
                    if(max < now){
                        max = now;
                        for(j = i; str[j-1] != ' ' && j != 0; j--)
                            first_el = j;
                        last_el = i;
                    }
                    now = 0;
                    continue;
                }
                if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
                        || str[i] == 'o' || str[i] == 'u' || str[i] == 'y'
                        || str[i] == 'A' || str[i] == 'E' || str[i] == 'I'
                        || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y')
                {
                    now++;
                }
            }
            printf("Рядок без лишніх пробілів: ");
            setColor(BLUE);
            for(int i = 0; str[i] != '\0'; i++){
                if(str[i] != ' ')
                    space_flag = 1;
                if(str[i] == ' ' && !space_flag)
                    continue;
                if(str[i] == ' ')
                    space_flag = 0;
                printf("%c", str[i]);
            }
            if(max == 0){
                setColor(RED);
                printf("В рядку немає слів з голосними літерами!\n");
                continue;
            }
            setColor(WHITE);
            printf("Слово яке має найбільшу кількість голосних літер: ");
            setColor(GREEN);
            for(int i = first_el-1; i <= last_el; i++)
                printf("%c", str[i]);
            printf("\n");
    }while (1);
    return 0;
}


