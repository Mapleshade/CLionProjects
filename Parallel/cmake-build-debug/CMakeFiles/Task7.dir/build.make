# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Elina\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\181.3986.16\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Elina\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\181.3986.16\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Elina\CLionProjects\Parallel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Elina\CLionProjects\Parallel\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task7.dir/flags.make

CMakeFiles/Task7.dir/Task7.c.obj: CMakeFiles/Task7.dir/flags.make
CMakeFiles/Task7.dir/Task7.c.obj: ../Task7.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elina\CLionProjects\Parallel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Task7.dir/Task7.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Task7.dir\Task7.c.obj   -c C:\Users\Elina\CLionProjects\Parallel\Task7.c

CMakeFiles/Task7.dir/Task7.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task7.dir/Task7.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elina\CLionProjects\Parallel\Task7.c > CMakeFiles\Task7.dir\Task7.c.i

CMakeFiles/Task7.dir/Task7.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task7.dir/Task7.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elina\CLionProjects\Parallel\Task7.c -o CMakeFiles\Task7.dir\Task7.c.s

CMakeFiles/Task7.dir/Task7.c.obj.requires:

.PHONY : CMakeFiles/Task7.dir/Task7.c.obj.requires

CMakeFiles/Task7.dir/Task7.c.obj.provides: CMakeFiles/Task7.dir/Task7.c.obj.requires
	$(MAKE) -f CMakeFiles\Task7.dir\build.make CMakeFiles/Task7.dir/Task7.c.obj.provides.build
.PHONY : CMakeFiles/Task7.dir/Task7.c.obj.provides

CMakeFiles/Task7.dir/Task7.c.obj.provides.build: CMakeFiles/Task7.dir/Task7.c.obj


# Object files for target Task7
Task7_OBJECTS = \
"CMakeFiles/Task7.dir/Task7.c.obj"

# External object files for target Task7
Task7_EXTERNAL_OBJECTS =

Task7.exe: CMakeFiles/Task7.dir/Task7.c.obj
Task7.exe: CMakeFiles/Task7.dir/build.make
Task7.exe: CMakeFiles/Task7.dir/linklibs.rsp
Task7.exe: CMakeFiles/Task7.dir/objects1.rsp
Task7.exe: CMakeFiles/Task7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elina\CLionProjects\Parallel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Task7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task7.dir/build: Task7.exe

.PHONY : CMakeFiles/Task7.dir/build

CMakeFiles/Task7.dir/requires: CMakeFiles/Task7.dir/Task7.c.obj.requires

.PHONY : CMakeFiles/Task7.dir/requires

CMakeFiles/Task7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task7.dir/clean

CMakeFiles/Task7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elina\CLionProjects\Parallel C:\Users\Elina\CLionProjects\Parallel C:\Users\Elina\CLionProjects\Parallel\cmake-build-debug C:\Users\Elina\CLionProjects\Parallel\cmake-build-debug C:\Users\Elina\CLionProjects\Parallel\cmake-build-debug\CMakeFiles\Task7.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task7.dir/depend

