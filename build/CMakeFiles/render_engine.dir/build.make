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
CMAKE_SOURCE_DIR = /home/curator/Repositories/rasterization

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/curator/Repositories/rasterization/build

# Include any dependencies generated for this target.
include CMakeFiles/render_engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/render_engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/render_engine.dir/flags.make

CMakeFiles/render_engine.dir/render_engine.cpp.o: CMakeFiles/render_engine.dir/flags.make
CMakeFiles/render_engine.dir/render_engine.cpp.o: ../render_engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/curator/Repositories/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/render_engine.dir/render_engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/render_engine.dir/render_engine.cpp.o -c /home/curator/Repositories/rasterization/render_engine.cpp

CMakeFiles/render_engine.dir/render_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/render_engine.dir/render_engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/curator/Repositories/rasterization/render_engine.cpp > CMakeFiles/render_engine.dir/render_engine.cpp.i

CMakeFiles/render_engine.dir/render_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/render_engine.dir/render_engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/curator/Repositories/rasterization/render_engine.cpp -o CMakeFiles/render_engine.dir/render_engine.cpp.s

CMakeFiles/render_engine.dir/render_engine.cpp.o.requires:

.PHONY : CMakeFiles/render_engine.dir/render_engine.cpp.o.requires

CMakeFiles/render_engine.dir/render_engine.cpp.o.provides: CMakeFiles/render_engine.dir/render_engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/render_engine.dir/build.make CMakeFiles/render_engine.dir/render_engine.cpp.o.provides.build
.PHONY : CMakeFiles/render_engine.dir/render_engine.cpp.o.provides

CMakeFiles/render_engine.dir/render_engine.cpp.o.provides.build: CMakeFiles/render_engine.dir/render_engine.cpp.o


# Object files for target render_engine
render_engine_OBJECTS = \
"CMakeFiles/render_engine.dir/render_engine.cpp.o"

# External object files for target render_engine
render_engine_EXTERNAL_OBJECTS =

render_engine: CMakeFiles/render_engine.dir/render_engine.cpp.o
render_engine: CMakeFiles/render_engine.dir/build.make
render_engine: CMakeFiles/render_engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/curator/Repositories/rasterization/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable render_engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/render_engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/render_engine.dir/build: render_engine

.PHONY : CMakeFiles/render_engine.dir/build

CMakeFiles/render_engine.dir/requires: CMakeFiles/render_engine.dir/render_engine.cpp.o.requires

.PHONY : CMakeFiles/render_engine.dir/requires

CMakeFiles/render_engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/render_engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/render_engine.dir/clean

CMakeFiles/render_engine.dir/depend:
	cd /home/curator/Repositories/rasterization/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/curator/Repositories/rasterization /home/curator/Repositories/rasterization /home/curator/Repositories/rasterization/build /home/curator/Repositories/rasterization/build /home/curator/Repositories/rasterization/build/CMakeFiles/render_engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/render_engine.dir/depend
