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

static uint32_t get_padding(uint32_t width) {
   // return width % 4;
    return (4 - width * 3 % 4) == 0 ? 0 : 4 - width * 3 % 4;
}
//ЗДЕСЬ ВЫПАДАЕТ ОШИБКА! ПРОШЛА после смены r на rb
enum input_state bmp_image_data_reader(FILE * input_f, struct image * imag) {
    uint64_t width = imag -> width;
    for (size_t i = 0; i < imag -> height; i++) {
        // здесь почему-то меньше
        if ((fread(&imag -> pixels[i * width], sizeof(struct pixel), width, input_f) != width)
                || (fseek(input_f, get_padding(width), SEEK_CUR) != 0)) {
            return BMP_IMAGE_READ_FAIL;
        }
    }
    return FILE_READ_SUCCESS;
}


enum input_state from_bmp_to_image(FILE* in, struct image* img ) {
    struct bmp_header header = bmp_header_reader(in);
    if (header.bits_per_pix != DEFAULT_BITS_PER_PIXEL) {
        return BMP_HEADER_READ_FAIL;
    }
    uint32_t orig_image_width = header.width;
    uint32_t orig_image_height = header.height;
    *img = create_space_for_image(orig_image_width, orig_image_height);

    enum input_state state_read = bmp_image_data_reader(in, img);
    if ( state_read != FILE_READ_SUCCESS) {
        return state_read;
    }

    return FILE_READ_SUCCESS;
}

static struct bmp_header generate_header(uint32_t width, uint32_t height) {

    return (struct bmp_header) {
            .file_type = 0x4d42,
            .file_size = sizeof(struct bmp_header) + sizeof(struct pixel) *
                                                     height * (width + get_padding(width)),
            .reserved = 0,
            .start_data = sizeof(struct bmp_header),
            .size_of_header = 40,
            .width = width,
            .height = height,
            .color_planes = 1,
            .bits_per_pix = 24,
            .compression = 0,
            .size__of_image = 0,
            .x_pixels_per_meter = 0,
            .y_pixels_per_meter = 0,
            .colors_used = 0,
            .important_colors = 0
    };
}

enum output_state bmp_image_data_writer(FILE * output_f, struct image * imag) {
    uint64_t width = imag -> width;
    for (size_t i = 0; i < imag -> height; i++) {
        if ((fwrite(&imag -> pixels[i * width], sizeof(struct pixel), width, output_f) != width)
            || (fseek(output_f, get_padding(width), SEEK_CUR) != 0)) {
            return BMP_IMAGE_WRITE_FAIL;
        }
    }
    return FILE_WRITE_SUCCESS;
}

enum output_state from_image_to_bmp(FILE * out, struct image * img) {
    uint32_t width = img -> width;
    uint32_t height = img -> height;
    struct bmp_header new_header = generate_header(width, height);
    size_t count = 1;
    if (fwrite(&new_header, sizeof(struct bmp_header), count, out) != count) {
        return BMP_HEADER_WRITE_FAIL;
    }
    enum output_state write_image_st = bmp_image_data_writer(out, img);
    if (write_image_st != FILE_WRITE_SUCCESS) {
        return write_image_st;
    }
    return FILE_WRITE_SUCCESS;
}


