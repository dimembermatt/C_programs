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
CMAKE_SOURCE_DIR = C:\Users\matth\CLionProjects\LoadingBar_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\matth\CLionProjects\LoadingBar_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LoadingBar_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LoadingBar_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LoadingBar_1.dir/flags.make

CMakeFiles/LoadingBar_1.dir/main.c.obj: CMakeFiles/LoadingBar_1.dir/flags.make
CMakeFiles/LoadingBar_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\matth\CLionProjects\LoadingBar_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LoadingBar_1.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LoadingBar_1.dir\main.c.obj   -c C:\Users\matth\CLionProjects\LoadingBar_1\main.c

CMakeFiles/LoadingBar_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LoadingBar_1.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\matth\CLionProjects\LoadingBar_1\main.c > CMakeFiles\LoadingBar_1.dir\main.c.i

CMakeFiles/LoadingBar_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LoadingBar_1.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\matth\CLionProjects\LoadingBar_1\main.c -o CMakeFiles\LoadingBar_1.dir\main.c.s

CMakeFiles/LoadingBar_1.dir/main.c.obj.requires:

.PHONY : CMakeFiles/LoadingBar_1.dir/main.c.obj.requires

CMakeFiles/LoadingBar_1.dir/main.c.obj.provides: CMakeFiles/LoadingBar_1.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\LoadingBar_1.dir\build.make CMakeFiles/LoadingBar_1.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/LoadingBar_1.dir/main.c.obj.provides

CMakeFiles/LoadingBar_1.dir/main.c.obj.provides.build: CMakeFiles/LoadingBar_1.dir/main.c.obj


# Object files for target LoadingBar_1
LoadingBar_1_OBJECTS = \
"CMakeFiles/LoadingBar_1.dir/main.c.obj"

# External object files for target LoadingBar_1
LoadingBar_1_EXTERNAL_OBJECTS =

LoadingBar_1.exe: CMakeFiles/LoadingBar_1.dir/main.c.obj
LoadingBar_1.exe: CMakeFiles/LoadingBar_1.dir/build.make
LoadingBar_1.exe: CMakeFiles/LoadingBar_1.dir/linklibs.rsp
LoadingBar_1.exe: CMakeFiles/LoadingBar_1.dir/objects1.rsp
LoadingBar_1.exe: CMakeFiles/LoadingBar_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\matth\CLionProjects\LoadingBar_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LoadingBar_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LoadingBar_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LoadingBar_1.dir/build: LoadingBar_1.exe

.PHONY : CMakeFiles/LoadingBar_1.dir/build

CMakeFiles/LoadingBar_1.dir/requires: CMakeFiles/LoadingBar_1.dir/main.c.obj.requires

.PHONY : CMakeFiles/LoadingBar_1.dir/requires

CMakeFiles/LoadingBar_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LoadingBar_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LoadingBar_1.dir/clean

CMakeFiles/LoadingBar_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\matth\CLionProjects\LoadingBar_1 C:\Users\matth\CLionProjects\LoadingBar_1 C:\Users\matth\CLionProjects\LoadingBar_1\cmake-build-debug C:\Users\matth\CLionProjects\LoadingBar_1\cmake-build-debug C:\Users\matth\CLionProjects\LoadingBar_1\cmake-build-debug\CMakeFiles\LoadingBar_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LoadingBar_1.dir/depend

