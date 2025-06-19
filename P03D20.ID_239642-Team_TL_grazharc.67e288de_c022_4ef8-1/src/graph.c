// построение и вывод графика, в graph.c находится main.
#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "evaluator.h"
#include "parser.h"

#define WIDTH 80
#define HEIGHT 25
#define X_MIN 0.0
#define X_MAX (4 * M_PI)
#define Y_MIN -1.0
#define Y_MAX 1.0

// Вспомогательная функция для масштабирования и отрисовки графика
void draw_graph(TokenArray *rpn) {
    char grid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++) grid[i][j] = '.';

    int error = 0;
    int center_y = HEIGHT / 2;  // Центр по Y — строка 12

    for (int col = 0; col < WIDTH; col++) {
        double x = X_MIN + (X_MAX - X_MIN) * col / (WIDTH - 1);
        double y = eval_expression(rpn, x, &error);
        if (error) {
            printf("n/a\n");
            return;
        }
        if (y < Y_MIN) y = Y_MIN;
        if (y > Y_MAX) y = Y_MAX;

        // Преобразуем y в индекс строки (ось Y направлена вниз)
        int row = center_y - (int)round(y * (HEIGHT / 2.0));
        if (row < 0) row = 0;
        if (row >= HEIGHT) row = HEIGHT - 1;

        grid[row][col] = '*';
    }

    // Вывод графика
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

// Функция main — точка входа программы
int main() {
    char expr[256];
    if (!fgets(expr, sizeof(expr), stdin)) {
        printf("n/a\n");
        return 0;
    }
    expr[strcspn(expr, "\r\n")] = 0;
    if (strlen(expr) == 0) {
        printf("n/a\n");
        return 0;
    }

    TokenArray tokens;
    tokens_init(&tokens);
    if (lex(expr, &tokens) != 0) {
        printf("n/a\n");
        tokens_free(&tokens);
        return 0;
    }

    TokenArray rpn;
    tokens_init(&rpn);
    if (shunting_yard(&tokens, &rpn) != 0) {
        printf("n/a\n");
        tokens_free(&tokens);
        tokens_free(&rpn);
        return 0;
    }
    tokens_free(&tokens);

    draw_graph(&rpn);

    tokens_free(&rpn);
    return 0;
}
