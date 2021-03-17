#include <stdio.h>
int main(){
    int n;
    float a, s, dobutok = 1;
    printf("\n");
    printf("Введіть дійсне число a: ");
    scanf("%f", &a);
    printf("Введіть натуральне число n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        s = a;
        for (float j = 1; j <= i; j++)
                s+=j;
        dobutok*=s;
    }
    printf("Результат - %.2f\n", dobutok);
    return 0;
}
