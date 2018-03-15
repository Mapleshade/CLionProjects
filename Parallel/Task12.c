// 12. Написать программу, в которой, объявить и заполнить случайными значениями массив целых чисел.
// Используя возможности OpenMP найти максимальное числовое значение элементов массива, кратное 7.
// Длину массива и количество потоков определить самостоятельно. Результат выдать на экран.
// Для синхронизации числовых значений максимума используется механизм критических секций. (3 балла)

#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define WOW 300
#define DIVIDER 7

int main() {

    srand(time(NULL));

    int a[WOW];

    int base_max = -1;
    for (int i = 0; i < WOW; i++){
        a[i] = rand() % WOW;
        if (a[i] % DIVIDER == 0 && base_max < a[i]) {
            base_max = a[i];
        }
    }

    int max = -1;
#pragma omp parallel for shared(max)
    for (int i = 0; i < WOW; i++) {
        if (a[i] % DIVIDER == 0 && max < a[i]) {
#pragma omp critical
            {
                max = a[i];
            }
        }
    }

    printf("%d\n", max);
    if (base_max == max) {
        printf("correct\n");
    }
}