#include <stdio.h>
#include <stdlib.h>

void input(int **a, int n);
void output(int *a, int n);
void bubble_sort(int *a, int n);
void swap(int *num1, int *num2);

int main() {
    int n, *arr = NULL;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
    } else {
        arr = malloc(sizeof(int) * n);
        if (arr == NULL) {
            printf("n/a");

        } else {
            input(&arr, n);

            if (arr == NULL) {
                printf("n/a");

            } else {
                if (n <= 0) {
                    printf("n/a");

                } else {
                    bubble_sort(arr, n);
                    output(arr, n);
                }
            }
        }
        free(arr);
    }

    return 0;
}

void input(int **a, int n) {
    for (int *p = *a; p - *a < n; p++) {
        if (scanf("%d", p) != 1) {
            free(*a);
            *a = NULL;
            break;
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a != n - 1) printf(" ");
    }
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