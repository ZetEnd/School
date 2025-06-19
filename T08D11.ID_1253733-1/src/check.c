#include <stdio.h>
#include <stdlib.h>

int main(){

    int n,m;

    scanf("%d %d", &n, &m);

    int** matrix = malloc(sizeof(int)*(n)*(m) + sizeof(int*)*(n));
    int* ptr = (int*)(matrix + n);

    for(int i = 0; i < n; i++){
        matrix[i] = ptr + i*(m);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);
}