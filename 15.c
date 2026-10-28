#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 100
#define X_MIN -10.0
#define X_MAX 10.0
#define N 10

int main() {
    setlocale(LC_ALL, "Russian");

    float A[N];
    float original_A[N];
    float sum = 0.0;
    float average = 0.0;

    printf("Введите %d вещественных чисел:\n", N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &A[i]);
        original_A[i] = A[i];
        sum += A[i];
    }

    average = sum / N;

    for (int i = 0; i < N; i++) {
        A[i] = A[i] * 2;
    }

    printf("\n-------------------------------------------------------------------------\n");
    printf("| %-8s | %-20s | %-20s |\n", "индекс", "исходное значение", "новое значение|");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("| %-8d | %-20.2f | %-20.2f |\n", i, original_A[i], A[i]);
    }
    printf("-----------------------------------------------------------\n");

    printf("\nСреднее арифметическое исходных элементов: %.2f\n", average);

    return 0;

}