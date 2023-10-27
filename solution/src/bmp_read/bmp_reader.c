//
// Created by user on 27.10.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "bmp_reader.h"

#ifndef IMAGE_TRANSFORMER_BMP_READER_C
#define IMAGE_TRANSFORMER_BMP_READER_C

uint32_t padding_size(uint32_t image_byte_width){
    uint32_t padding = image_byte_width % 4;
    return padding;
}

bmp_file * load_bmp_file(char * file_name){
    FILE * file = fopen(file_name, "r");

    if (file) {
        bmp_file * b_file = (bmp_file *) malloc(sizeof(bmp_file));
        fread(&b_file->bmp_h, sizeof(bmp_header), 1, file);

        b_file->data = (unsigned char *) malloc(b_file->bmp_h.bi_size_image);

    }
}

void free_bmp_file(bmp_file * bmp_file) {

}


#endif
