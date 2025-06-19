#include <stdio.h>

void read_file(const char* filename); 

int main() {
    const char *filename = "filename.txt";
    read_file(filename);
    return 0;
}

void read_file(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    char myString[100];
    if (fptr != NULL) {
        while(fgets(myString, 100, fptr)) {
            printf("%s", myString);
        }
    } else {
    printf ("n/a");
    }
  fclose(fptr);
}
