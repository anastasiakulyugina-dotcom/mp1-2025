#include <stdio.h>
#include "FTaylor.h"
#include <locale.h>


int main() {
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");

	int choice, n;
    double x;

    printf("Выберите функцию:\n");
    printf("0 - e^x\n");
    printf("1 - sin(x)\n");
    printf("2 - cos(x)\n");
    printf("3 - ln(1+x)\n");
    scanf_s("%d", &choice);

    printf("x: ");
    scanf_s("%lf", &x);

    printf("Количество: ");
    scanf_s("%d", &n);

    FType type;
    if (choice == 0) type = FUNC_EXP;
    else if (choice == 1) type = FUNC_SIN;
    else if (choice == 2) type = FUNC_COS;
    else if (choice == 3) type = FUNC_LN;

    double res = taylor(x, type, n);

    printf("%f", res);
    return 0;
}