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
CMAKE_SOURCE_DIR = C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/flags.make

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/flags.make
CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Baum_Sweet_Sequence_Program_1.dir\main.c.obj   -c C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\main.c

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\main.c > CMakeFiles\Baum_Sweet_Sequence_Program_1.dir\main.c.i

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\main.c -o CMakeFiles\Baum_Sweet_Sequence_Program_1.dir\main.c.s

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.requires

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.provides: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Baum_Sweet_Sequence_Program_1.dir\build.make CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.provides

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.provides.build: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj


# Object files for target Baum_Sweet_Sequence_Program_1
Baum_Sweet_Sequence_Program_1_OBJECTS = \
"CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj"

# External object files for target Baum_Sweet_Sequence_Program_1
Baum_Sweet_Sequence_Program_1_EXTERNAL_OBJECTS =

Baum_Sweet_Sequence_Program_1.exe: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj
Baum_Sweet_Sequence_Program_1.exe: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/build.make
Baum_Sweet_Sequence_Program_1.exe: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/linklibs.rsp
Baum_Sweet_Sequence_Program_1.exe: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/objects1.rsp
Baum_Sweet_Sequence_Program_1.exe: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Baum_Sweet_Sequence_Program_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Baum_Sweet_Sequence_Program_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/build: Baum_Sweet_Sequence_Program_1.exe

.PHONY : CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/build

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/requires: CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/main.c.obj.requires

.PHONY : CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/requires

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Baum_Sweet_Sequence_Program_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/clean

CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1 C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1 C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\cmake-build-debug C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\cmake-build-debug C:\Users\matth\CLionProjects\Baum_Sweet_Sequence_Program_1\cmake-build-debug\CMakeFiles\Baum_Sweet_Sequence_Program_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Baum_Sweet_Sequence_Program_1.dir/depend
