#include <stdio.h>
#include <stdlib.h>
#include "image/image.h"
#include "file_work/file_work.h"

extern const char * args_state[];
extern const char * input_state[];
extern const char * output_state[];

int main( int argc, char** argv ) {

    if (argc > 3) {
        print_fail(args_state[TOO_MANY_ARGS]);
        return -1;
    }
    if (argc < 3) {
        print_fail(args_state[NOT_ENOUGH_ARGS]);
        return -1;
    }

    char * input_file_name = argv[1];
    char * output_file_name = argv[2];

    FILE * input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        print_fail(input_state[INPUT_FILE_OPEN_FAIL]);
        return -1;
    }

    struct image input_image = {0};
    // здесь процесс чтения из файла и сохранения данных в структуре

    if (fclose(input_file) == -1) {
        print_fail(input_state[INPUT_FILE_CLOSE_FAIL]);
        return -1;
    }

    FILE * output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        print_fail(output_state[OUTPUT_FILE_OPEN_FAIL]);
        return -1;
    }
    // здесь процесс записи в файл

    if (fclose(output_file) == -1) {
        print_fail(output_state[OUTPUT_FILE_CLOSE_FAIL]);
        return -1;
    }
    
    return 0;
}
