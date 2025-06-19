#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} Record;



int main() {
    char filename[100];
    int menu;
    // char buffer[256];
    char c;
    char str[1024] = "";
    char add_str[256];
    int work = 0;

    while ((scanf("%d%c", &menu, &c) == 2 && menu != -1) && c == '\n') {
        if (menu == 1) {
            if (fgets(filename, sizeof(filename), stdin) != NULL) {
                filename[strcspn(filename, "\n")] = '\0';
                work = Read_file(filename, "r", str);

            } 
        } else if (menu == 2) {
            if (fgets(add_str, sizeof(add_str), stdin) != NULL) {
                add_str[strcspn(add_str, "\n")] = '\0';

                if (work == 1) {
                    Write_file(filename, "a", add_str);
                    Read_file(filename, "r", str);
                } else {
                    strcat(str, "n/a");
                }

            }

        }
    }
    printf("%s", str);
}
