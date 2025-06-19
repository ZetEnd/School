#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);

void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
  int *data = NULL, *vertical_res = NULL, *horizontal_res = NULL;
  int rows, cols;

  input(&data, &rows, &cols);

  vertical_res = (int *)malloc(rows * cols * sizeof(int));
  horizontal_res = (int *)malloc(rows * cols * sizeof(int));

  int **data_2d = (int **)malloc(rows * sizeof(int *));
  int **vertical_2d = (int **)malloc(rows * sizeof(int *));
  int **horizontal_2d = (int **)malloc(rows * sizeof(int *));

  for (int i = 0; i < rows; i++) {
    data_2d[i] = &data[i * cols];
    vertical_2d[i] = &vertical_res[i * cols];
    horizontal_2d[i] = &horizontal_res[i * cols];
  }

  // sort_horizontal(data_2d, rows, cols, horizontal_2d);
  // output(horizontal_2d, rows, cols);

  // printf("\n\n");

  sort_vertical(data_2d, rows, cols, vertical_2d);
  output(vertical_2d, rows, cols);

  // printf("\n");
  printf("\n\n");

  sort_horizontal(data_2d, rows, cols, horizontal_2d);
  output(horizontal_2d, rows, cols);

  free(data);
  free(vertical_res);
  free(horizontal_res);
  free(data_2d);
  free(vertical_2d);
  free(horizontal_2d);

  return 0;
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
  int total = n * m;
  int *temp = (int *)malloc(total * sizeof(int));

  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      temp[index++] = matrix[i][j];
    }
  }

  for (int i = 0; i < total - 1; i++) {
    for (int j = 0; j < total - i - 1; j++) {
      if (temp[j] > temp[j + 1]) {
        int t = temp[j];
        temp[j] = temp[j + 1];
        temp[j + 1] = t;
      }
    }
  }

  index = 0;
  for (int j = 0; j < m; j++) {
    if (j % 2 == 0) {
      for (int i = 0; i < n; i++) {
        result_matrix[i][j] = temp[index++];
      }
    } else {
      for (int i = n - 1; i >= 0; i--) {
        result_matrix[i][j] = temp[index++];
      }
    }
  }

  free(temp);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
  int total = n * m;
  int *temp = (int *)malloc(total * sizeof(int));

  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      temp[index++] = matrix[i][j];
    }
  }

  for (int i = 0; i < total - 1; i++) {
    for (int j = 0; j < total - i - 1; j++) {
      if (temp[j] > temp[j + 1]) {
        int t = temp[j];
        temp[j] = temp[j + 1];
        temp[j + 1] = t;
      }
    }
  }

  index = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < m; j++) {
        result_matrix[i][j] = temp[index++];
      }
    } else {
      for (int j = m - 1; j >= 0; j--) {
        result_matrix[i][j] = temp[index++];
      }
    }
  }

  free(temp);
}

void input(int **matrix, int *n, int *m) {
  if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) {
    printf("n/a");
    exit(0);
  }

  *matrix = (int *)malloc(*n * *m * sizeof(int));

  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *m; j++) {
      if (scanf("%d", &(*matrix)[i * *m + j]) != 1) {
        printf("n/a");
        exit(0);
      }
    }
  }
}

void output(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", matrix[i][j]);
      if (j < m - 1) {
        printf(" ");
      }
    }
    if (i < n - 1) {
      printf("\n");
    }
  }
}