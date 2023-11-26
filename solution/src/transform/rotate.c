#include <malloc.h>
#include "transform/rotate.h"
#include "file_work/file_work.h"
#include "image/image.h"

enum transform_state rotation(struct image input_image, struct image * rotate_image) {
    uint64_t width = input_image.width;
    uint64_t height = input_image.height;

    rotate_image->width = height;
    rotate_image->height = width;
    rotate_image ->pixels = malloc(sizeof(struct pixel) * width * height);

    for (uint64_t i = 0; i < height; ++i) {
        for (uint64_t j = 0; j < width; ++j) {
            rotate_image->pixels[height * (j + 1) - (i + 1)] = input_image.pixels[j + width * i];
        }
    }

    return ROTATION_SUCCESS;
}

