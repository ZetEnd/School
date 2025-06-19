#include "print_module.h"

#include <stdio.h>
#include <time.h>

/*
    input:  printchar-callback, log message
    output: void
    result: "Log_prefix HH:MM:SS message"
*/

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t mytime = time(NULL);
    struct tm* now = localtime(&mytime);
    // printf(" %d.%d.%d\n", Log_prefix, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    printf("%s %d:%d:%d\n", Log_prefix, now->tm_hour, now->tm_min, now->tm_sec);

    for (int i = 0; message[i] != '\0'; i++) {
        print(message[i]);
    }
}