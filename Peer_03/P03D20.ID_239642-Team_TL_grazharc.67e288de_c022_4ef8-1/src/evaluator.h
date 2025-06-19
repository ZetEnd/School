#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "lexer.h"

// Вычисление выражения в ОПН с подстановкой x
// error = 0 при успехе, 1 при ошибке
double eval_expression(TokenArray *rpn, double x, int *error);

#endif
