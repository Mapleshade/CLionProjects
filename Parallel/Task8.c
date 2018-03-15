//  Написать программу, в которой объявлен массив из 16000 элементов и инициализирован так, что значение элемента массива равно его порядковому номеру.
//  Затем создайте результирующий массив, в котором (за исключением крайних элементов) будут средние значения исходного массива:
// b[i] = (a[i-1] + a[i] + a[i+1])/3.0
// Запустите программу с 8-ю процессами при различных типах распределения работ.

#include <omp.h>
#include <stdio.h>

#define WOW 16000

void printArray(int a[], int numb) {
    for (int i = 0; i < numb; i++) {
        printf("%.1f ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[WOW];
    double b[WOW];

    for (int i = 0; i < WOW; i++) {
        a[i] = i;
    }

    printArray(a, WOW);

#pragma omp parallel for schedule(static) num_threads(8) shared(b)
    for (int i = 1; i < WOW - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
        printf("%.0f:%d ", b[i], omp_get_thread_num());
        if (i == WOW - 2) printf("\n");
    }

#pragma omp parallel for schedule(dynamic) num_threads(8) shared(b)
    for (int i = 1; i < WOW - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
        printf("%.0f:%d ", b[i], omp_get_thread_num());
        if (i == WOW - 2) printf("\n");
    }

#pragma omp parallel for schedule(dynamic, 3) num_threads(8) shared(b)
    for (int i = 1; i < WOW - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3;
        printf("%.0f:%d ", b[i], omp_get_thread_num());
        if (i == WOW - 2) printf("\n");
    }

    omp_get_wtime();

}