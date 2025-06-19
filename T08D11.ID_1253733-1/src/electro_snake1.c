#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int ***result_matrix);




/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int ***result_matrix);


void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void quick_sort(int *a, int first, int last);
void swap(int *num1, int *num2);


int main()
{
    int **matrix, **result;
    int n,m;

    input(&matrix, &n, &m);
    //output(matrix, n, m);
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/
    
    sort_vertical(matrix, n, m, &result);
    output(result, n, m);
    //free(result);
    result = NULL;

    printf("\n\n");
    
    sort_horizontal(matrix, n, m, &result);
    output(result, n, m);
    free(matrix);
    //free(result);
}

void input(int ***matrixXX, int *n, int *m){

    scanf("%d %d", n, m);

    int** matrix = malloc(sizeof(int)* (*n)*(*m) + sizeof(int*)*(*n));
    int* ptr = (int*)(matrix + *n);

    for(int i = 0; i < *n; i++){
        (matrix)[i] = ptr + i*(*m);
    }

    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++){
            scanf("%d", &(matrix)[i][j]);
        }
    }

    /*for(int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++){
            printf("%d ", (matrix)[i][j]);
        }
        printf("\n");
    }*/
    *matrixXX = matrix;

}

void output(int **matrix, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}

void sort_vertical(int **matrix, int n, int m, int ***result_matrix){

    int* arr = malloc(sizeof(int)*n*m);
    int y = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[y] = matrix[i][j];
            y++;
        }
    }

    quick_sort(arr, 0, m*n-1);
    y = 0;
    /*for(int i = 0; i < m*n; i++){
        printf("%d ",arr[i]);
    }*/

    int z = 0;


    for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i % 2 == 0){
                matrix[j][i] = arr[y];
                y++;
                } else{
                    matrix[j][i] = arr[(i+1)*n-z-1];
                    y++;
                    z++;
                }
            }
            z = 0;
        }

    free(arr);

    *result_matrix = matrix;
    //output(matrix, n,m);



}
/*
    1 6 7
    2 5 8
    3 4 9
*/


void sort_horizontal(int **matrix, int n, int m, int ***result_matrix){

    int* arr = malloc(sizeof(int)*n*m);
    int y = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[y] = matrix[i][j];
            y++;
        }
    }

    quick_sort(arr, 0, m*n-1);
    y = 0;
    /*for(int i = 0; i < m*n; i++){
        printf("%d ",arr[i]);
    }*/

    int z = 0;


    for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i % 2 == 0){
                matrix[j][i] = arr[y];
                y++;
                } else{
                    matrix[j][i] = arr[(j+1)*m-z-1];
                    y++;
                    z++;
                }
            }
            z = 0;
        }

    free(arr);
    *result_matrix = matrix;
    //output(matrix, n,m);
}
/*
    1 2 3
    6 5 4
    7 8 9
*/



void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle) left++;

            while (a[right] > middle) right--;

            if (left <= right) {
                swap(a + left, a + right);
                left++;
                right--;
            }

        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void swap(int *num1, int *num2) {
    int buf = *num1;
    *num1 = *num2;
    *num2 = buf;
}