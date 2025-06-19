#include <stdio.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) == 1 && n > 0) {
        locmemory(&data, n);

        input(data, n);

        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");

        freememory(data);
    }
    return 0;
}
