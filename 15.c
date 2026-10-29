#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 10
#define M 100
#define X0 -1.0
#define X1 2.0

float f(float x) {
    float x2 = x * x;
    return (x2 * x2) - (2.0f * x2) + 1.0f;
}

int main() {
    setlocale(LC_ALL, "Russian");

    float a[N], a0[N], s1 = 0.0;

    printf("--- Задание 1 ---\n");
    printf("Введите %d вещественных чисел:\n", N);

    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &a[i]);
        a0[i] = a[i];
        s1 += a[i];
    }

    for (int i = 0; i < N; i++) {
        a[i] = a[i] * 2;
    }

    printf("\n-------------------------------------------------------------------------\n");
    printf("| %-8s | %-20s | %-20s |\n", "Индекс", "Исходное значение", "Новое значение");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("| %-8d | %-20.2f | %-20.2f |\n", i + 1, a0[i], a[i]);
    }
    printf("-------------------------------------------------------------------------\n");
    printf("Среднее арифметическое элементов: %.2f\n\n", s1 / N);

    float b[M];
    float dx = (X1 - X0) / (M - 1);

    float sp = 0.0f;
    float sn = 0.0f;
    int cp = 0;
    int cn = 0;
    float ap = 0.0f;

    printf("--- Задание 2 (Практикум 15) ---\n");

    for (int i = 0; i < M; i++) {
        float x = X0 + i * dx;
        b[i] = f(x);
    }

    for (int i = 0; i < M; i++) {
        if (b[i] > 0) {
            sp += b[i];
            cp++;
        }
        else if (b[i] < 0) {
            sn += b[i];
            cn++;
        }
    }

    if (cp > 0) {
        ap = sp / cp;
    }

    printf("Имя массива: B\n");
    printf("Накопленное значение положительных: %.4f\n", sp);
    printf("Накопленное значение отрицательных: %.4f\n", sn);
    printf("Число положительных элементов: %d\n", cp);
    printf("Число отрицательных элементов: %d\n", cn);
    printf("Среднее значение положительных элементов: %.4f\n\n", ap);

    int li = -1;

    for (int i = M - 1; i >= 0; i--) {
        if (b[i] > 0) {
            li = i;
            break;
        }
    }

    float hs = 0.0f;

    if (li != -1) {
        for (int i = 0; i < li; i++) {
            hs += b[i];
        }
        printf("Индекс последнего положительного элемента: %d\n", li);
        printf("Сумма элементов до последнего положительного: %.4f\n\n", hs);
    }
    else {
        printf("В массиве нет положительных элементов.\n\n");
    }

    float h, mn, mx, xmn, xmx;
    int fp = 1;

    return 0;
}
