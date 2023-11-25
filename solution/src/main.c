#include <stdio.h>
#include <stdlib.h>
#include "image/image.h"
#include "file_work/file_work.h"
#include "bmp/bmp.h"

extern const char * args_state_m[];
extern const char * input_state_m[];
extern const char * output_state_m[];
extern const char * transform_state_m[];

int main( int argc, char** argv ) {

    if (argc > 3) {
        print_fail(args_state_m[TOO_MANY_ARGS]);
        return -1;
    }
    if (argc < 3) {
        print_fail(args_state_m[NOT_ENOUGH_ARGS]);
        return -1;
    }

    char * input_file_name = argv[1];
    char * output_file_name = argv[2];

    FILE * input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        print_fail(input_state_m[INPUT_FILE_OPEN_FAIL]);
        return -1;
    }

    struct image input_image = {0};

    // здесь процесс чтения из файла и сохранения данных в структуре
    enum input_state read_and_create_image = from_bmp_to_image(input_file, &input_image);

    if (read_and_create_image == FILE_READ_SUCCESS) {
        print_success(input_state_m[FILE_READ_SUCCESS]);
        //здесь вызов функции поворота картинки
        struct image * rotate_image = malloc(sizeof(struct image));
        enum transform_state state_of_rotation = rotation(input_image, rotate_image);
        if (state_of_rotation != ROTATION_SUCCESS) {
            print_fail(transform_state_m[state_of_rotation]);
        }
    } else {
        print_fail(input_state_m[read_and_create_image]);
        return 1;
    }


    if (fclose(input_file) == -1) {
        print_fail(input_state_m[INPUT_FILE_CLOSE_FAIL]);
        return -1;
    }

    FILE * output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        print_fail(output_state_m[OUTPUT_FILE_OPEN_FAIL]);
        return -1;
    }
    // здесь процесс записи в файл

    print_success(output_state_m[FILE_WRITE_SUCCESS]);

    if (fclose(output_file) == -1) {
        print_fail(output_state_m[OUTPUT_FILE_CLOSE_FAIL]);
        return -1;
    }

    return 0;
}
