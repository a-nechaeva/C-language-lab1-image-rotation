//
// Created by user on 25.11.2023.
//

#include "bmp/bmp.h"
#include "image/image.h"

extern const char * input_state_m[];
static const uint16_t DEFAULT_BITS_PER_PIXEL = 24;

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

/*struct __attribute__((packed)) pixel {
    uint8_t b, g, r;
};
 */

struct bmp_header bmp_header_reader(FILE * input_f) {
    struct bmp_header header = {0};
    size_t count = 1;
    if (fread(&header, sizeof(struct bmp_header), count, input_f) != count) {
        header = (struct bmp_header){0};
    }
    return header;
}


enum input_state from_bmp(FILE* in, struct image* img ) {
    struct bmp_header header = bmp_header_reader(in);
    if (header.bits_per_pix != DEFAULT_BITS_PER_PIXEL) {
        return BMP_HEADER_READ_FAIL;
    }
    uint32_t orig_image_width = header.width;
    uint32_t orig_image_height = header.height;
    //uint32_t padding
    *img = create_space_for_image(orig_image_width, orig_image_height);

    for (size_t i = 0; i < orig_image_height; i++) {
        
    }



    return FILE_READ_SUCCESS;
}

