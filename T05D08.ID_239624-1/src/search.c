#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 30

void input(int *a, int *n);
// void output(int *a, int n);
double MO(int *a, int n);
double sigma(int *a, int n);
void find(int *a, int n);

int main() {
    int n, arr[NMAX];

    input(arr, &n);
    if (n == -1) {
        printf("n/a");
        return 0;
    }
    find(arr, n);
}

void find(int *a, int n) {
    double mo = MO(a, n);
    double s = sigma(a, n);
    int res = 0;

    for (int *p = a; p - a < n; p++) {
        int num = *p;

        if (*p % 2 == 1) continue;
        if (*p < mo) continue;
        if (*p == 0) continue;
        if (abs(num) > 3 * s) continue;

        res = *p;
        break;
    }

    printf("%d", res);
}

void input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        *n = -1;
    }

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            *n = -1;
        }
    }
}

double MO(int *a, int n) {
    double sum = 0;

    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }

    return sum / n;
}

double sigma(int *a, int n) {
    double sigma = 0;
    double mo = MO(a, n);

    for (int *p = a; p - a < n; p++) {
        sigma += pow(*p - mo, 2);
    }

    return sqrt(sigma);
}
/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
