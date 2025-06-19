#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

static int compare_records(const void *a, const void *b) {
    const struct my_struct *ra = a, *rb = b;
    int fields[] = {ra->year - rb->year, ra->month - rb->month,   ra->day - rb->day,
                    ra->hour - rb->hour, ra->minute - rb->minute, ra->second - rb->second};
    for (int i = 0; i < 6; i++) {
        if (fields[i] != 0) return fields[i];
    }
    return 0;
}

static void print_record(struct my_struct r) {
    printf("%d %d %d %d %d %d %d %d\n", r.year, r.month, r.day, r.hour, r.minute, r.second, r.status, r.code);
}

static void print_file(const char *path) {
    FILE *f = fopen(path, "rb");
    int ok = 0;

    if (f) {
        int count = get_records_count_in_file(f);
        for (int i = 0; i < count; i++) {
            struct my_struct r = read_record_from_file(f, i);
            print_record(r);
            ok = 1;
        }
        fclose(f);
    }

    if (!ok) {
        printf("n/a\n");
    }
}

static void inplace_bubble_sort(const char *path) {
    FILE *f = fopen(path, "rb+");
    if (!f) {
        printf("n/a\n");
        return;
    }

    int n = get_records_count_in_file(f);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            struct my_struct a = read_record_from_file(f, j);
            struct my_struct b = read_record_from_file(f, j + 1);
            if (compare_records(&a, &b) > 0) {
                swap_records_in_file(f, j, j + 1);
            }
        }
    }

    fclose(f);
}

static void sort_and_print(const char *path) {
    inplace_bubble_sort(path);
    print_file(path);
}

static void add_and_sort(const char *path) {
    struct my_struct r;
    int input_ok = scanf("%d %d %d %d %d %d %d %d", &r.year, &r.month, &r.day, &r.hour, &r.minute, &r.second,
                         &r.status, &r.code);

    int valid = 0;
    FILE *f = NULL;

    if (input_ok == 8) {
        f = fopen(path, "ab");
        if (f) {
            fwrite(&r, sizeof(struct my_struct), 1, f);
            fclose(f);
            sort_and_print(path);
            valid = 1;
        }
    }

    if (!valid) {
        printf("n/a\n");
    }
}

static void print_menu(void) {
    printf("\nInput path to file, press 'Enter', choose an action:\n");
    printf("0. Display the file contents to the console\n");
    printf("1. Display the sorted file contents\n");
    printf("2. Add the record and display the sorted file contents\n");
    printf("Path to file: ");
}

int main() {
    char path[256];
    int option = -1;
    int valid = 0;

    print_menu();

    if (fgets(path, sizeof(path), stdin)) {
        path[strcspn(path, "\n")] = '\0';
        if (scanf("%d", &option) == 1) {
            if (option == 0) {
                print_file(path);
                valid = 1;
            } else if (option == 1) {
                sort_and_print(path);
                valid = 1;
            } else if (option == 2) {
                add_and_sort(path);
                valid = 1;
            }
        }
    }

    if (!valid) {
        printf("n/a\n");
    }

    return 0;
}