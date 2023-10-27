file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(image-transformer ${sources}
        src/bmp_read/bmp_reader.c
        include/bmp_read/bmp_reader.h
        src/image/image.c
        include/image/image.h
        src/transform/rotate.c
        include/transform/rotate.h)
target_include_directories(image-transformer PRIVATE src include)
