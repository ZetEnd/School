#ifndef LEXER_H
#define LEXER_H

// Типы токенов
typedef enum {
    TOK_NUMBER,
    TOK_VARIABLE,
    TOK_OPERATOR,
    TOK_FUNCTION,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_INVALID
} TokenType;

// Структура токена
typedef struct {
    TokenType type;  // Тип токена
    char str[16];  // Имя функции или оператора (для функций и операторов)
    double value;  // Значение (для чисел)
} Token;

// Динамический массив токенов
typedef struct {
    Token *tokens;
    int size;
    int capacity;
} TokenArray;

// Инициализация массива токенов
void tokens_init(TokenArray *arr);

// Освобождение памяти массива токенов
void tokens_free(TokenArray *arr);

int is_function_name(char *s);

// Лексический анализ: разбивает строку expr на токены
// Возвращает 0 при успехе, -1 при ошибке
int lex(const char *expr, TokenArray *tokens);

#endif
