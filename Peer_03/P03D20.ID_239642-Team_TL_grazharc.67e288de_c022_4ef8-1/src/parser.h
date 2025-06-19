#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Преобразование массива токенов из инфиксной формы в обратную польскую нотацию (ОПН)
// Возвращает 0 при успехе, -1 при ошибке
int shunting_yard(TokenArray *input, TokenArray *output);

#endif
