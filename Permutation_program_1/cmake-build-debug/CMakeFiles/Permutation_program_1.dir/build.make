# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\matth\CLionProjects\Permutation_program_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\matth\CLionProjects\Permutation_program_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Permutation_program_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Permutation_program_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Permutation_program_1.dir/flags.make

CMakeFiles/Permutation_program_1.dir/main.c.obj: CMakeFiles/Permutation_program_1.dir/flags.make
CMakeFiles/Permutation_program_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\matth\CLionProjects\Permutation_program_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Permutation_program_1.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Permutation_program_1.dir\main.c.obj   -c C:\Users\matth\CLionProjects\Permutation_program_1\main.c

CMakeFiles/Permutation_program_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Permutation_program_1.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\matth\CLionProjects\Permutation_program_1\main.c > CMakeFiles\Permutation_program_1.dir\main.c.i

CMakeFiles/Permutation_program_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Permutation_program_1.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\matth\CLionProjects\Permutation_program_1\main.c -o CMakeFiles\Permutation_program_1.dir\main.c.s

CMakeFiles/Permutation_program_1.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Permutation_program_1.dir/main.c.obj.requires

CMakeFiles/Permutation_program_1.dir/main.c.obj.provides: CMakeFiles/Permutation_program_1.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Permutation_program_1.dir\build.make CMakeFiles/Permutation_program_1.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Permutation_program_1.dir/main.c.obj.provides

CMakeFiles/Permutation_program_1.dir/main.c.obj.provides.build: CMakeFiles/Permutation_program_1.dir/main.c.obj


# Object files for target Permutation_program_1
Permutation_program_1_OBJECTS = \
"CMakeFiles/Permutation_program_1.dir/main.c.obj"

# External object files for target Permutation_program_1
Permutation_program_1_EXTERNAL_OBJECTS =

Permutation_program_1.exe: CMakeFiles/Permutation_program_1.dir/main.c.obj
Permutation_program_1.exe: CMakeFiles/Permutation_program_1.dir/build.make
Permutation_program_1.exe: CMakeFiles/Permutation_program_1.dir/linklibs.rsp
Permutation_program_1.exe: CMakeFiles/Permutation_program_1.dir/objects1.rsp
Permutation_program_1.exe: CMakeFiles/Permutation_program_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\matth\CLionProjects\Permutation_program_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Permutation_program_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Permutation_program_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Permutation_program_1.dir/build: Permutation_program_1.exe

.PHONY : CMakeFiles/Permutation_program_1.dir/build

CMakeFiles/Permutation_program_1.dir/requires: CMakeFiles/Permutation_program_1.dir/main.c.obj.requires

.PHONY : CMakeFiles/Permutation_program_1.dir/requires

CMakeFiles/Permutation_program_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Permutation_program_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Permutation_program_1.dir/clean

CMakeFiles/Permutation_program_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\matth\CLionProjects\Permutation_program_1 C:\Users\matth\CLionProjects\Permutation_program_1 C:\Users\matth\CLionProjects\Permutation_program_1\cmake-build-debug C:\Users\matth\CLionProjects\Permutation_program_1\cmake-build-debug C:\Users\matth\CLionProjects\Permutation_program_1\cmake-build-debug\CMakeFiles\Permutation_program_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Permutation_program_1.dir/depend
