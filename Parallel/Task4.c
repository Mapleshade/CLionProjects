// Написать программу, в которой объявить и присвоить начальные значения целочисленным массивам a[10] и b[10],
// определить параллельную область, количество нитей задать равным 2, выделить код для основной (номер 0) и нити с номером 1.
// Основная нить должна выполнять поиск min значения элементов массива a,
// нить с номером 1 - поиск max значения элементов массива b.

#include <omp.h>
#include <stdio.h>

int main() {

    int a[10] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int min = 100;
    int max = 0;

#pragma omp parallel sections num_threads(2)
    {
#pragma omp section
        {
            for (int i = 0; i < 10; i++) {
                if (min > a[i]) { min = a[i]; }
            }
        }

#pragma omp section
        {
            for (int i = 0; i < 10; i++) {
                if (max < b[i]) { max = b[i]; }
            }
        }
    }

    printf("mix is %d, max is %d\n", min, max);

}