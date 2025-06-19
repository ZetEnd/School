#include <math.h>
#include <stdio.h>
#define NMAX 10

void input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    input(data, &n);
    if (n == -1) {
        printf("n/a");
        return 0;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}
int max(int *a, int n) {
    int maxA = *a;

    for (int *p = a + 1; p - a < n; p++) {
        if (*p > maxA) maxA = *p;
    }

    return maxA;
}

int min(int *a, int n) {
    int minA = *a;

    for (int *p = a + 1; p - a < n; p++) {
        if (*p < minA) minA = *p;
    }
    return minA;
}
double SUM(int *a, int n) {
    double sumA = 0;

    for (int *p = a; p - a < n; p++) {
        sumA += *p;
    }

    return sumA;
}
double mean(int *a, int n) { return SUM(a, n) / n; }
double variance(int *a, int n) {
    double var = 0;
    double meanA = mean(a, n);

    for (int *p = a; p - a < n; p++) {
        var += pow((*p - meanA), 2);
    }

    return var / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}
