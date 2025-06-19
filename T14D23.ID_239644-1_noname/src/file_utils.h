#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>

struct my_struct {
    int year, month, day;
    int hour, minute, second;
    int status;
    int code;
};

struct my_struct read_record_from_file(FILE *pfile, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_records_count_in_file(FILE *pfile);

#endif