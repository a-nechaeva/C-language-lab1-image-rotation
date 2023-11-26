#include "stdio.h"
#include "file_work/file_work.h"

const char * args_state_m[] = {
   [NOT_ENOUGH_ARGS] = "Not enough args, enter 2 args!",
   [TOO_MANY_ARGS] = "Too many args, enter 2 args!"
};

const char * input_state_m[] = {
    [INPUT_FILE_OPEN_FAIL] = "Can't open file for reading :(",
    [INPUT_FILE_READ_FAIL] = "Error during reading file :(",
    [FILE_READ_SUCCESS] = "File has read! ^..%",
    [INPUT_FILE_CLOSE_FAIL] = "Can't close input file :(",
    [BMP_HEADER_READ_FAIL] = "Can't read header of BMP :(",
    [BMP_IMAGE_READ_SUCCESS] = "Reading image data is success!",
    [BMP_IMAGE_READ_FAIL] = "Can't read image data :("
};

const char * output_state_m[] = {
    [OUTPUT_FILE_OPEN_FAIL] = "Can´t open file for writing :(",
    [OUTPUT_FILE_WRITE_FAIL] = "Error during writing file :(",
    [FILE_WRITE_SUCCESS] = "File has written! ^..%",
    [OUTPUT_FILE_CLOSE_FAIL] = "Can't close output file :(",
    [BMP_HEADER_WRITE_FAIL] = "Can't write header of BMP :(",
    [BMP_IMAGE_WRITE_FAIL] = "Can't write BMP data :("
};

const char * transform_state_m[] = {
    [ROTATION_FAIL] = "Error during rotation :(",
    [ROTATION_SUCCESS] = "Rotation is success! ^..% "
};

void print_success(const char * m) {
    fprintf(stdout, "%s", m);
}

void print_fail(const char * e) {
    fprintf(stderr, "%s", e);
}
