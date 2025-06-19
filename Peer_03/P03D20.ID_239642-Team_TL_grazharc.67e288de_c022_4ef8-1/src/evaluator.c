// вычисление выражения по ОПН с подстановкой x
#include "evaluator.h"

#include <math.h>
#include <string.h>

double eval_expression(TokenArray *rpn, double x, int *error) {
    double stack[256];
    int sp = 0;
    *error = 0;

    for (int i = 0; i < rpn->size; i++) {
        Token *tok = &rpn->tokens[i];
        if (tok->type == TOK_NUMBER) {
            if (sp >= 256) {
                *error = 1;
                return 0;
            }
            stack[sp++] = tok->value; // (*tok).val tok->val
        } else if (tok->type == TOK_VARIABLE) {
            if (sp >= 256) {
                *error = 1;
                return 0;
            }
            stack[sp++] = x;
        } else if (tok->type == TOK_OPERATOR) {
            if (sp < 2) {
                *error = 1;
                return 0;
            }
            double b = stack[--sp];
            double a = stack[--sp];
            double res = 0;
            switch (tok->str[0]) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        *error = 1;
                        return 0;
                    }
                    res = a / b;
                    break;
                case '^':
                    res = pow(a, b);
                    break;
                default:
                    *error = 1;
                    return 0;
            }
            stack[sp++] = res;
        } else if (tok->type == TOK_FUNCTION) {
            if (sp < 1) {
                *error = 1;
                return 0;
            }
            double val = stack[--sp];
            double res = 0;
            if (strcmp(tok->str, "sin") == 0)
                res = sin(val);
            else if (strcmp(tok->str, "cos") == 0)
                res = cos(val);
            else if (strcmp(tok->str, "tan") == 0)
                res = tan(val);
            else if (strcmp(tok->str, "exp") == 0)
                res = exp(val);
            else if (strcmp(tok->str, "ctg") == 0) {
            if (tan(val) == 0) {
                    *error = 1;
                    return 0;
                }
                res = 1/tan(val);
            } else if (strcmp(tok->str, "ln") == 0) {
                if (val <= 0) {
                    *error = 1;
                    return 0;
                }
                res = log(val);
            } else if (strcmp(tok->str, "sqrt") == 0) {
                if (val < 0) {
                    *error = 1;
                    return 0;
                }
                res = sqrt(val);
            } else if (strcmp(tok->str, "abs") == 0)
                res = fabs(val);
            else {
                *error = 1;
                return 0;
            }
            stack[sp++] = res;
        } else {
            *error = 1;
            return 0;
        }
    }
    if (sp != 1) {
        *error = 1;
        return 0;
    }
    return stack[0];
}
