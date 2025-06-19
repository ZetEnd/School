#include <stdio.h>
#include <stdlib.h>

int stat(int M, int N);
int dinamic_1(int M, int N);
int dinamic_2(int M, int N);
int dinamic_3(int M, int N);
void output(int* arr, int M);

int main() {
    int choice;
    int M, N;
    scanf("%d", &choice);

    int M_max = 100, N_max = 100;

    switch (choice) {
        case 1:
            if (scanf("%d%d", &M, &N) != 2 || M > M_max || N > N_max) {
                printf("n/a");
                return 1;
            }
            stat(M, N);
            break;

        case 2:

            if (scanf("%d%d", &M, &N) != 2) {
                printf("n/a");
                return 1;
            }
            dinamic_1(M, N);
            break;

        case 3:
            if (scanf("%d%d", &M, &N) != 2) {
                printf("n/a");
                return 1;
            }
            dinamic_2(M, N);
            break;

        case 4:
            if (scanf("%d%d", &M, &N) != 2) {
                printf("n/a");
                return 1;
            }
            dinamic_3(M, N);
            break;

        default:
            printf("n/a");
            break;
    };
    return 0;
}

void maxel(int** arr, int M, int N) {
    int maxS = 0, minS = 0;
    int *arrStroka, *arrStolbec;

    arrStroka = malloc(M * sizeof(int));
    arrStolbec = malloc(N * sizeof(int));
    for (int i = 0; i < M; i++) {
        arrStroka[i] = arr[i][0];
    }

    for (int i = 0; i < N; i++) {
        arrStolbec[i] = arr[0][i];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (maxS < arr[i][j]) maxS = arr[i][j];

            // if(arr[i][j] < arrStolbec[j]) arrStolbec[s] = arr[i][j];

            for (int s = 0; s < M; s++) {
                if (arr[i][j] < arrStolbec[j]) arrStolbec[s] = arr[i][j];
            }
        }
        arrStroka[i] = maxS;
    }
    printf("\n");
    output(arrStroka, M);
    printf("\n");
    output(arrStolbec, N);
}

void output(int* arr, int M) {
    for (int i = 0; i < M; i++) {
        printf("%d", arr[i]);
        if (i < M - 1) printf(" ");
    }
}

int stat(int M, int N) {
    int i, j;
    int element[M][N];

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &element[i][j]);
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", element[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        if (i < M - 1) {
            printf("\n");
        }
    }

    // maxel(element, M, N);
    return 0;
}

int dinamic_1(int M, int N) {
    int i, j;
    int** single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int*));
    int* ptr = (int*)(single_array_matrix + M);
    int count = 0;

    for (int i = 0; i < M; i++) {
        single_array_matrix[i] = ptr + N * i;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            single_array_matrix[i][j] = ++count;
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &single_array_matrix[i][j]);
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", single_array_matrix[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        if (i < M - 1) {
            printf("\n");
        }
    }
    maxel(single_array_matrix, M, N);

    free(single_array_matrix);

    return 0;
}

int dinamic_2(int M, int N) {
    int i, j;
    int** pointer_array = malloc(M * sizeof(int*));

    for (int i = 0; i < M; i++) {
        pointer_array[i] = malloc(N * sizeof(int));
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &pointer_array[i][j]);
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", pointer_array[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        if (i < M - 1) {
            printf("\n");
        }
    }

    for (int i = 0; i < M; i++) {
        free(pointer_array[i]);
    }
    free(pointer_array);

    return 0;
}

int dinamic_3(int M, int N) {
    int i, j;
    int** pointer_array = malloc(M * sizeof(int*));
    int* values_array = malloc(M * N * sizeof(int));

    for (int i = 0; i < M; i++) {
        pointer_array[i] = values_array + N * i;
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &pointer_array[i][j]);
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", pointer_array[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        if (i < M - 1) {
            printf("\n");
        }
    }

    free(values_array);
    free(pointer_array);

    return 0;
}