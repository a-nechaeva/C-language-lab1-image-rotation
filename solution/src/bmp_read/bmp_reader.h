//
// Created by user on 27.10.2023.
//
#include <stdint.h>
#include "image/image.h"

#ifndef IMAGE_TRANSFORMER_BMP_READER_H
#define IMAGE_TRANSFORMER_BMP_READER_H

// устанавливаем выравнивание в 1 байт, чтобы можно было нормально читать данные из файла
//#pragma pack(push, 1)

typedef struct  __attribute__((packed)) bmp_header {
    uint16_t bfile_type;
    uint32_t bfile_size;
    uint32_t reserved;
    uint32_t bf_off_bits;
    uint32_t bi_size;
    uint32_t bi_width;
    uint32_t bi_height;
    uint16_t bi_planes;
    uint16_t bi_bit_count;
    uint32_t bi_compression;
    uint32_t bi_size_image;
    uint32_t bi_x_pixels_per_meter;
    uint32_t bi_y_pixels_per_meter;
    uint32_t bi_colors_used;
    uint32_t bi_important_colors;
} bmp_header;

// функция, загружающая все в память
typedef struct bmp_file {
    bmp_header bmp_h;
    unsigned char* data; // т к заранее неизвестен размер, то задаем указатель
} bmp_file;

bmp_file * load_bmp_file(char * file_name);
void free_bmp_file(bmp_file * bmp_file);
//#pragma pop

uint32_t padding_size(uint32_t image_byte_width);

/*  deserializer   */
enum read_status {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
};

enum read_status from_bmp(FILE * in, struct image * img);

/*  serializer   */
enum write_status {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum write_status to_bmp(FILE * out, struct image const * img);

#endif //IMAGE_TRANSFORMER_BMP_READER_H
