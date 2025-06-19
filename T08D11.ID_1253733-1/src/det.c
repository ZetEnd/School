#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
int input(double **matrix, int *n, int *m);
void output(double det);

int main() {
    int n;
    int m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0 || n != m)
        printf("n/a");
    else {
        double **matrix = malloc(n * sizeof(double *));
        if (matrix == NULL) {
            printf("n/a");
        } else {
            for (int i = 0; i < n; i++) {
                matrix[i] = malloc(m * sizeof(double));
                if (matrix[i] == NULL) {
                    for (int j = 0; j < i; j++) {
                        free(matrix[j]);
                    }
                    free(matrix);
                    printf("n/a");
                }
            }
            if (input(matrix, &n, &m)) {
                double det_matrix = det(matrix, n);
                output(det_matrix);

            } else
                printf("n/a");
            if (matrix != NULL) {
                for (int i = 0; i < n; i++) {
                    free(matrix[i]);
                }
                free(matrix);
            }
        }
    }
}

int input(double **matrix, int *n, int *m) {
    int flag = 1;
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                for (int k = 0; k < *n; k++) {
                    flag = 0;
                    break;
                }
            }
        }
    }
    return flag;
}

double det(double **matrix, int n) {
    double det_m = 0;
    if (n == 1)
        det_m = matrix[0][0];
    else if (n == 2) {
        det_m = matrix[0][0] * matrix[1][1] - (matrix[0][1] * matrix[1][0]);
    } else {
        for (int i = 0; i < n; i++) {
            double **minor = malloc((n - 1) * sizeof(double *));
            for (int k = 0; k < n - 1; k++) {
                minor[k] = malloc((n - 1) * sizeof(double));
            }
            for (int k = 1; k < n; k++) {
                int y = 0;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        minor[k - 1][y] = matrix[k][j];
                        y++;
                    }
                }
            }
            det_m += pow(-1, i) * matrix[0][i] * det(minor, n - 1);

            for (int k = 0; k < n - 1; k++) {
                free(minor[k]);
            }
            free(minor);
        }
    }

    return det_m;
}

void output(double det) { printf("%.6f", det); }