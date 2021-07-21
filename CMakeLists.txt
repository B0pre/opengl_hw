cmake_minimum_required (VERSION 2.6)

project (opengl_hw.app)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(${PROJECT_NAME} opengl_hw.cpp)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLEW::GLEW glfw)
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})