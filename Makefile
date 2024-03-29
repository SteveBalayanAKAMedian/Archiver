# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles /home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/median/OIMP/cpp-pilot-hse/tasks/archiver/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named archiver

# Build rule for target.
archiver: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 archiver
.PHONY : archiver

# fast build rule for target.
archiver/fast:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/build
.PHONY : archiver/fast

BitIO.o: BitIO.cpp.o

.PHONY : BitIO.o

# target to build an object file
BitIO.cpp.o:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/BitIO.cpp.o
.PHONY : BitIO.cpp.o

BitIO.i: BitIO.cpp.i

.PHONY : BitIO.i

# target to preprocess a source file
BitIO.cpp.i:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/BitIO.cpp.i
.PHONY : BitIO.cpp.i

BitIO.s: BitIO.cpp.s

.PHONY : BitIO.s

# target to generate assembly for a file
BitIO.cpp.s:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/BitIO.cpp.s
.PHONY : BitIO.cpp.s

Decoder.o: Decoder.cpp.o

.PHONY : Decoder.o

# target to build an object file
Decoder.cpp.o:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/Decoder.cpp.o
.PHONY : Decoder.cpp.o

Decoder.i: Decoder.cpp.i

.PHONY : Decoder.i

# target to preprocess a source file
Decoder.cpp.i:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/Decoder.cpp.i
.PHONY : Decoder.cpp.i

Decoder.s: Decoder.cpp.s

.PHONY : Decoder.s

# target to generate assembly for a file
Decoder.cpp.s:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/Decoder.cpp.s
.PHONY : Decoder.cpp.s

Encoder.o: Encoder.cpp.o

.PHONY : Encoder.o

# target to build an object file
Encoder.cpp.o:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/Encoder.cpp.o
.PHONY : Encoder.cpp.o

Encoder.i: Encoder.cpp.i

.PHONY : Encoder.i

# target to preprocess a source file
Encoder.cpp.i:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/Encoder.cpp.i
.PHONY : Encoder.cpp.i

Encoder.s: Encoder.cpp.s

.PHONY : Encoder.s

# target to generate assembly for a file
Encoder.cpp.s:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/Encoder.cpp.s
.PHONY : Encoder.cpp.s

HuffmanTree.o: HuffmanTree.cpp.o

.PHONY : HuffmanTree.o

# target to build an object file
HuffmanTree.cpp.o:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/HuffmanTree.cpp.o
.PHONY : HuffmanTree.cpp.o

HuffmanTree.i: HuffmanTree.cpp.i

.PHONY : HuffmanTree.i

# target to preprocess a source file
HuffmanTree.cpp.i:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/HuffmanTree.cpp.i
.PHONY : HuffmanTree.cpp.i

HuffmanTree.s: HuffmanTree.cpp.s

.PHONY : HuffmanTree.s

# target to generate assembly for a file
HuffmanTree.cpp.s:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/HuffmanTree.cpp.s
.PHONY : HuffmanTree.cpp.s

PriorityQueue.o: PriorityQueue.cpp.o

.PHONY : PriorityQueue.o

# target to build an object file
PriorityQueue.cpp.o:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/PriorityQueue.cpp.o
.PHONY : PriorityQueue.cpp.o

PriorityQueue.i: PriorityQueue.cpp.i

.PHONY : PriorityQueue.i

# target to preprocess a source file
PriorityQueue.cpp.i:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/PriorityQueue.cpp.i
.PHONY : PriorityQueue.cpp.i

PriorityQueue.s: PriorityQueue.cpp.s

.PHONY : PriorityQueue.s

# target to generate assembly for a file
PriorityQueue.cpp.s:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/PriorityQueue.cpp.s
.PHONY : PriorityQueue.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/archiver.dir/build.make CMakeFiles/archiver.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... archiver"
	@echo "... BitIO.o"
	@echo "... BitIO.i"
	@echo "... BitIO.s"
	@echo "... Decoder.o"
	@echo "... Decoder.i"
	@echo "... Decoder.s"
	@echo "... Encoder.o"
	@echo "... Encoder.i"
	@echo "... Encoder.s"
	@echo "... HuffmanTree.o"
	@echo "... HuffmanTree.i"
	@echo "... HuffmanTree.s"
	@echo "... PriorityQueue.o"
	@echo "... PriorityQueue.i"
	@echo "... PriorityQueue.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

