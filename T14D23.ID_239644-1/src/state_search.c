#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

int parse_date(const char *s, int *d, int *m, int *y) { return sscanf(s, "%d.%d.%d", d, m, y) == 3; }

static void search_by_date(const char *path, int d, int m, int y) {
    FILE *f = fopen(path, "rb");
    int found = 0;

    if (f) {
        int count = get_records_count_in_file(f);
        for (int i = 0; i < count; i++) {
            struct my_struct rec = read_record_from_file(f, i);
            if (rec.day == d && rec.month == m && rec.year == y) {
                printf("%d\n", rec.code);
                found = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!found) {
        printf("n/a\n");
    }
}

int main() {
    char path[256], date[20];
    int d, m, y;
    int valid = 0;

    if (fgets(path, sizeof(path), stdin) && fgets(date, sizeof(date), stdin) &&
        parse_date(date, &d, &m, &y)) {
        path[strcspn(path, "\n")] = '\0';

        search_by_date(path, d, m, y);
        valid = 1;
    }

    if (!valid) {
        printf("n/a\n");
    }

    return 0;
}