#include <math.h>
#include <stdio.h>

double f1(double x);
double f2(double x);
double f3(double x);

int main() {
    for (double i = -M_PI; i <= M_PI; i += 2 * M_PI / 41) {
        if (f2(i) == -1) {
            printf("%.7f | %.7f | - | %.7f\n", i, f1(i), f3(i));
        } else {
            printf("%.7f | %.7f | %.7f | %.7f\n", i, f1(i), f2(i), f3(i));
        }
    }

    return 0;
}

double f1(double x) { return 1 / (1 + pow(x, 2)); }

double f2(double x) {
    if (fabs(x) >= sqrt(2)) return -1;
    return sqrt(sqrt(1 + 4 * x * x) - pow(x, 2) - 1);
}

double f3(double x) {
    if (x == 0) return -1;
    return 1 / pow(x, 2);
}