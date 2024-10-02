
cmake_minimum_required(VERSION 3.10)
# Set the project name
project(PixelProject)

#Set the OpenCV paths
set(OpenCV_INCLUDE_DIRS /opt/homebrew/Cellar/opencv/4.10.0/include/opencv4/opencv2)
set(OpenCV_LIB_DIR /opt/homebrew/Cellar/opencv/4.10.0/lib)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})


# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add the executable
add_executable(MyProject MakeImage.cpp ColorMatch.cpp LegoColorClass.cpp Pixelate.cpp  ColorMatch.hpp main.cpp)

# Link OpenCV libraries
target_link_libraries(MyProject ${OpenCV_LIBS})
