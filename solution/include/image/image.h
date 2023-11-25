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
struct image create_space_for_image(uint64_t width, uint64_t height);



#endif //IMAGE_TRANSFORMER_IMAGE_H
