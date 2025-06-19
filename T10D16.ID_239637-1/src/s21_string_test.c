#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test(char *str, int n) {
    int len = s21_strlen(str);

    printf("%s\n", str);
    printf("%d\n", len);
    printf("%s\n", (len == n) ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test(char *str1, char *str2, int n) {
    int res = s21_strcmp(str1, str2);

    printf("\"%s\" vs \"%s\"\n", str1, str2);
    printf("%d\n", res);
    printf("%s\n", (res == n) ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test(char *src, char *expected) {
    char dest[256] = {0};  // Буфер с запасом
    s21_strcpy(dest, src);
    printf("\"%s\"\n", src);
    printf("\"%s\"\n", dest);
    printf("\"%s\"\n", expected);
    printf("%s\n", (s21_strcmp(dest, expected) == 0) ? "SUCCESS" : "FAIL");
}

void s21_strcat_test(char *dest_init, char *src, char *expected) {
    char dest[256];               // Буфер с запасом
    s21_strcpy(dest, dest_init);  // Инициализируем dest
    s21_strcat(dest, src);        // Вызываем тестируемую функцию

    printf("\"%s\" + \"%s\"\n", dest_init, src);
    printf("\"%s\"\n", dest);
    printf("\"%s\"\n", expected);
    printf("%s\n", (s21_strcmp(dest, expected) == 0) ? "SUCCESS" : "FAIL");
}

int main() {
    s21_strlen_test("313123", 6);
    s21_strlen_test("", 0);
    s21_strlen_test(" ", 1);
    s21_strlen_test(" s ", 3);
    s21_strlen_test("s  hello", 8);

    s21_strcmp_test("abc", "abc", 0);
    s21_strcmp_test("abc", "abd", -1);
    s21_strcmp_test("xyz", "xy", 1);
    // Краевые случаи
    s21_strcmp_test("", "", 0);
    s21_strcmp_test("a", "", 1);
    s21_strcmp_test("", "a", -1);
    // Спецсимволы
    s21_strcmp_test("\n", "\t", 1);

    s21_strcpy_test("Hello", "Hello");
    s21_strcpy_test("", "");
    // Краевые значения
    s21_strcpy_test("A\0B", "A");
    s21_strcpy_test("12345", "12345");
    // Спецсимволы
    s21_strcpy_test("\n\t", "\n\t");

    s21_strcat_test("Hello", " World", "Hello World");
    s21_strcat_test("Start", "", "Start");
    s21_strcat_test("", "End", "End");
    // Краевые значения
    s21_strcat_test("A", "\0B", "A");
    s21_strcat_test("1", "2", "12");
    // Спецсимволы
    s21_strcat_test("Line", "\nBreak", "Line\nBreak");
}