#include <stdio.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) == 1 && n > 0) {
        // Don`t forget to allocate memory !
        locmemory(&data, n);

        input(data, n);

        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");

        output(data, n);

        freememory(data);
    }

    return 0;
}
