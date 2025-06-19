#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
}
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", data[i]);
        if (i < n - 1) printf(" ");
    }
}

void locmemory(double **data, int n) { *data = malloc(sizeof(double) * n); }
void freememory(double *data) { free(data); }

void sort(double *a, int first, int last) {
    if (first < last) {
        int left = first, right = last;
        double pivot = a[(left + right) / 2];

        do {
            while (a[left] < pivot) left++;
            while (a[right] > pivot) right--;

            if (left <= right) {
                double tmp = a[left];
                a[left] = a[right];
                a[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);

        sort(a, first, right);
        sort(a, left, last);
    }
}