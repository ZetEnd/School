#include <stdio.h>
#include <stdlib.h>

#define NMAX 10
#define MMAX 10

void first(int ***arr, int* n, int* m){

    scanf("%d %d",n,m);

    int **mas = malloc(sizeof(int*)*(*n) + sizeof(int)*(*n)*(*m));

    //int *ptr = (int*)(mas+ *n);
    int *ptr = (int*)(mas+ *n);

    for(int i = 0; i < *n; i++){
        mas[i] = ptr + i*(*m);
    }

    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++){
            scanf("%d", &mas[i][j]);
        }
    }

    /*for(int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++){
            printf("%d",mas[i][j]);
        }
    }*/

    *arr = mas;

}

void second(int *** arr, int*n, int *m){


    scanf("%d %d", n, m);

    int ** mas = malloc(sizeof(int*) * (*n));

    for(int i = 0; i < *n; i++){
        mas[i] = malloc(sizeof(int)*(*m));
    }

    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++){
            scanf("%d", &mas[i][j]);
        }
    }

    *arr = mas;


}

void third(int ***arr, int *n, int *m){

    scanf("%d %d", n,m);

    int ** mas = malloc(sizeof(int*) * (*n));

    int * ptr = malloc(sizeof(int)* (*n) * (*m));

    for(int i = 0; i < *n; i++){
        mas[i] = ptr + i * (*m);
    }

    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++){
            //scanf("%d", mas[i]+j);
            scanf("%d", &mas[i][j]);
        }
    }

    *arr = mas;
}

void fourth(int (*mas)[MMAX][MMAX], int *n, int *m){

    scanf("%d", n);
    scanf("%d", m);
    
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            scanf("%d", &(*mas)[i][j]);  // Просто mas[i][j], без (*mas)
        }
    }
    
    // Вывод для проверки
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("%d ", (*mas)[i][j]);
        }
        printf("\n");
    }

}


void output(int ** arr, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //printf("%d",arr[i][j]);
            printf("%d",*(*(arr+i)+j));
            if(j < m-1) printf(" ");
        }
        printf("\n");
    }
    free(arr);

}

void in(int (*mas)[MMAX], int *n, int *m) {  // Принимаем указатель на строку статического массива
    scanf("%d", n);
    scanf("%d", m);
    
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            scanf("%d", &mas[i][j]);  // Просто mas[i][j], без (*mas)
        }
    }
    
    // Вывод для проверки
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int** arr;
    int mas[NMAX][MMAX];
    //int **p = mas;
    int n, m;
    //first(&arr, &n, &m);
    //second(&arr, &n, &m);
    //third(&arr, &n, &m);
    //in(mas, &n, &m);
    fourth(&mas, &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //printf("%d",arr[i][j]);
            printf("%d",mas[i][j]);
            if(j < m-1) printf(" ");
        }
        printf("\n");
    }
    //printf("%d", arr);
    //output(arr, n,m);
    //output(mas, n,m);

}