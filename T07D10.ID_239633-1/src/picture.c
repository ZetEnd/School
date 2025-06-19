#include <stdio.h>
#include <stdlib.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void print_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(&picture_data[0][0], picture, N, M);

    make_picture(picture, N, M);
    print_picture(picture, N, M);

    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int j = 0; j < length_frame_h; j++) {
        for (int i = 0; i < length_frame_w; i++) {
            picture[j][i] = 0;
            if (j > 0 && j < 7) {
                if (i > 6 && i < 12) picture[j][i] = sun_data[j - 1][i - 7];
            };
            if (j < 5 && j > 2 && i > 1 && i < 6) picture[j][i] = tree_foliage[i - 2];
            if (i < 5 && i > 2 && j < 6 && j > 1) picture[j][i] = tree_foliage[j - 2];
            if (j > 5 && j < 10 && i > 2 && i < 5) picture[j][i] = tree_trunk[j - 6];
            if (j > 9 && j < 11 && i > 1 && i < 6) picture[j][i] = tree_trunk[i - 2];
            if (j == 0 || j == 7 || j == 14) picture[j][i] = frame_w[i];
            if (i == 0 || i == 6 || i == 12) picture[j][i] = frame_h[j];
        }
    }
}
void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void print_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (picture[i][j] == 0)
                printf("0 ");
            else if (j == 12 && i < 14)
                printf("%d\n", picture[i][j]);
            else
                printf("%d ", picture[i][j]);
        }
    }
}