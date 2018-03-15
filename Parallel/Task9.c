//Используя возможности OpenMP написать программу умножения матрицы на вектор.
// Сравнить время выполнения последовательной и параллельных программ.
// Определить размеры матрицы при которых параллельная программа начинает работать
// быстрей последовательной (3 балла)

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


#define WOW 30

int main() {

    int size = 700;

    printf("Matrix : \n");
    int matrix[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % WOW;
            //printf("%d ", matrix[i][j]);
        }
        //printf("\n");
    }


    printf("\n Vector:  ");
    int vec[size];
    for (int i = 0; i < size; i++) {
        vec[i] = rand() % WOW;
        //printf("%d ", vec[i]);
    }
    printf("\n");


    double time = omp_get_wtime();
    // Поcледовательный алгоритм умножения матрицы на вектор
    int c[size];
    for (int i = 0; i < size; i++) {
        c[i] = 0;
        for (int j = 0; j < size; j++) {
            c[i] += matrix[i][j] * vec[j];
        }
        //printf("%d ", c[i]);
    }
    printf("\n");
    printf("\n Time = %lf", (omp_get_wtime()-time)*1000);
    printf("\n Result :  ");
    for (int i = 0; i < size; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    int i, j, rank;
    time = omp_get_wtime();
    /* Создание множества параллельных процессов и в каждом из них задаются
 * свои приватные переменные rank и i*/
#pragma omp parallel shared(matrix, vec, c) private(rank, i)
    {
        rank = omp_get_thread_num();

/* Директива распараллеливания цикла по виткам */
#pragma omp for private(j)
        for (i = 0; i < size; i++) {
            c[i]=0;
            for (j = 0; j < size; j++) {
                c[i] += (matrix[i][j] * vec[j]);

/* Каждый процесс выводит свой порядковый номер, значение витка цикла и
 * значение результирующего вектора на каждом витке цикла и внутри
 * критической секции */
//#pragma omp critical
//            {
//                printf(" rank= %d c[%d]=%d \n", rank, i, c[i]);
//            }
        }
        }/* Конец параллельного цикла */
    } /* Завершение параллельной конструкции */


    printf("\n Parallel Time = %lf", (omp_get_wtime()-time)*1000);

    printf("\n Parallel Result :  ");

    for (int i = 0; i < size; i++) {
        printf("%d ", c[i]);
    }
}

