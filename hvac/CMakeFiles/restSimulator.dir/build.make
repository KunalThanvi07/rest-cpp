# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/yash/hvacSimRest_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yash/hvacSimRest_2

# Include any dependencies generated for this target.
include CMakeFiles/restSimulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/restSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/restSimulator.dir/flags.make

CMakeFiles/restSimulator.dir/restApplication.cpp.o: CMakeFiles/restSimulator.dir/flags.make
CMakeFiles/restSimulator.dir/restApplication.cpp.o: restApplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yash/hvacSimRest_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/restSimulator.dir/restApplication.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/restSimulator.dir/restApplication.cpp.o -c /home/yash/hvacSimRest_2/restApplication.cpp

CMakeFiles/restSimulator.dir/restApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/restSimulator.dir/restApplication.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yash/hvacSimRest_2/restApplication.cpp > CMakeFiles/restSimulator.dir/restApplication.cpp.i

CMakeFiles/restSimulator.dir/restApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/restSimulator.dir/restApplication.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yash/hvacSimRest_2/restApplication.cpp -o CMakeFiles/restSimulator.dir/restApplication.cpp.s

CMakeFiles/restSimulator.dir/restSimulator.cpp.o: CMakeFiles/restSimulator.dir/flags.make
CMakeFiles/restSimulator.dir/restSimulator.cpp.o: restSimulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yash/hvacSimRest_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/restSimulator.dir/restSimulator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/restSimulator.dir/restSimulator.cpp.o -c /home/yash/hvacSimRest_2/restSimulator.cpp

CMakeFiles/restSimulator.dir/restSimulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/restSimulator.dir/restSimulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yash/hvacSimRest_2/restSimulator.cpp > CMakeFiles/restSimulator.dir/restSimulator.cpp.i

CMakeFiles/restSimulator.dir/restSimulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/restSimulator.dir/restSimulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yash/hvacSimRest_2/restSimulator.cpp -o CMakeFiles/restSimulator.dir/restSimulator.cpp.s

# Object files for target restSimulator
restSimulator_OBJECTS = \
"CMakeFiles/restSimulator.dir/restApplication.cpp.o" \
"CMakeFiles/restSimulator.dir/restSimulator.cpp.o"

# External object files for target restSimulator
restSimulator_EXTERNAL_OBJECTS =

restSimulator: CMakeFiles/restSimulator.dir/restApplication.cpp.o
restSimulator: CMakeFiles/restSimulator.dir/restSimulator.cpp.o
restSimulator: CMakeFiles/restSimulator.dir/build.make
restSimulator: /usr/lib/x86_64-linux-gnu/libcpprest.so.2.10
restSimulator: /usr/local/lib/libboost_system.so.1.66.0
restSimulator: /usr/lib/x86_64-linux-gnu/libssl.so
restSimulator: /usr/lib/x86_64-linux-gnu/libcrypto.so
restSimulator: CMakeFiles/restSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yash/hvacSimRest_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable restSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/restSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/restSimulator.dir/build: restSimulator

.PHONY : CMakeFiles/restSimulator.dir/build

CMakeFiles/restSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/restSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/restSimulator.dir/clean

CMakeFiles/restSimulator.dir/depend:
	cd /home/yash/hvacSimRest_2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yash/hvacSimRest_2 /home/yash/hvacSimRest_2 /home/yash/hvacSimRest_2 /home/yash/hvacSimRest_2 /home/yash/hvacSimRest_2/CMakeFiles/restSimulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/restSimulator.dir/depend

