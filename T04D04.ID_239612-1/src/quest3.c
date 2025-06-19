#include <math.h>
#include <stdio.h>

int f(int a);

int main() {
    int a;

    if (scanf("%d", &a) != 1 || a < 1) {
        printf("n/a");
        return 0;
    }

    // if(a )

    printf("%d", f(a));

    return 0;
}

int f(int a) {
    if (a == 0 || a == 1) {
        return a;
    }

    return f(a - 1) + f(a - 2);
}