//
// Created by user on 27.10.2023.
//

#include <malloc.h>
#include "image/image.h"

struct image create_space_for_image(uint64_t width, uint64_t height) {
    return (struct image){.width = width, .height = height, .pixels = malloc(sizeof(struct pixel) * width * height)};
}
