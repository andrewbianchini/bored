# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrewbianchini/code/bored/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrewbianchini/code/bored/cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/bored.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bored.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bored.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bored.dir/flags.make

CMakeFiles/bored.dir/bored.cpp.o: CMakeFiles/bored.dir/flags.make
CMakeFiles/bored.dir/bored.cpp.o: /Users/andrewbianchini/code/bored/cpp/bored.cpp
CMakeFiles/bored.dir/bored.cpp.o: CMakeFiles/bored.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/andrewbianchini/code/bored/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bored.dir/bored.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bored.dir/bored.cpp.o -MF CMakeFiles/bored.dir/bored.cpp.o.d -o CMakeFiles/bored.dir/bored.cpp.o -c /Users/andrewbianchini/code/bored/cpp/bored.cpp

CMakeFiles/bored.dir/bored.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bored.dir/bored.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrewbianchini/code/bored/cpp/bored.cpp > CMakeFiles/bored.dir/bored.cpp.i

CMakeFiles/bored.dir/bored.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bored.dir/bored.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrewbianchini/code/bored/cpp/bored.cpp -o CMakeFiles/bored.dir/bored.cpp.s

# Object files for target bored
bored_OBJECTS = \
"CMakeFiles/bored.dir/bored.cpp.o"

# External object files for target bored
bored_EXTERNAL_OBJECTS =

bored: CMakeFiles/bored.dir/bored.cpp.o
bored: CMakeFiles/bored.dir/build.make
bored: /opt/homebrew/Cellar/sdl2/2.28.3/lib/libSDL2.dylib
bored: CMakeFiles/bored.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/andrewbianchini/code/bored/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bored"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bored.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bored.dir/build: bored
.PHONY : CMakeFiles/bored.dir/build

CMakeFiles/bored.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bored.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bored.dir/clean

CMakeFiles/bored.dir/depend:
	cd /Users/andrewbianchini/code/bored/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrewbianchini/code/bored/cpp /Users/andrewbianchini/code/bored/cpp /Users/andrewbianchini/code/bored/cpp/build /Users/andrewbianchini/code/bored/cpp/build /Users/andrewbianchini/code/bored/cpp/build/CMakeFiles/bored.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bored.dir/depend

