# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/149/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/149/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haydn/CLionProjects/4001Assignment3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haydn/CLionProjects/4001Assignment3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4001Assignment3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4001Assignment3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4001Assignment3.dir/flags.make

CMakeFiles/4001Assignment3.dir/main.c.o: CMakeFiles/4001Assignment3.dir/flags.make
CMakeFiles/4001Assignment3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haydn/CLionProjects/4001Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/4001Assignment3.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/4001Assignment3.dir/main.c.o -c /home/haydn/CLionProjects/4001Assignment3/main.c

CMakeFiles/4001Assignment3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4001Assignment3.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/haydn/CLionProjects/4001Assignment3/main.c > CMakeFiles/4001Assignment3.dir/main.c.i

CMakeFiles/4001Assignment3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4001Assignment3.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/haydn/CLionProjects/4001Assignment3/main.c -o CMakeFiles/4001Assignment3.dir/main.c.s

# Object files for target 4001Assignment3
4001Assignment3_OBJECTS = \
"CMakeFiles/4001Assignment3.dir/main.c.o"

# External object files for target 4001Assignment3
4001Assignment3_EXTERNAL_OBJECTS =

4001Assignment3: CMakeFiles/4001Assignment3.dir/main.c.o
4001Assignment3: CMakeFiles/4001Assignment3.dir/build.make
4001Assignment3: CMakeFiles/4001Assignment3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haydn/CLionProjects/4001Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 4001Assignment3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/4001Assignment3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4001Assignment3.dir/build: 4001Assignment3

.PHONY : CMakeFiles/4001Assignment3.dir/build

CMakeFiles/4001Assignment3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/4001Assignment3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/4001Assignment3.dir/clean

CMakeFiles/4001Assignment3.dir/depend:
	cd /home/haydn/CLionProjects/4001Assignment3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haydn/CLionProjects/4001Assignment3 /home/haydn/CLionProjects/4001Assignment3 /home/haydn/CLionProjects/4001Assignment3/cmake-build-debug /home/haydn/CLionProjects/4001Assignment3/cmake-build-debug /home/haydn/CLionProjects/4001Assignment3/cmake-build-debug/CMakeFiles/4001Assignment3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4001Assignment3.dir/depend

