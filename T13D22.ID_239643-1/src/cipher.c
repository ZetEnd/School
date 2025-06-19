#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

int Read_file(char filename[100], char* flag, char* str) {
    char buffer[256];
    int flag_reader = 0;

    FILE* fp = fopen(filename, flag);

    if (fp) {
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0) {
            strcat(str, "n/a");
            // fclose(fp);
            // return 0;
        }

        fseek(fp, 0, SEEK_SET);  // Возвращаем указатель в начало файла

        while ((fgets(buffer, 256, fp)) != NULL) {
            char* pos;
            while ((pos = strstr(buffer, "\\n")) != NULL) {
                *pos = '\n';
                memmove(pos + 1, pos + 2, strlen(pos + 2) + 1);
            }

            if (strlen(str) + strlen(buffer) < MAX_STR_LEN) {
                strcat(str, buffer);
            }
        }
        strcat(str, "\n");
        fclose(fp);
        flag_reader = 1;
    } else {
        // printf("n/a");
        filename = NULL;
        if (strlen(str) + strlen("n/a") < MAX_STR_LEN) {
            strcat(str, "n/a");
            strcat(str, "\n");
        }
    }

    return flag_reader;
}

void Write_file(char filename[100], char* flag, char* add_str) {
    int len = strlen(add_str);

    FILE* fp = fopen(filename, flag);

    if (fp) {
        // putc('\n', fp);
        for (int i = 0; i < len; i++) {
            putc(add_str[i], fp);
        }
        // putc('\n', fp);
    }
    fclose(fp);
}
/*
void Clear_h(char* filename) {
    printf("sw");
    FILE* fp = fopen(filename, "w");

    fclose(fp);
}*/
/*
void caesar_cipher_file(const char *filename, int shift);
void process_directory(const char *dirname, int shift) {

    DIR *dir;
    struct dirent *entry;
    char path[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

            char *ext = strrchr(entry->d_name, '.');
            if (ext != NULL) {
                if (strcmp(ext, ".c") == 0) {
                    // Encrypt .c files with Caesar cipher
                    caesar_cipher_file(path, shift);

                } else if (strcmp(ext, ".h") == 0) {
                    // Clear .h files
                    Clear_h(path);

                }
            }
        }
    }
    closedir(dir);
}



void caesar_cipher_file(const char *filename, int shift) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("fopen");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(size + 1);
    fread(content, 1, size, file);
    content[size] = '\0';

    for (long i = 0; i < size; i++) {
        if (isalpha(content[i])) {
            char base = isupper(content[i]) ? 'A' : 'a';
            content[i] = (content[i] - base + shift) % 26;
            if (content[i] < 0) content[i] += 26;
            content[i] += base;
        }
    }

    fseek(file, 0, SEEK_SET);
    fwrite(content, 1, size, file);
    fclose(file);
    free(content);
}
*/

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

            } else {
                // printf("n/a");
                if (strlen(str) + strlen("n/a") < MAX_STR_LEN) {
                    strcat(str, "n/a");
                    strcat(str, "\n");
                }
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

            } else if (menu == 3) {
                // char direct[100] = "/ai_modules";
                // int shift;

                // shift = 1;

                // process_directory(direct, shift);

            }

            else {
                // printf("n/a");
                if (strlen(str) + strlen("n/a") < MAX_STR_LEN) {
                    strcat(str, "n/a");
                    strcat(str, "\n");
                }
            }
        }
    }
    printf("%s", str);
}
