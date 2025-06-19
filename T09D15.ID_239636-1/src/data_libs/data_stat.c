#include "data_stat.h"
// #include <math.h>

double max(double *data, int n) {
    double maxdata = data[0];

    for (int i = 1; i < n; i++) {
        if (data[i] > maxdata) maxdata = data[i];
    }

    return maxdata;
}
double min(double *data, int n) {
    double mindata = data[0];

    for (int i = 1; i < n; i++) {
        if (data[i] < mindata) mindata = data[i];
    }

    return mindata;
}
double mean(double *data, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += data[i];
    }

    double meandata = sum / n;

    return meandata;
}
double variance(double *data, int n) {
    double meandata = mean(data, n);

    double var = 0;

    for (int i = 0; i < n; i++) {
        var += (data[i] - meandata) * (data[i] - meandata);
    }

    var = var / n;

    return var;
}
