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
CMAKE_SOURCE_DIR = /home/median/OIMP/cpp-pilot-hse/tasks/archiver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/median/OIMP/cpp-pilot-hse/tasks/archiver

# Include any dependencies generated for this target.
include CMakeFiles/archiver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/archiver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/archiver.dir/flags.make

CMakeFiles/archiver.dir/main.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/archiver.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/main.cpp.o -c /home/median/OIMP/cpp-pilot-hse/tasks/archiver/main.cpp

CMakeFiles/archiver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/median/OIMP/cpp-pilot-hse/tasks/archiver/main.cpp > CMakeFiles/archiver.dir/main.cpp.i

CMakeFiles/archiver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/median/OIMP/cpp-pilot-hse/tasks/archiver/main.cpp -o CMakeFiles/archiver.dir/main.cpp.s

CMakeFiles/archiver.dir/BitIO.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/BitIO.cpp.o: BitIO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/archiver.dir/BitIO.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/BitIO.cpp.o -c /home/median/OIMP/cpp-pilot-hse/tasks/archiver/BitIO.cpp

CMakeFiles/archiver.dir/BitIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/BitIO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/median/OIMP/cpp-pilot-hse/tasks/archiver/BitIO.cpp > CMakeFiles/archiver.dir/BitIO.cpp.i

CMakeFiles/archiver.dir/BitIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/BitIO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/median/OIMP/cpp-pilot-hse/tasks/archiver/BitIO.cpp -o CMakeFiles/archiver.dir/BitIO.cpp.s

CMakeFiles/archiver.dir/Decoder.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/Decoder.cpp.o: Decoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/archiver.dir/Decoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/Decoder.cpp.o -c /home/median/OIMP/cpp-pilot-hse/tasks/archiver/Decoder.cpp

CMakeFiles/archiver.dir/Decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/Decoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/median/OIMP/cpp-pilot-hse/tasks/archiver/Decoder.cpp > CMakeFiles/archiver.dir/Decoder.cpp.i

CMakeFiles/archiver.dir/Decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/Decoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/median/OIMP/cpp-pilot-hse/tasks/archiver/Decoder.cpp -o CMakeFiles/archiver.dir/Decoder.cpp.s

CMakeFiles/archiver.dir/Encoder.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/Encoder.cpp.o: Encoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/archiver.dir/Encoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/Encoder.cpp.o -c /home/median/OIMP/cpp-pilot-hse/tasks/archiver/Encoder.cpp

CMakeFiles/archiver.dir/Encoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/Encoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/median/OIMP/cpp-pilot-hse/tasks/archiver/Encoder.cpp > CMakeFiles/archiver.dir/Encoder.cpp.i

CMakeFiles/archiver.dir/Encoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/Encoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/median/OIMP/cpp-pilot-hse/tasks/archiver/Encoder.cpp -o CMakeFiles/archiver.dir/Encoder.cpp.s

CMakeFiles/archiver.dir/HuffmanTree.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/HuffmanTree.cpp.o: HuffmanTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/archiver.dir/HuffmanTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/HuffmanTree.cpp.o -c /home/median/OIMP/cpp-pilot-hse/tasks/archiver/HuffmanTree.cpp

CMakeFiles/archiver.dir/HuffmanTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/HuffmanTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/median/OIMP/cpp-pilot-hse/tasks/archiver/HuffmanTree.cpp > CMakeFiles/archiver.dir/HuffmanTree.cpp.i

CMakeFiles/archiver.dir/HuffmanTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/HuffmanTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/median/OIMP/cpp-pilot-hse/tasks/archiver/HuffmanTree.cpp -o CMakeFiles/archiver.dir/HuffmanTree.cpp.s

CMakeFiles/archiver.dir/PriorityQueue.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/PriorityQueue.cpp.o: PriorityQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/archiver.dir/PriorityQueue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/PriorityQueue.cpp.o -c /home/median/OIMP/cpp-pilot-hse/tasks/archiver/PriorityQueue.cpp

CMakeFiles/archiver.dir/PriorityQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/PriorityQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/median/OIMP/cpp-pilot-hse/tasks/archiver/PriorityQueue.cpp > CMakeFiles/archiver.dir/PriorityQueue.cpp.i

CMakeFiles/archiver.dir/PriorityQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/PriorityQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/median/OIMP/cpp-pilot-hse/tasks/archiver/PriorityQueue.cpp -o CMakeFiles/archiver.dir/PriorityQueue.cpp.s

# Object files for target archiver
archiver_OBJECTS = \
"CMakeFiles/archiver.dir/main.cpp.o" \
"CMakeFiles/archiver.dir/BitIO.cpp.o" \
"CMakeFiles/archiver.dir/Decoder.cpp.o" \
"CMakeFiles/archiver.dir/Encoder.cpp.o" \
"CMakeFiles/archiver.dir/HuffmanTree.cpp.o" \
"CMakeFiles/archiver.dir/PriorityQueue.cpp.o"

# External object files for target archiver
archiver_EXTERNAL_OBJECTS =

archiver: CMakeFiles/archiver.dir/main.cpp.o
archiver: CMakeFiles/archiver.dir/BitIO.cpp.o
archiver: CMakeFiles/archiver.dir/Decoder.cpp.o
archiver: CMakeFiles/archiver.dir/Encoder.cpp.o
archiver: CMakeFiles/archiver.dir/HuffmanTree.cpp.o
archiver: CMakeFiles/archiver.dir/PriorityQueue.cpp.o
archiver: CMakeFiles/archiver.dir/build.make
archiver: CMakeFiles/archiver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable archiver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/archiver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/archiver.dir/build: archiver

.PHONY : CMakeFiles/archiver.dir/build

CMakeFiles/archiver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/archiver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/archiver.dir/clean

CMakeFiles/archiver.dir/depend:
	cd /home/median/OIMP/cpp-pilot-hse/tasks/archiver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/median/OIMP/cpp-pilot-hse/tasks/archiver /home/median/OIMP/cpp-pilot-hse/tasks/archiver /home/median/OIMP/cpp-pilot-hse/tasks/archiver /home/median/OIMP/cpp-pilot-hse/tasks/archiver /home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles/archiver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/archiver.dir/depend

