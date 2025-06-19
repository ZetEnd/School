#include "s21_string.h"

int s21_strlen(char *str) {
    int len = 0;

    char ch = str[0];

    while (ch != '\0') {
        len++;
        ch = str[len];
    }

    return len;
}

int s21_strcmp(char *str1, char *str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void s21_strcpy(char *dest, const char *src) {
    // char* ptr = dest;
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    // return dest;
}

char *s21_strcat(char *dest, const char *src) {
    char *ptr = dest + s21_strlen(dest);  // Находим конец dest
    while (*src != '\0') {
        *ptr++ = *src++;  // Копируем src в конец dest
    }
    *ptr = '\0';  // Добавляем завершающий нуль-терминатор
    return dest;
}
