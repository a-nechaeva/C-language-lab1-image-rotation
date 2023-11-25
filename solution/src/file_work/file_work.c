//
// Created by user on 25.11.2023.
//
#include "stdio.h"
#include "file_work/file_work.h"

char * args_state[] = {
   [NOT_ENOUGH_ARGS] = "Недостаточное число аргументов, введите 2 аргумента!",
   [TOO_MANY_ARGS] = "Слишком много аргументов, введите 2 аргумента!",
   [CORRECT_NUMBER_ARGS] = "Введено корректное число аргументов ^..%"
};

char * input_state[] = {
    [INPUT_FILE_OPEN_FAIL] = "Не удается открыть файл для чтения :(",
    [INPUT_FILE_READ_FAIL] = "Ошибка при чтении файла :(",
    [FILE_READ_SUCCESS] = "Файл прочитан! ^..^",
    [INPUT_FILE_CLOSE_FAIL] = "Не удается закрыть прочитанный файл :("
};

char * output_state[] = {
    [OUTPUT_FILE_OPEN_FAIL] = "Не удается открыть файл для записи :(",
    [OUTPUT_FILE_WRITE_FAIL] = "Ошибка записи данных в файл :(",
    [FILE_WRITE_SUCCESS] = "Запись в файл прошла успешно! ^..^",
    [OUTPUT_FILE_CLOSE_FAIL] = "Не удается закрыть файл с записанными данными :(",
};

void print_success(char * m) {
    fprintf(stdout, "%s", m);
}

void print_fail(char * e) {
    fprintf(stderr, "%s", e);
}
