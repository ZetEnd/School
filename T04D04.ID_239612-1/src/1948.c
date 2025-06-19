#include <math.h>
#include <stdio.h>

int IsSimple(int a);
int MaxDelet(int a);

int main() {
    int a;

    if (scanf("%d", &a) != 1 || a == 0) {
        printf("n/a");
        return 0;
    }

    if (a < 0) a = a * (-1);

    printf("%d", MaxDelet(a));

    return 0;
}

int MaxDelet(int a) {
    int res = -1;

    for (int i = a; i > 0; i--) {
        if (IsSimple(i) == 0) continue;

        int m = a;

        while (m > 0) {
            m = m - i;
        }

        if (m == 0) {
            res = i;
            break;
        }
    }

    return res;
}

int IsSimple(int a) {
    int count = 0;
    for (int i = 1; i <= sqrt(a); i++) {
        int m = a;

        while (m > 0) {
            m = m - i;
        }

        if (m == 0) {
            count++;
        }
    }

    if (count == 1) {
        return 1;
    } else {
        return 0;
    }
}