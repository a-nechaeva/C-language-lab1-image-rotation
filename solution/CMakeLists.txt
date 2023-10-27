file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(image-transformer ${sources}
        src/bmp_read/bmp_reader.c
        src/bmp_read/bmp_reader.h
        src/image/image.c
        src/image/image.h)
target_include_directories(image-transformer PRIVATE src include)
