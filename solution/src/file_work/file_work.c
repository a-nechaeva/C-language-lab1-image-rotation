//
// Created by user on 25.11.2023.
//
#include "stdio.h"
#include "file_work/file_work.h"

const char * args_state_m[] = {
   [NOT_ENOUGH_ARGS] = "Недостаточное число аргументов, введите 2 аргумента!",
   [TOO_MANY_ARGS] = "Слишком много аргументов, введите 2 аргумента!"
};

const char * input_state_m[] = {
    [INPUT_FILE_OPEN_FAIL] = "Не удается открыть файл для чтения :(",
    [INPUT_FILE_READ_FAIL] = "Ошибка при чтении файла :(",
    [FILE_READ_SUCCESS] = "Файл прочитан! ^..^",
    [INPUT_FILE_CLOSE_FAIL] = "Не удается закрыть прочитанный файл :(",
    [BMP_HEADER_READ_FAIL] = "Не удается прочитать заголовок BMP файла :(",
    [BMP_IMAGE_READ_SUCCESS] = "Успешное чтение данных картинки!",
    [BMP_IMAGE_READ_FAIL] = "Не получилось считать данные картинки :("
};

const char * output_state_m[] = {
    [OUTPUT_FILE_OPEN_FAIL] = "Не удается открыть файл для записи :(",
    [OUTPUT_FILE_WRITE_FAIL] = "Ошибка записи данных в файл :(",
    [FILE_WRITE_SUCCESS] = "Запись в файл прошла успешно! ^..^",
    [OUTPUT_FILE_CLOSE_FAIL] = "Не удается закрыть файл с записанными данными :(",
};

void print_success(const char * m) {
    fprintf(stdout, "%s", m);
}

void print_fail(const char * e) {
    fprintf(stderr, "%s", e);
}
