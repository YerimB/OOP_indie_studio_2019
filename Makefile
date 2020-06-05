# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/alexis/Tek2/INDIE/OOP_indie_studio_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexis/Tek2/INDIE/OOP_indie_studio_2019

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
all:
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles 0
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

#=============================================================================
# Target rules for targets named bomberman

# Build rule for target.
bomberman:
	$(MAKE) -f CMakeFiles/Makefile2 bomberman
.PHONY : bomberman

# fast build rule for target.
bomberman/fast:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/build
.PHONY : bomberman/fast

Sources/Generation/Generation.o: Sources/Generation/Generation.cpp.o

.PHONY : Sources/Generation/Generation.o

# target to build an object file
Sources/Generation/Generation.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Generation/Generation.cpp.o
.PHONY : Sources/Generation/Generation.cpp.o

Sources/Generation/Generation.i: Sources/Generation/Generation.cpp.i

.PHONY : Sources/Generation/Generation.i

# target to preprocess a source file
Sources/Generation/Generation.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Generation/Generation.cpp.i
.PHONY : Sources/Generation/Generation.cpp.i

Sources/Generation/Generation.s: Sources/Generation/Generation.cpp.s

.PHONY : Sources/Generation/Generation.s

# target to generate assembly for a file
Sources/Generation/Generation.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Generation/Generation.cpp.s
.PHONY : Sources/Generation/Generation.cpp.s

Sources/InputManager.o: Sources/InputManager.cpp.o

.PHONY : Sources/InputManager.o

# target to build an object file
Sources/InputManager.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/InputManager.cpp.o
.PHONY : Sources/InputManager.cpp.o

Sources/InputManager.i: Sources/InputManager.cpp.i

.PHONY : Sources/InputManager.i

# target to preprocess a source file
Sources/InputManager.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/InputManager.cpp.i
.PHONY : Sources/InputManager.cpp.i

Sources/InputManager.s: Sources/InputManager.cpp.s

.PHONY : Sources/InputManager.s

# target to generate assembly for a file
Sources/InputManager.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/InputManager.cpp.s
.PHONY : Sources/InputManager.cpp.s

Sources/Map.o: Sources/Map.cpp.o

.PHONY : Sources/Map.o

# target to build an object file
Sources/Map.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Map.cpp.o
.PHONY : Sources/Map.cpp.o

Sources/Map.i: Sources/Map.cpp.i

.PHONY : Sources/Map.i

# target to preprocess a source file
Sources/Map.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Map.cpp.i
.PHONY : Sources/Map.cpp.i

Sources/Map.s: Sources/Map.cpp.s

.PHONY : Sources/Map.s

# target to generate assembly for a file
Sources/Map.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Map.cpp.s
.PHONY : Sources/Map.cpp.s

Sources/Thread/Thread.o: Sources/Thread/Thread.cpp.o

.PHONY : Sources/Thread/Thread.o

# target to build an object file
Sources/Thread/Thread.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.o
.PHONY : Sources/Thread/Thread.cpp.o

Sources/Thread/Thread.i: Sources/Thread/Thread.cpp.i

.PHONY : Sources/Thread/Thread.i

# target to preprocess a source file
Sources/Thread/Thread.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.i
.PHONY : Sources/Thread/Thread.cpp.i

Sources/Thread/Thread.s: Sources/Thread/Thread.cpp.s

.PHONY : Sources/Thread/Thread.s

# target to generate assembly for a file
Sources/Thread/Thread.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.s
.PHONY : Sources/Thread/Thread.cpp.s

Sources/Thread/ThreadPool.o: Sources/Thread/ThreadPool.cpp.o

.PHONY : Sources/Thread/ThreadPool.o

# target to build an object file
Sources/Thread/ThreadPool.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.o
.PHONY : Sources/Thread/ThreadPool.cpp.o

Sources/Thread/ThreadPool.i: Sources/Thread/ThreadPool.cpp.i

.PHONY : Sources/Thread/ThreadPool.i

# target to preprocess a source file
Sources/Thread/ThreadPool.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.i
.PHONY : Sources/Thread/ThreadPool.cpp.i

Sources/Thread/ThreadPool.s: Sources/Thread/ThreadPool.cpp.s

.PHONY : Sources/Thread/ThreadPool.s

# target to generate assembly for a file
Sources/Thread/ThreadPool.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.s
.PHONY : Sources/Thread/ThreadPool.cpp.s

Sources/main.o: Sources/main.cpp.o

.PHONY : Sources/main.o

# target to build an object file
Sources/main.cpp.o:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/main.cpp.o
.PHONY : Sources/main.cpp.o

Sources/main.i: Sources/main.cpp.i

.PHONY : Sources/main.i

# target to preprocess a source file
Sources/main.cpp.i:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/main.cpp.i
.PHONY : Sources/main.cpp.i

Sources/main.s: Sources/main.cpp.s

.PHONY : Sources/main.s

# target to generate assembly for a file
Sources/main.cpp.s:
	$(MAKE) -f CMakeFiles/bomberman.dir/build.make CMakeFiles/bomberman.dir/Sources/main.cpp.s
.PHONY : Sources/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... rebuild_cache"
	@echo "... bomberman"
	@echo "... edit_cache"
	@echo "... Sources/Generation/Generation.o"
	@echo "... Sources/Generation/Generation.i"
	@echo "... Sources/Generation/Generation.s"
	@echo "... Sources/InputManager.o"
	@echo "... Sources/InputManager.i"
	@echo "... Sources/InputManager.s"
	@echo "... Sources/Map.o"
	@echo "... Sources/Map.i"
	@echo "... Sources/Map.s"
	@echo "... Sources/Thread/Thread.o"
	@echo "... Sources/Thread/Thread.i"
	@echo "... Sources/Thread/Thread.s"
	@echo "... Sources/Thread/ThreadPool.o"
	@echo "... Sources/Thread/ThreadPool.i"
	@echo "... Sources/Thread/ThreadPool.s"
	@echo "... Sources/main.o"
	@echo "... Sources/main.i"
	@echo "... Sources/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

