# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/curator/Repository/rasterization

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/curator/Repository/rasterization/build

# Include any dependencies generated for this target.
include CMakeFiles/render_engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/render_engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/render_engine.dir/flags.make

CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o: ../sources/engine/controls.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o -c /home/curator/Repository/rasterization/sources/engine/controls.cpp

CMakeFiles/render_engine.dir/sources/engine/controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/engine/controls.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/engine/controls.cpp > CMakeFiles/render_engine.dir/sources/engine/controls.cpp.i

CMakeFiles/render_engine.dir/sources/engine/controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/engine/controls.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/engine/controls.cpp -o CMakeFiles/render_engine.dir/sources/engine/controls.cpp.s

CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.requires

CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.provides: CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.provides

CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o


CMakeFiles/render_engine.dir/sources/engine/display.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/engine/display.cpp.o: ../sources/engine/display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/render_engine.dir/sources/engine/display.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/engine/display.cpp.o -c /home/curator/Repository/rasterization/sources/engine/display.cpp

CMakeFiles/render_engine.dir/sources/engine/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/engine/display.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/engine/display.cpp > CMakeFiles/render_engine.dir/sources/engine/display.cpp.i

CMakeFiles/render_engine.dir/sources/engine/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/engine/display.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/engine/display.cpp -o CMakeFiles/render_engine.dir/sources/engine/display.cpp.s

CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.requires

CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.provides: CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.provides

CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/engine/display.cpp.o


CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o: ../sources/engine/master_renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o -c /home/curator/Repository/rasterization/sources/engine/master_renderer.cpp

CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/engine/master_renderer.cpp > CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.i

CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/engine/master_renderer.cpp -o CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.s

CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.requires

CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.provides: CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.provides

CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o


CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o: ../sources/engine/model_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o -c /home/curator/Repository/rasterization/sources/engine/model_loader.cpp

CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/engine/model_loader.cpp > CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.i

CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/engine/model_loader.cpp -o CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.s

CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.requires

CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.provides: CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.provides

CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o


CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o: ../sources/entities/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o -c /home/curator/Repository/rasterization/sources/entities/camera.cpp

CMakeFiles/render_engine.dir/sources/entities/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/entities/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/entities/camera.cpp > CMakeFiles/render_engine.dir/sources/entities/camera.cpp.i

CMakeFiles/render_engine.dir/sources/entities/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/entities/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/entities/camera.cpp -o CMakeFiles/render_engine.dir/sources/entities/camera.cpp.s

CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.requires

CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.provides: CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.provides

CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o


CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o: ../sources/entities/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o -c /home/curator/Repository/rasterization/sources/entities/mesh.cpp

CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/entities/mesh.cpp > CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.i

CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/entities/mesh.cpp -o CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.s

CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.requires

CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.provides: CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.provides

CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o


CMakeFiles/render_engine.dir/sources/entities/model.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/entities/model.cpp.o: ../sources/entities/model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/render_engine.dir/sources/entities/model.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/entities/model.cpp.o -c /home/curator/Repository/rasterization/sources/entities/model.cpp

CMakeFiles/render_engine.dir/sources/entities/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/entities/model.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/entities/model.cpp > CMakeFiles/render_engine.dir/sources/entities/model.cpp.i

CMakeFiles/render_engine.dir/sources/entities/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/entities/model.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/entities/model.cpp -o CMakeFiles/render_engine.dir/sources/entities/model.cpp.s

CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.requires

CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.provides: CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.provides

CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/entities/model.cpp.o


CMakeFiles/render_engine.dir/sources/entities/object.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/entities/object.cpp.o: ../sources/entities/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/render_engine.dir/sources/entities/object.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/entities/object.cpp.o -c /home/curator/Repository/rasterization/sources/entities/object.cpp

CMakeFiles/render_engine.dir/sources/entities/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/entities/object.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/entities/object.cpp > CMakeFiles/render_engine.dir/sources/entities/object.cpp.i

CMakeFiles/render_engine.dir/sources/entities/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/entities/object.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/entities/object.cpp -o CMakeFiles/render_engine.dir/sources/entities/object.cpp.s

CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.requires

CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.provides: CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.provides

CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/entities/object.cpp.o


CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o: ../sources/entities/textured_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o -c /home/curator/Repository/rasterization/sources/entities/textured_model.cpp

CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/entities/textured_model.cpp > CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.i

CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/entities/textured_model.cpp -o CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.s

CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.requires

CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.provides: CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.provides

CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o


CMakeFiles/render_engine.dir/sources/entities/light.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/entities/light.cpp.o: ../sources/entities/light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/render_engine.dir/sources/entities/light.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/entities/light.cpp.o -c /home/curator/Repository/rasterization/sources/entities/light.cpp

CMakeFiles/render_engine.dir/sources/entities/light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/entities/light.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/entities/light.cpp > CMakeFiles/render_engine.dir/sources/entities/light.cpp.i

CMakeFiles/render_engine.dir/sources/entities/light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/entities/light.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/entities/light.cpp -o CMakeFiles/render_engine.dir/sources/entities/light.cpp.s

CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.requires

CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.provides: CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.provides

CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/entities/light.cpp.o


CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o: ../sources/shaders/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o -c /home/curator/Repository/rasterization/sources/shaders/shader.cpp

CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/sources/shaders/shader.cpp > CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.i

CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/sources/shaders/shader.cpp -o CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.s

CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.requires

CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.provides: CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.provides

CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.provides.build: CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o


CMakeFiles/render_engine.dir/render_engine.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/render_engine.cpp.o: ../render_engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/render_engine.dir/render_engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/render_engine.cpp.o -c /home/curator/Repository/rasterization/render_engine.cpp

CMakeFiles/render_engine.dir/render_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/render_engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repository/rasterization/render_engine.cpp > CMakeFiles/render_engine.dir/render_engine.cpp.i

CMakeFiles/render_engine.dir/render_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/render_engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repository/rasterization/render_engine.cpp -o CMakeFiles/render_engine.dir/render_engine.cpp.s

CMakeFiles/render_engine.dir/render_engine.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/render_engine.cpp.o.requires

CMakeFiles/render_engine.dir/render_engine.cpp.o.provides: CMakeFiles/render_engine.dir/render_engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/render_engine.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/render_engine.cpp.o.provides

CMakeFiles/render_engine.dir/render_engine.cpp.o.provides.build: CMakeFiles/render_engine.dir/render_engine.cpp.o


# Object files for target render_engine
render_engine_OBJECTS = \
"CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o" \
"CMakeFiles/render_engine.dir/sources/engine/display.cpp.o" \
"CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o" \
"CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o" \
"CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o" \
"CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o" \
"CMakeFiles/render_engine.dir/sources/entities/model.cpp.o" \
"CMakeFiles/render_engine.dir/sources/entities/object.cpp.o" \
"CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o" \
"CMakeFiles/render_engine.dir/sources/entities/light.cpp.o" \
"CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o" \
"CMakeFiles/render_engine.dir/render_engine.cpp.o"

# External object files for target render_engine
render_engine_EXTERNAL_OBJECTS =

render_engine: CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/engine/display.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/entities/model.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/entities/object.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/entities/light.cpp.o
render_engine: CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o
render_engine: CMakeFiles/render_engine.dir/render_engine.cpp.o
render_engine: CMakeFiles/render_engine.dir/build.make
render_engine: externals/glfw-3.2.1/src/libglfw3.a
render_engine: /usr/lib/x86_64-linux-gnu/libGLEW.so
render_engine: /usr/lib/x86_64-linux-gnu/libGLU.so
render_engine: /usr/lib/x86_64-linux-gnu/libGL.so
render_engine: /usr/lib/x86_64-linux-gnu/libpng.so
render_engine: /usr/lib/x86_64-linux-gnu/librt.so
render_engine: /usr/lib/x86_64-linux-gnu/libm.so
render_engine: /usr/lib/x86_64-linux-gnu/libX11.so
render_engine: /usr/lib/x86_64-linux-gnu/libXrandr.so
render_engine: /usr/lib/x86_64-linux-gnu/libXinerama.so
render_engine: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
render_engine: /usr/lib/x86_64-linux-gnu/libXcursor.so
render_engine: CMakeFiles/render_engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/curator/Repository/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable render_engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/render_engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/render_engine.dir/build: render_engine

.PHONY : CMakeFiles/render_engine.dir/build

CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/engine/controls.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/engine/display.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/engine/master_renderer.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/engine/model_loader.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/entities/camera.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/entities/mesh.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/entities/model.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/entities/object.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/entities/textured_model.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/entities/light.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/sources/shaders/shader.cpp.o.requires
CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/render_engine.cpp.o.requires

.PHONY : CMakeFiles/render_engine.dir/requires

CMakeFiles/render_engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/render_engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/render_engine.dir/clean

CMakeFiles/render_engine.dir/depend:
	cd /home/curator/Repository/rasterization/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/curator/Repository/rasterization /home/curator/Repository/rasterization /home/curator/Repository/rasterization/build /home/curator/Repository/rasterization/build /home/curator/Repository/rasterization/build/CMakeFiles/render_engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/render_engine.dir/depend

