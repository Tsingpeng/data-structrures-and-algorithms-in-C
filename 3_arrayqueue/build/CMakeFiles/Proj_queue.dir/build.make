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
CMAKE_SOURCE_DIR = "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\build"

# Include any dependencies generated for this target.
include CMakeFiles/Proj_queue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Proj_queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proj_queue.dir/flags.make

CMakeFiles/Proj_queue.dir/main.c.obj: CMakeFiles/Proj_queue.dir/flags.make
CMakeFiles/Proj_queue.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Proj_queue.dir/main.c.obj"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Proj_queue.dir\main.c.obj -c "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\main.c"

CMakeFiles/Proj_queue.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Proj_queue.dir/main.c.i"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\main.c" > CMakeFiles\Proj_queue.dir\main.c.i

CMakeFiles/Proj_queue.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Proj_queue.dir/main.c.s"
	D:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\main.c" -o CMakeFiles\Proj_queue.dir\main.c.s

# Object files for target Proj_queue
Proj_queue_OBJECTS = \
"CMakeFiles/Proj_queue.dir/main.c.obj"

# External object files for target Proj_queue
Proj_queue_EXTERNAL_OBJECTS =

Proj_queue.exe: CMakeFiles/Proj_queue.dir/main.c.obj
Proj_queue.exe: CMakeFiles/Proj_queue.dir/build.make
Proj_queue.exe: CMakeFiles/Proj_queue.dir/linklibs.rsp
Proj_queue.exe: CMakeFiles/Proj_queue.dir/objects1.rsp
Proj_queue.exe: CMakeFiles/Proj_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Proj_queue.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Proj_queue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proj_queue.dir/build: Proj_queue.exe

.PHONY : CMakeFiles/Proj_queue.dir/build

CMakeFiles/Proj_queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Proj_queue.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Proj_queue.dir/clean

CMakeFiles/Proj_queue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue" "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue" "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\build" "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\build" "E:\BookForWork\CODE---Data Structures in C\3_arrayqueue\build\CMakeFiles\Proj_queue.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Proj_queue.dir/depend
