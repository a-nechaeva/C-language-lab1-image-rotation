#include "image/image.h"
#include "bmp/bmp.h"
#include "file_work/file_work.h"
#include "transform/rotate.h"
#include <stdio.h>

extern const char * args_state_m[];
extern const char * input_state_m[];
extern const char * output_state_m[];
extern const char * transform_state_m[];

int main( int argc, char** argv ) {
    // проверяем, что получено корректное число аргументов
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
    // открываем на чтение файл с исходной картинкой
    FILE * input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        print_fail(input_state_m[INPUT_FILE_OPEN_FAIL]);
        return -1;
    }
    //создаем "пустую" структуру под исходную картинку
    struct image input_image = {0};
    // читаем информацию из полученного файла и заполняем input_image
    enum input_state read_and_create_image = from_bmp_to_image(input_file, &input_image);

    if (read_and_create_image == FILE_READ_SUCCESS) {
        print_success(input_state_m[FILE_READ_SUCCESS]);

    } else {
        print_fail(input_state_m[read_and_create_image]);
        return -1;
    }
    // создаем "пустую" структуру под повернутую картинку
    struct image rotate_image = {0};
    //операция поворота на 90 градусов
    enum transform_state state_of_rotation = rotation(input_image, &rotate_image);
    if (state_of_rotation != ROTATION_SUCCESS) {
        print_fail(transform_state_m[state_of_rotation]);
        return 1;
    }

    free_image(&input_image);

    if (fclose(input_file) == -1) {
        print_fail(input_state_m[INPUT_FILE_CLOSE_FAIL]);
        return -1;
    }

    FILE * output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        print_fail(output_state_m[OUTPUT_FILE_OPEN_FAIL]);
        return -1;
    }
    // упаковка полученной повернутой картинки в BMP файл
    enum output_state write_and_save_st = from_image_to_bmp(output_file, &rotate_image);

    free_image(&rotate_image);

    if (write_and_save_st != FILE_WRITE_SUCCESS) {
        print_fail(output_state_m[write_and_save_st]);
        return -1;
    }
    print_success(output_state_m[FILE_WRITE_SUCCESS]);

    if (fclose(output_file) == -1) {
        print_fail(output_state_m[OUTPUT_FILE_CLOSE_FAIL]);
        return -1;
    }

    return 0;
}
