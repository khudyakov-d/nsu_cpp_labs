# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CSVParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CSVParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CSVParser.dir/flags.make

CMakeFiles/CSVParser.dir/main.cpp.o: CMakeFiles/CSVParser.dir/flags.make
CMakeFiles/CSVParser.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CSVParser.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CSVParser.dir/main.cpp.o -c /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/main.cpp

CMakeFiles/CSVParser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSVParser.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/main.cpp > CMakeFiles/CSVParser.dir/main.cpp.i

CMakeFiles/CSVParser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSVParser.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/main.cpp -o CMakeFiles/CSVParser.dir/main.cpp.s

# Object files for target CSVParser
CSVParser_OBJECTS = \
"CMakeFiles/CSVParser.dir/main.cpp.o"

# External object files for target CSVParser
CSVParser_EXTERNAL_OBJECTS =

CSVParser: CMakeFiles/CSVParser.dir/main.cpp.o
CSVParser: CMakeFiles/CSVParser.dir/build.make
CSVParser: CMakeFiles/CSVParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CSVParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CSVParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CSVParser.dir/build: CSVParser

.PHONY : CMakeFiles/CSVParser.dir/build

CMakeFiles/CSVParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CSVParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CSVParser.dir/clean

CMakeFiles/CSVParser.dir/depend:
	cd /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/cmake-build-debug /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/cmake-build-debug /home/daniel/OOPprojects/oop_17207_khudyakov/CSVParser/cmake-build-debug/CMakeFiles/CSVParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CSVParser.dir/depend

