# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\BookForWork\CODE---Data Structures in C\liststack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\BookForWork\CODE---Data Structures in C\liststack\build"

# Include any dependencies generated for this target.
include CMakeFiles/Proj_Stack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Proj_Stack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proj_Stack.dir/flags.make

CMakeFiles/Proj_Stack.dir/main.c.obj: CMakeFiles/Proj_Stack.dir/flags.make
CMakeFiles/Proj_Stack.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\BookForWork\CODE---Data Structures in C\liststack\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Proj_Stack.dir/main.c.obj"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Proj_Stack.dir\main.c.obj -c "E:\BookForWork\CODE---Data Structures in C\liststack\main.c"

CMakeFiles/Proj_Stack.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Proj_Stack.dir/main.c.i"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\BookForWork\CODE---Data Structures in C\liststack\main.c" > CMakeFiles\Proj_Stack.dir\main.c.i

CMakeFiles/Proj_Stack.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Proj_Stack.dir/main.c.s"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\BookForWork\CODE---Data Structures in C\liststack\main.c" -o CMakeFiles\Proj_Stack.dir\main.c.s

# Object files for target Proj_Stack
Proj_Stack_OBJECTS = \
"CMakeFiles/Proj_Stack.dir/main.c.obj"

# External object files for target Proj_Stack
Proj_Stack_EXTERNAL_OBJECTS =

Proj_Stack.exe: CMakeFiles/Proj_Stack.dir/main.c.obj
Proj_Stack.exe: CMakeFiles/Proj_Stack.dir/build.make
Proj_Stack.exe: CMakeFiles/Proj_Stack.dir/linklibs.rsp
Proj_Stack.exe: CMakeFiles/Proj_Stack.dir/objects1.rsp
Proj_Stack.exe: CMakeFiles/Proj_Stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\BookForWork\CODE---Data Structures in C\liststack\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Proj_Stack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Proj_Stack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proj_Stack.dir/build: Proj_Stack.exe

.PHONY : CMakeFiles/Proj_Stack.dir/build

CMakeFiles/Proj_Stack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Proj_Stack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Proj_Stack.dir/clean

CMakeFiles/Proj_Stack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\BookForWork\CODE---Data Structures in C\liststack" "E:\BookForWork\CODE---Data Structures in C\liststack" "E:\BookForWork\CODE---Data Structures in C\liststack\build" "E:\BookForWork\CODE---Data Structures in C\liststack\build" "E:\BookForWork\CODE---Data Structures in C\liststack\build\CMakeFiles\Proj_Stack.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Proj_Stack.dir/depend

