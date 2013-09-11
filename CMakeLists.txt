project(libimghash)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
FIND_PACKAGE(ImageMagick COMPONENTS Magick++)
include_directories("${ImageMagick_INCLUDE_DIRS}")
include_directories(".")
add_definitions("-DMAGICKCORE_QUANTUM_DEPTH=8" "-DMAGICKCORE_HDRI_ENABLE=0")
add_library(libimghash SHARED libimghash.cpp libimghash.h source.cpp source.h hash.cpp hash.h hasher.cpp hasher.h simplehasher.cpp simplehasher.h)

add_executable(singlefile examples/singlefile.cpp)
target_link_libraries(singlefile libimghash ${ImageMagick_LIBRARIES})

add_executable(delta examples/delta.cpp)
target_link_libraries(delta libimghash ${ImageMagick_LIBRARIES})
