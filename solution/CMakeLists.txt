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
        include/transform/rotate.h
        src/file_work/file_work.c
        include/file_work/file_work.h
        src/bmp/bmp.c
        include/bmp/bmp.h)
target_include_directories(image-transformer PRIVATE src include)
