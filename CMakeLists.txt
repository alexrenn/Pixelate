
cmake_minimum_required(VERSION 3.10)
# Set the project name
project(PixelProject)

# Specify the compilers explicitly
set(CMAKE_C_COMPILER "/opt/homebrew/Cellar/llvm/19.1.0/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/Cellar/llvm/19.1.0/bin/clang++")

#Set the OpenCV paths
set(OpenCV_INCLUDE_DIRS /opt/homebrew/Cellar/opencv/4.10.0/include/opencv4/opencv2)
set(OpenCV_INCLUDE_DIRS /opt/homebrew/Cellar/opencv/4.10.0/include/opencv4/opencv2)
set(OpenCV_LIB_DIR /opt/homebrew/Cellar/opencv/4.10.0/lib)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})


# Find packages
find_package(OpenCV REQUIRED)
#find_package(OpenMP REQUIRED)

# Add the executable
add_executable(MyProject MakeImage.cpp ColorMatch.cpp LegoColorClass.cpp Pixelate.cpp  ColorMatch.hpp main.cpp)

# Link libraries
# target_link_libraries(MyProject ${OpenCV_LIBS})
target_link_libraries(MyProject ${OpenCV_LIBS} ${OpenMP_omp_LIBRARY})
