// Написать программу, в которой объявить и присвоить начальные значения элементам двумерного массива d[6][8],
// для инициализации значений использовать генератор случайных чисел.
// Используя конструкцию директивы omp parallel for и omp critical определить минимальное и максимальное значения элементов двумерного массива.
// Количество нитей задать самостоятельно. Результат выдать на экран.
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WOW 30

int main() {

    int width = 6;
    int height = 8;

    int d[width][height];
    srand(time(NULL));

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            d[i][j] = rand() % WOW;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    int max = -1;
    int min = WOW + 1;

    int counter = 0;
#pragma omp parallel num_threads(6) reduction(+: counter)
    for (int i = 0; i < width; i++) {
#pragma omp for
        for (int j = 0; j < height; j++) {
            counter++;
            if (min > d[i][j]) {
#pragma omp critical (first)
                min = d[i][j];
            }
            if (max < d[i][j]) {
#pragma omp critical (second)
                max = d[i][j];
            }
        }
    }
    printf("counter is %d\n", counter);
    printf("min is %d, max is %d\n", min, max);

}