#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

int parse_date(const char *s, int *day, int *month, int *year) {
    return sscanf(s, "%d.%d.%d", day, month, year) == 3;
}

static int date_compare(const struct my_struct *r, int day, int month, int year) {
    if (r->year != year) return r->year - year;
    if (r->month != month) return r->month - month;
    return r->day - day;
}

static int is_in_range(const struct my_struct *r, int d1, int m1, int y1, int d2, int m2, int y2) {
    int from_cmp = date_compare(r, d1, m1, y1);
    int to_cmp = date_compare(r, d2, m2, y2);
    return from_cmp >= 0 && to_cmp <= 0;
}

static int read_input(char *path, char *range) {
    if (!fgets(path, 256, stdin) || !fgets(range, 64, stdin)) return 0;
    path[strcspn(path, "\n")] = 0;
    range[strcspn(range, "\n")] = 0;
    return 1;
}

static int parse_range(const char *range, int *d1, int *m1, int *y1, int *d2, int *m2, int *y2) {
    return sscanf(range, "%d.%d.%d %d.%d.%d", d1, m1, y1, d2, m2, y2) == 6;
}

static int process_file(const char *path, int d1, int m1, int y1, int d2, int m2, int y2) {
    FILE *in = fopen(path, "rb");
    if (!in) return 0;

    FILE *out = fopen("temp.tmp", "wb");
    if (!out) {
        fclose(in);
        return 0;
    }

    struct my_struct record;
    int count = get_records_count_in_file(in);
    for (int i = 0; i < count; i++) {
        record = read_record_from_file(in, i);
        if (!is_in_range(&record, d1, m1, y1, d2, m2, y2)) {
            fwrite(&record, sizeof(record), 1, out);
        }
    }

    fclose(in);
    fclose(out);

    if (remove(path) != 0 || rename("temp.tmp", path) != 0) {
        return 0;
    }

    FILE *f = fopen(path, "rb");
    if (!f) return 0;

    while (fread(&record, sizeof(record), 1, f) == 1) {
        printf("%d %d %d %d %d %d %d %d\n", record.year, record.month, record.day, record.hour, record.minute,
               record.second, record.status, record.code);
    }

    fclose(f);
    return 1;
}

int main() {
    char path[256];
    char range[64];
    int d1, m1, y1, d2, m2, y2;
    int ok = 0;

    if (read_input(path, range) && parse_range(range, &d1, &m1, &y1, &d2, &m2, &y2)) {
        ok = process_file(path, d1, m1, y1, d2, m2, y2);
    }

    if (!ok) {
        printf("n/a\n");
    }

    return 0;
}