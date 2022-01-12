cmake_minimum_required(VERSION "3.17")

project(bilberry)

# set OpenCV_DIR equals to the install path (after compilation)
set(OpenCV_DIR /Users/lauro/Documents/workspace/install_opencv/lib/cmake/opencv4)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )

# include OpenCV
include_directories( ${OpenCV_INCLUDE_DIRS})

# search for *.cpp and *.h
file(GLOB bilberry_SRC
     "src/*.h"
     "src/*.cpp"
)

add_executable(bilberry-demo ${bilberry_SRC})

# Link OpenCV
target_link_libraries(bilberry-demo ${OpenCV_LIBS} )
