//
// Created by user on 25.11.2023.
//

#ifndef IMAGE_TRANSFORMER_BMP_H
#define IMAGE_TRANSFORMER_BMP_H

#include <stdio.h>
#include "image/image.h"
#include "file_work/file_work.h"

enum input_state from_bmp_to_image(FILE* in, struct image* img );
enum output_state from_image_to_bmp(FILE * out, struct image * img);

#endif //IMAGE_TRANSFORMER_BMP_H
