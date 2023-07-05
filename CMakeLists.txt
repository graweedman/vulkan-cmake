cmake_minimum_required(VERSION 3.12)
project(VulkanApp LANGUAGES CXX)

set(GLFW_DIR "C:/VulkanSDK/glfw-3.3.8.bin.WIN64")  # Replace with the actual path to your GLFW directory

# find_package(glfw3 CONFIG REQUIRED)

find_package(Vulkan REQUIRED)
file(GLOB_RECURSE SOURCES "src/*.cpp") # src/main.cpp src/lve_app_base.cpp src/lve_window.cpp src/hello.cpp
add_executable(${PROJECT_NAME} ${SOURCES})

# Include GLFW headers
include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)

include_directories(${PROJECT_NAME} PRIVATE "C:/VulkanSDK/glm")

include_directories(${PROJECT_NAME} PRIVATE "C:/VulkanSDK/1.3.250.1/Include")

# Link GLFW library
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/lib-vc2022/glfw3.lib)

# Link Vulkan library
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)

# Set C++ standard and compiler flags
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF)
target_compile_options(${PROJECT_NAME} PRIVATE /W4)