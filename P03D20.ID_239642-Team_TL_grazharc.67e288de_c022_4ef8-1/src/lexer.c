// лексический анализатор, разбивает строку на токены.
#include "lexer.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Проверка, является ли строка именем поддерживаемой функции
int is_function_name(char *s) {
    const char *funcs[] = {"sin", "cos", "tan", "exp", "ln", "ctg", "sqrt", "abs", NULL};
    for (int i = 0; funcs[i] != NULL; i++) {
        if (strcmp(s, funcs[i]) == 0) return 1;
    }
    return 0;
}

// Инициализация массива токенов
void tokens_init(TokenArray *arr) {
    arr->size = 0;
    arr->capacity = 16;
    arr->tokens = malloc(sizeof(Token) * arr->capacity);
}

// Освобождение памяти массива токенов
void tokens_free(TokenArray *arr) {
    free(arr->tokens);
    arr->tokens = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

// Вспомогательная функция добавления токена в массив
static void tokens_push(TokenArray *arr, Token t) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->tokens = realloc(arr->tokens, sizeof(Token) * arr->capacity);
    }
    arr->tokens[arr->size++] = t;
}

// Лексический анализ выражения
int lex(const char *expr, TokenArray *tokens) {
    int i = 0;
    int len = (int)strlen(expr);
    while (i < len) {
        if (isspace(expr[i])) {
            i++;
            continue;
        }
        // Число (целое или с плавающей точкой)
        if (isdigit(expr[i]) || (expr[i] == '.' && i + 1 < len && isdigit(expr[i + 1]))) {
            int start = i;
            int dot_count = 0;
            while (i < len && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') dot_count++;
                if (dot_count > 1) return -1;  // Ошибка: более одной точки
                i++;
            }
            char buf[32];
            int n = i - start;
            if (n >= (int)sizeof(buf)) return -1;
            strncpy(buf, expr + start, n);
            buf[n] = '\0';
            Token t;
            t.type = TOK_NUMBER;
            t.value = atof(buf);
            tokens_push(tokens, t);
            continue;
        }
        // Переменная x
        if (expr[i] == 'x') {
            Token t;
            t.type = TOK_VARIABLE;
            strcpy(t.str, "x");
            t.value = 0.0;
            tokens_push(tokens, t);
            i++;
            continue;
        }
        // Скобки
        if (expr[i] == '(') {
            Token t;
            t.type = TOK_LPAREN;
            t.value = 0.0;
            tokens_push(tokens, t);
            i++;
            continue;
        }
        if (expr[i] == ')') {
            Token t;
            t.type = TOK_RPAREN;
            t.value = 0.0;
            tokens_push(tokens, t);
            i++;
            continue;
        }
        // Операторы
        if (strchr("+-*/^", expr[i]) != NULL) {
            Token t;
            t.type = TOK_OPERATOR;
            t.str[0] = expr[i];
            t.str[1] = '\0';
            t.value = 0.0;
            tokens_push(tokens, t);
            i++;
            continue;
        }
        // Функции (sin, cos, ...)
        if (isalpha(expr[i])) {
            int start = i;
            while (i < len && isalpha(expr[i])) i++;
            int n = i - start;
            if (n >= (int)sizeof(((Token *)0)->str)) return -1;
            char buf[16];
            strncpy(buf, expr + start, n);
            buf[n] = '\0';
            if (is_function_name(buf)) {
                Token t;
                t.type = TOK_FUNCTION;
                strcpy(t.str, buf);
                t.value = 0.0;
                tokens_push(tokens, t);
                continue;
            } else {
                return -1;  // Неизвестная функция
            }
        }
        return -1;  // Неизвестный символ
    }
    return 0;
}
