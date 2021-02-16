#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	float a, b, c, P;
	printf("Введіть довжину першої сторони: ");
	scanf("%f", &a);
	printf("Введіть довжину другої сторони: ");
	scanf("%f", &b);
	c = sqrt(a * a + b * b);
	P = a + b + c;
	printf("a\tb\tc\tP\n"); printf("%.2f\t%.2f\t%.2f\t%.2f", a, b, c, P);
	return 0;
}
