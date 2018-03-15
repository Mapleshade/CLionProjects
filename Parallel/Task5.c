// Написать программу, в которой объявить и присвоить начальные значения элементам двумерного массива d[6][8],
// для инициализации значений использовать генератор случайных чисел.
// Используя конструкцию директивы sections…section определить три секции для выполнения следующих операций:
// первая секция выполняет вычисление среднего арифметического значения элементов двумерного массива,
// вторая секция выполняет вычисление минимального и максимального значений элементов двумерного массива,
// третья секция выполняет вычисление количества элементов массива, числовые значения которых кратны 3.
// В каждой секции определить и выдать на экран номер исполняющей нити и результат выполнения вычислений.

#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WOW 30

int main() {

    int d[6][8];
    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            d[i][j] = rand() % WOW;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

#pragma omp parallel sections
    {
#pragma omp section
        {
            int elements = 0;
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    sum += d[i][j];
                    elements++;
                }
            }
            printf("mid is %.2f from %d thread\n", sum * 1.0 / elements, omp_get_thread_num());
        }

#pragma omp section
        {
            int min = WOW + 1;
            int max = -1;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (min > d[i][j]) {
                        min = d[i][j];
                    }
                    if (max < d[i][j]) {
                        max = d[i][j];
                    }
                }
            }
            printf("min is %d and max is %d from %d thread\n", min, max, omp_get_thread_num());
        }

#pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (d[i][j] % 3 == 0) {
                        sum += d[i][j];
                    }
                }
            }
            printf("sum of deviders is %d from %d thread\n", sum, omp_get_thread_num());
        }
    }

}