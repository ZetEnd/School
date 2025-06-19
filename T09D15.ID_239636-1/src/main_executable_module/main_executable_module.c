#include <stdio.h>

#include "../data_libs/data_io.h"
#include "../yet_another_decision_module/decision.h"

#ifdef USE_DYNAMIC
#include "data_process.so"
#else
#include "../data_module/data_process.h"
#endif

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) == 1 && n > 0) {
        locmemory(&data, n);

        printf("LOAD DATA...\n");
        input(data, n);

        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, 0, n - 1);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        // make_decision(data, n);
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
        //...

        freememory(data);
    }

    return 0;
}
