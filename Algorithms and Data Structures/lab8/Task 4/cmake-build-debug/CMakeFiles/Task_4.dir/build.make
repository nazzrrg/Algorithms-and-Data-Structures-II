# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Task_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_4.dir/flags.make

CMakeFiles/Task_4.dir/main.cpp.o: CMakeFiles/Task_4.dir/flags.make
CMakeFiles/Task_4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_4.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task_4.dir/main.cpp.o -c "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/main.cpp"

CMakeFiles/Task_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_4.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/main.cpp" > CMakeFiles/Task_4.dir/main.cpp.i

CMakeFiles/Task_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_4.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/main.cpp" -o CMakeFiles/Task_4.dir/main.cpp.s

# Object files for target Task_4
Task_4_OBJECTS = \
"CMakeFiles/Task_4.dir/main.cpp.o"

# External object files for target Task_4
Task_4_EXTERNAL_OBJECTS =

Task_4: CMakeFiles/Task_4.dir/main.cpp.o
Task_4: CMakeFiles/Task_4.dir/build.make
Task_4: CMakeFiles/Task_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_4.dir/build: Task_4

.PHONY : CMakeFiles/Task_4.dir/build

CMakeFiles/Task_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task_4.dir/clean

CMakeFiles/Task_4.dir/depend:
	cd "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4" "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4" "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/cmake-build-debug" "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/cmake-build-debug" "/Users/nazzrrg/Git/Algorithms-and-Data-Structures-II/Algorithms and Data Structures/lab8/Task 4/cmake-build-debug/CMakeFiles/Task_4.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Task_4.dir/depend

