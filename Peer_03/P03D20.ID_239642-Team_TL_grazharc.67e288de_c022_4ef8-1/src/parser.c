// алгоритм Дейкстры для преобразования в обратную польскую нотацию.
#include "parser.h"

#include <stdlib.h>
#include <string.h>

// Определение приоритета операторов и функций
static int precedence(Token *t) {
    if (t->type == TOK_FUNCTION) return 5;
    if (t->type == TOK_OPERATOR) {
        if (t->str[0] == '+' || t->str[0] == '-') return 2;
        if (t->str[0] == '*' || t->str[0] == '/') return 3;
        if (t->str[0] == '^') return 4;
    }
    return 0;
}

// Проверка ассоциативности оператора (1 — правоассоциативный)
static int is_right_associative(Token *t) { return (t->type == TOK_OPERATOR && t->str[0] == '^'); }

// Вспомогательная функция добавления токена в массив
static void tokens_push(TokenArray *arr, Token t) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->tokens = realloc(arr->tokens, sizeof(Token) * arr->capacity);
    }
    arr->tokens[arr->size++] = t;
}

// Алгоритм Дейкстры (сортировочная станция)
int shunting_yard(TokenArray *input, TokenArray *output) {
    TokenArray stack;
    stack.size = 0;
    stack.capacity = 16;
    stack.tokens = malloc(sizeof(Token) * stack.capacity);

    for (int i = 0; i < input->size; i++) {
        Token *tok = &input->tokens[i];
        switch (tok->type) {
            case TOK_NUMBER:
            case TOK_VARIABLE:
                tokens_push(output, *tok);
                break;
            case TOK_FUNCTION:
                tokens_push(&stack, *tok);
                break;
            case TOK_OPERATOR:
                while (stack.size > 0) {
                    Token *top = &stack.tokens[stack.size - 1];
                    if ((top->type == TOK_FUNCTION) ||
                        (top->type == TOK_OPERATOR &&
                         ((precedence(top) > precedence(tok)) ||
                          (precedence(top) == precedence(tok) && !is_right_associative(tok))))) {
                        tokens_push(output, *top);
                        stack.size--;
                    } else {
                        break;
                    }
                }
                tokens_push(&stack, *tok);
                break;
            case TOK_LPAREN:
                tokens_push(&stack, *tok);
                break;
            case TOK_RPAREN: {
                int found_lparen = 0;
                while (stack.size > 0) {
                    Token top = stack.tokens[stack.size - 1];
                    stack.size--;
                    if (top.type == TOK_LPAREN) {
                        found_lparen = 1;
                        break;
                    } else {
                        tokens_push(output, top);
                    }
                }
                if (!found_lparen) {
                    free(stack.tokens);
                    return -1;  // Несбалансированные скобки
                }
                if (stack.size > 0 && stack.tokens[stack.size - 1].type == TOK_FUNCTION) {
                    tokens_push(output, stack.tokens[stack.size - 1]);
                    stack.size--;
                }
                break;
            }
            default:
                free(stack.tokens);
                return -1;
        }
    }
    for (int i = stack.size - 1; i >= 0; i--) {
        if (stack.tokens[i].type == TOK_LPAREN || stack.tokens[i].type == TOK_RPAREN) {
            free(stack.tokens);
            return -1;  // Несбалансированные скобки
        }
        tokens_push(output, stack.tokens[i]);
    }
    free(stack.tokens);
    return 0;
}
