#include <stdio.h>
#define NMAX 10

void input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    // printf("ss %d %dss", data[0], *data);
    if (n == -1) {
        printf("n/a");
        return 0;
    }
    squaring(data, &n);
    output(data, &n);

    return 0;
}

void input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        *n = -1;
    }
    // printf("%d", *n);
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            *n = -1;
        }
        // printf("%d", *p);
    }
}

void output(int *a, int *n) {
    // printf("gg %d gg", *a);
    for (int *p = a; p - a < *n; p++) {
        printf("%d ", *p);
    }
    // printf("dffdf");
    // NOTHING
}

void squaring(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        *p = (*p) * (*p);
    }
    // NOTHING
}
