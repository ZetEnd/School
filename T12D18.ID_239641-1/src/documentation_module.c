#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
/*
    input: validation callback, documents count, args with documents names (max 16)
    output: binary mask of documents availability
*/
int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    // const char* docs = {Documents, NULL};
    int bin_mas[document_count];
    for(int i = 0; i < document_count; i++){

        bin_mas[i] = validate(document_data[i]);
    }

    /*
        init
        arr
        while
            arr++
    
    */

    return bin_mas;
}