cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME LearningVulkan)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(SOURCES src/main.cpp)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

project(${PROJECT_NAME} VERSION 0.0.1)

source_group("Source files" FILES SOURCES)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/externals/glfw/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/externals/glm/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/externals/vulkanSDK/include)

target_link_libraries(${PROJECT_NAME} PRIVATE optimized ${CMAKE_CURRENT_SOURCE_DIR}/externals/glfw/lib/Release/glfw3.lib)
target_link_libraries(${PROJECT_NAME} PRIVATE debug ${CMAKE_CURRENT_SOURCE_DIR}/externals/glfw/lib/Debug/glfw3.lib)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/externals/vulkanSDK/lib/vulkan-1.lib)

target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_VULKAN)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLM_FORCE_RADIANS)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLM_FORCE_DEPTH_ZERO_TO_ONE)

message("Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
