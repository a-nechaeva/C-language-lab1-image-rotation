//
// Created by user on 25.11.2023.
//

#include "bmp/bmp.h"

struct  __attribute__((packed)) bmp_header {
    uint16_t file_type;
    uint32_t file_size;
    uint32_t reserved;
    uint32_t start_data;
    uint32_t size_of_header;
    uint32_t width;
    uint32_t height;
    uint16_t color_planes;
    uint16_t bits_per_pix;
    uint32_t compression;
    uint32_t size__of_image;
    uint32_t x_pixels_per_meter;
    uint32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t important_colors;
};

struct __attribute__((packed)) pixel {
    uint8_t b, g, r;
};
