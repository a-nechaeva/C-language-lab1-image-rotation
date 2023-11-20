#include <stdio.h>
#include <stdlib.h>
#include "image/image.h"

int main( int argc, char** argv ) {
    // проверяем количество аргументов командной строки
    if (argc != 3) {
        fprintf(stderr, "Wrong number of arguments!");
        return -1;
    }
    // выделяем место под файл???
    FILE * input_file = malloc(sizeof(FILE *));
    // пытаемся открыть файл на чтение
    if ((input_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open file for read!");
        return -1;
    }

    FILE * output_file = malloc(sizeof (FILE *));
    // пытаемся открыть второй файл на запись
    if ((output_file = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Can't open file for write!");
        return -1;
    }

    struct image input_image = {0};


    
    fclose(input_file);
    fclose(output_file);
    return 0;
}
