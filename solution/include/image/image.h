//
// Created by user on 27.10.2023.
//
#include <stdio.h>
#include <stdint.h>

#ifndef IMAGE_TRANSFORMER_IMAGE_H
#define IMAGE_TRANSFORMER_IMAGE_H

struct image {
    uint64_t width, height;
    struct pixel * pixels;
};

struct pixel {
    uint8_t b, g, r;
};

#endif //IMAGE_TRANSFORMER_IMAGE_H
