# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /snap/clion/126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/126/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniltolmachev/Boniface

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniltolmachev/Boniface

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/clion/126/bin/cmake/linux/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/snap/clion/126/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/daniltolmachev/Boniface/CMakeFiles /home/daniltolmachev/Boniface/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/daniltolmachev/Boniface/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Boniface

# Build rule for target.
Boniface: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Boniface
.PHONY : Boniface

# fast build rule for target.
Boniface/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/build
.PHONY : Boniface/fast

app/App.o: app/App.cpp.o

.PHONY : app/App.o

# target to build an object file
app/App.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/app/App.cpp.o
.PHONY : app/App.cpp.o

app/App.i: app/App.cpp.i

.PHONY : app/App.i

# target to preprocess a source file
app/App.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/app/App.cpp.i
.PHONY : app/App.cpp.i

app/App.s: app/App.cpp.s

.PHONY : app/App.s

# target to generate assembly for a file
app/App.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/app/App.cpp.s
.PHONY : app/App.cpp.s

context/Context.o: context/Context.cpp.o

.PHONY : context/Context.o

# target to build an object file
context/Context.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/Context.cpp.o
.PHONY : context/Context.cpp.o

context/Context.i: context/Context.cpp.i

.PHONY : context/Context.i

# target to preprocess a source file
context/Context.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/Context.cpp.i
.PHONY : context/Context.cpp.i

context/Context.s: context/Context.cpp.s

.PHONY : context/Context.s

# target to generate assembly for a file
context/Context.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/Context.cpp.s
.PHONY : context/Context.cpp.s

context/request/Request.o: context/request/Request.cpp.o

.PHONY : context/request/Request.o

# target to build an object file
context/request/Request.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/request/Request.cpp.o
.PHONY : context/request/Request.cpp.o

context/request/Request.i: context/request/Request.cpp.i

.PHONY : context/request/Request.i

# target to preprocess a source file
context/request/Request.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/request/Request.cpp.i
.PHONY : context/request/Request.cpp.i

context/request/Request.s: context/request/Request.cpp.s

.PHONY : context/request/Request.s

# target to generate assembly for a file
context/request/Request.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/request/Request.cpp.s
.PHONY : context/request/Request.cpp.s

context/response/Response.o: context/response/Response.cpp.o

.PHONY : context/response/Response.o

# target to build an object file
context/response/Response.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/response/Response.cpp.o
.PHONY : context/response/Response.cpp.o

context/response/Response.i: context/response/Response.cpp.i

.PHONY : context/response/Response.i

# target to preprocess a source file
context/response/Response.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/response/Response.cpp.i
.PHONY : context/response/Response.cpp.i

context/response/Response.s: context/response/Response.cpp.s

.PHONY : context/response/Response.s

# target to generate assembly for a file
context/response/Response.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/context/response/Response.cpp.s
.PHONY : context/response/Response.cpp.s

examples/main.o: examples/main.cpp.o

.PHONY : examples/main.o

# target to build an object file
examples/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/examples/main.cpp.o
.PHONY : examples/main.cpp.o

examples/main.i: examples/main.cpp.i

.PHONY : examples/main.i

# target to preprocess a source file
examples/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/examples/main.cpp.i
.PHONY : examples/main.cpp.i

examples/main.s: examples/main.cpp.s

.PHONY : examples/main.s

# target to generate assembly for a file
examples/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/examples/main.cpp.s
.PHONY : examples/main.cpp.s

middleware/MiddlewareManager.o: middleware/MiddlewareManager.cpp.o

.PHONY : middleware/MiddlewareManager.o

# target to build an object file
middleware/MiddlewareManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/middleware/MiddlewareManager.cpp.o
.PHONY : middleware/MiddlewareManager.cpp.o

middleware/MiddlewareManager.i: middleware/MiddlewareManager.cpp.i

.PHONY : middleware/MiddlewareManager.i

# target to preprocess a source file
middleware/MiddlewareManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/middleware/MiddlewareManager.cpp.i
.PHONY : middleware/MiddlewareManager.cpp.i

middleware/MiddlewareManager.s: middleware/MiddlewareManager.cpp.s

.PHONY : middleware/MiddlewareManager.s

# target to generate assembly for a file
middleware/MiddlewareManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/middleware/MiddlewareManager.cpp.s
.PHONY : middleware/MiddlewareManager.cpp.s

routing/Router.o: routing/Router.cpp.o

.PHONY : routing/Router.o

# target to build an object file
routing/Router.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/routing/Router.cpp.o
.PHONY : routing/Router.cpp.o

routing/Router.i: routing/Router.cpp.i

.PHONY : routing/Router.i

# target to preprocess a source file
routing/Router.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/routing/Router.cpp.i
.PHONY : routing/Router.cpp.i

routing/Router.s: routing/Router.cpp.s

.PHONY : routing/Router.s

# target to generate assembly for a file
routing/Router.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Boniface.dir/build.make CMakeFiles/Boniface.dir/routing/Router.cpp.s
.PHONY : routing/Router.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Boniface"
	@echo "... app/App.o"
	@echo "... app/App.i"
	@echo "... app/App.s"
	@echo "... context/Context.o"
	@echo "... context/Context.i"
	@echo "... context/Context.s"
	@echo "... context/request/Request.o"
	@echo "... context/request/Request.i"
	@echo "... context/request/Request.s"
	@echo "... context/response/Response.o"
	@echo "... context/response/Response.i"
	@echo "... context/response/Response.s"
	@echo "... examples/main.o"
	@echo "... examples/main.i"
	@echo "... examples/main.s"
	@echo "... middleware/MiddlewareManager.o"
	@echo "... middleware/MiddlewareManager.i"
	@echo "... middleware/MiddlewareManager.s"
	@echo "... routing/Router.o"
	@echo "... routing/Router.i"
	@echo "... routing/Router.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

