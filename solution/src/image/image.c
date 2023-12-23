#include "image/image.h"
#include <stdlib.h>

struct image create_space_for_image(uint64_t width, uint64_t height) {
    struct image  created_image_space;
    created_image_space.width = width;
    created_image_space.height = height;
    created_image_space.pixels = malloc(sizeof(struct pixel) * width * height);
    if (created_image_space.pixels == NULL) {
        return (struct image){.width = -100};
    }
    return created_image_space;
}

void free_image(struct image * image){
    if (image -> width > 0) {
        free(image->pixels);
    }
}

