#ifndef IMAGE_TRANSFORMER_ROTATE_H
#define IMAGE_TRANSFORMER_ROTATE_H

#include "file_work/file_work.h"
#include "image/image.h"

//struct image rotate( struct image const source );
enum transform_state rotation(struct image input_image, struct image * rotate_image);
#endif
