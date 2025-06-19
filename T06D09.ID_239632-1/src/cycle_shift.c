#include <stdio.h>

#define maxn 10

void input(int *a, int *n);
void output(int *a, int n);
void track(int *res, int *a, int n, int c);

int main() {
    int arr[maxn], n, c, res[maxn];
    input(arr, &n);
    if (n <= 0) {
        printf("n/a");
    } else {
        scanf("%d", &c);
        if (c > n) c = c % n;
        track(res, arr, n, c);
        output(res, n);
    }
    return 0;
}

void track(int *res, int *a, int n, int c) {
    int *mas = res;

    for (int *p = a; p - a < n; p++) {
        if (p + c < a + n) {
            *mas = *(p + c);

        } else {
            *mas = *(p - n + c);
        }
        mas++;
    }
}

void input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        *n = -1;
    }

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            *n = -1;
            break;
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a < n - 1) printf(" ");
    }
}