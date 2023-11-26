//
// Created by user on 25.11.2023.
//
#include "stdio.h"
#include "file_work/file_work.h"

const char * args_state_m[] = {
   [NOT_ENOUGH_ARGS] = "Not enough args, enter 2 args!",
   [TOO_MANY_ARGS] = "Too many args, enter 2 args!"
};

const char * input_state_m[] = {
    [INPUT_FILE_OPEN_FAIL] = "Can't open file for reading :(",
    [INPUT_FILE_READ_FAIL] = "Error during reading file :(",
    [FILE_READ_SUCCESS] = "File has read! ^..^",
    [INPUT_FILE_CLOSE_FAIL] = "Can't close input file :(",
    [BMP_HEADER_READ_FAIL] = "Can't read header of BMP :(",
    [BMP_IMAGE_READ_SUCCESS] = "Reading image data is success!",
    [BMP_IMAGE_READ_FAIL] = "Can't read image data :("
};

const char * output_state_m[] = {
    [OUTPUT_FILE_OPEN_FAIL] = "Не удается открыть файл для записи :(",
    [OUTPUT_FILE_WRITE_FAIL] = "Ошибка записи данных в файл :(",
    [FILE_WRITE_SUCCESS] = "Запись в файл прошла успешно! ^..^",
    [OUTPUT_FILE_CLOSE_FAIL] = "Не удается закрыть файл с записанными данными :(",
    [BMP_HEADER_WRITE_FAIL] = "Ошибка при записи заголовка BMP файла :(",
    [BMP_IMAGE_WRITE_FAIL] = "Ошибка при записи данных картинки в BMP файл"
};

const char * transform_state_m[] = {
    [ROTATION_FAIL] = "Возникла ошибка при повороте картинки :(",
    [ROTATION_SUCCESS] = "Поворот картинки осуществлен успешно! ^. .^ "
};

void print_success(const char * m) {
    fprintf(stdout, "%s", m);
}

void print_fail(const char * e) {
    fprintf(stderr, "%s", e);
}
