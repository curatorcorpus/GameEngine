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
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FIND_PACKAGE(OpenGL REQUIRED) # Find OpenGL - 
FIND_PACKAGE(GLM REQUIRED)    # Find GLM Libraries - maths library for graphics
FIND_PACKAGE(GLEW REQUIRED)   # Find GLEW libraries - 
FIND_PACKAGE(assimp REQUIRED) # Find Assimp libraries
FIND_PACKAGE(PNG REQUIRED)    # Find Libpmg libraries

INCLUDE_DIRECTORIES(
    
    ${OPENGL_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${PNG_INCLUDE_DIR}

    includes/engine
    includes/entities
    includes/shaders
    includes/terrains
    includes/textures
)

SET(SRC_CODE

    sources/engine/controls.cpp
  	sources/engine/display.cpp
    sources/engine/master_renderer.cpp
    sources/engine/loader.cpp

    sources/entities/camera.cpp
    sources/entities/light.cpp
    sources/entities/mesh.cpp
    sources/entities/model.cpp
    sources/entities/object.cpp

    sources/shaders/shader.cpp

    sources/terrains/terrain.cpp

  	render_engine.cpp
)

ADD_DEFINITIONS(
    #-DGLEW_STATIC
)

ADD_EXECUTABLE(render_engine
	
    ${SRC_CODE}
)

TARGET_LINK_LIBRARIES(render_engine 
    
    glfw
    ${ASSIMP_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLM_LIBRARIES}
    ${PNG_LIBRARY}
)