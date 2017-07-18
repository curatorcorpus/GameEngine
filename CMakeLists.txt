CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(render_engine)

IF(UNIX)
  FIND_PACKAGE(PkgConfig REQUIRED)
ENDIF(UNIX)

# CMake Settings
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules")

# Enable C++11 compiler
INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
  IF(COMPILER_SUPPORTS_CXX11)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    SET(LIBFREENECT2_WITH_CXX11_SUPPORT 1)
    SET(HAVE_CXX11 yes)
  ELSEIF(COMPILER_SUPPORTS_CXX0X)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    SET(HAVE_CXX11 c++0x)
  ELSE()
    SET(HAVE_CXX11 no)
    MESSAGE(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
ENDIF()

# GLFW Libraries
#FIND_PACKAGE(GLFW REQUIRED)
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FIND_PACKAGE(OpenGL REQUIRED) # 
FIND_PACKAGE(GLM REQUIRED)    # Find OpenGL
FIND_PACKAGE(GLEW REQUIRED)   # Find GLM Libraries

INCLUDE_DIRECTORIES(
    ${OPENGL_INCLUDE_DIRS}
    #${GLFW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    #includes/depends/GL
    includes/engine
    includes/shaders
)

SET(SRC_CODE

    #sources/depends/glew.c
#sources/depends/visualinfo.c
#sources/depends/glewinfo.c

  	sources/engine/display_manager.cpp
    sources/engine/render_manager.cpp
    sources/engine/input_manager.cpp

    sources/shaders/shader.cpp

  	render_engine.cpp
)

ADD_SUBDIRECTORY(
    externals/glfw-3.2.1
)

ADD_DEFINITIONS(
    #-DGLEW_STATIC
)

ADD_EXECUTABLE(render_engine
	${SRC_CODE}
)

TARGET_LINK_LIBRARIES(render_engine 
    glfw
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    #${GLFW_LIBRARIES}
    ${GLM_LIBRARIES}
)