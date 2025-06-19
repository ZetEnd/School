#include <stdio.h>
#include <stdlib.h>

void input(int **a, int *n);
void output(int *a, int n);
void bubble_sort(int *a, int n);
void swap(int *num1, int *num2);

int main() {
    int n, *arr = NULL;

    input(&arr, &n);

    if (n == -1) {
        printf("n/a");
    } else {
        bubble_sort(arr, n);
        output(arr, n);
    }

    return 0;
}

void input(int **a, int *n) {
    // scanf("%d", &d);
    if (scanf("%d", n) != 1 || *n <= 0) {
        *n = -1;
    }

    // printf("%d ", *n);

    // int* mas = malloc(sizeof(int)*(*n));
    // a = mas;
    // printf("%d ", *n);
    *a = calloc(*n, sizeof(int));
    if (*a == NULL) {
        *n = -1;
    }

    for (int *p = *a; p - *a < *n; p++) {
        if (scanf("%d", p) != 1) {
            free(*a);
            *a = NULL;
            *n = -1;
        }
        // printf("%d", *p);
    }

    // printf("%d ", *n);
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a != n - 1) printf(" ");
    }

    free(a);
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(a + j) > *(a + j + 1)) {
                swap((a + j), (a + j + 1));
            }
        }
    }
}

void swap(int *num1, int *num2) {
    int buf = *num1;
    *num1 = *num2;
    *num2 = buf;
}