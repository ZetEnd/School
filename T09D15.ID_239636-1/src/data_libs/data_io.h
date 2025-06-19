#ifndef DATA_IO_H
#define DATA_IO_H

void input(double *data, int n);
void output(double *data, int n);

void locmemory(double **data, int n);
void freememory(double *data);

void sort(double *data, int first, int last);

#endif
