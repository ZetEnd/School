#include <stdio.h>

#define maxn 10

void input(int *a, int *n);
void output(int *a, int n);
void bubble_sort(int *a, int n);
void swap(int *num1, int *num2);

int main() {
    int n, arr[maxn];
    n = maxn;

    input(arr, &n);
    if (n == -1) {
        printf("n/a");
        return 0;
    }
    bubble_sort(arr, maxn);
    output(arr, maxn);

    return 0;
}

void input(int *a, int *n) {
    // scanf("%d", &d);
    // printf("%d", n);

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            *n = -1;
        };
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
        if (p - a < n - 1) printf(" ");
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