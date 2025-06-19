#include "file_utils.h"

#include <stdio.h>

struct my_struct read_record_from_file(FILE *pfile, int index) {
    struct my_struct record = {0};
    if (!pfile || index < 0) return record;

    int offset = index * (int)sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    fread(&record, sizeof(struct my_struct), 1, pfile);
    rewind(pfile);

    return record;
}

static void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    if (!pfile || !record_to_write || index < 0) return;

    int offset = index * (int)sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    if (!pfile || record_index1 < 0 || record_index2 < 0) return;

    struct my_struct r1 = read_record_from_file(pfile, record_index1);
    struct my_struct r2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &r1, record_index2);
    write_record_in_file(pfile, &r2, record_index1);
}

static int get_file_size_in_bytes(FILE *pfile) {
    if (!pfile) return 0;

    fseek(pfile, 0, SEEK_END);
    int size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) {
    int size = get_file_size_in_bytes(pfile);
    return size / (int)sizeof(struct my_struct);
}