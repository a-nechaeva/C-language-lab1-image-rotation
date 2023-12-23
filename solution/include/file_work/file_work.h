#ifndef IMAGE_TRANSFORMER_FILE_WORK_H
#define IMAGE_TRANSFORMER_FILE_WORK_H

enum input_arg_state {
    NOT_ENOUGH_ARGS,
    TOO_MANY_ARGS
};

enum input_state {
    INPUT_FILE_OPEN_FAIL,
    INPUT_FILE_READ_FAIL,
    FILE_READ_SUCCESS,
    INPUT_FILE_CLOSE_FAIL,
    BMP_HEADER_READ_FAIL,
    BMP_IMAGE_READ_FAIL,
    MEM_FAIL,
    BMP_IMAGE_READ_SUCCESS
};

enum output_state {
    OUTPUT_FILE_OPEN_FAIL,
    OUTPUT_FILE_WRITE_FAIL,
    FILE_WRITE_SUCCESS,
    OUTPUT_FILE_CLOSE_FAIL,
    BMP_HEADER_WRITE_FAIL,
    BMP_IMAGE_WRITE_FAIL
};

enum transform_state {
    ROTATION_FAIL,
    ROTATION_SUCCESS
};

void print_success(const char * m);

void print_fail(const char * e);


#endif
