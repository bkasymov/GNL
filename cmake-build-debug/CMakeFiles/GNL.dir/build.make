# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /private/var/folders/zz/zyxvpxvq6csfxvn_n00014yh00097m/T/AppTranslocation/1B81918C-7680-4C18-AB9A-65CCCC4522CF/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/zz/zyxvpxvq6csfxvn_n00014yh00097m/T/AppTranslocation/1B81918C-7680-4C18-AB9A-65CCCC4522CF/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dpenney/Desktop/GNL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dpenney/Desktop/GNL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GNL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GNL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GNL.dir/flags.make

CMakeFiles/GNL.dir/obrazec.c.o: CMakeFiles/GNL.dir/flags.make
CMakeFiles/GNL.dir/obrazec.c.o: ../obrazec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dpenney/Desktop/GNL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GNL.dir/obrazec.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GNL.dir/obrazec.c.o   -c /Users/dpenney/Desktop/GNL/obrazec.c

CMakeFiles/GNL.dir/obrazec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GNL.dir/obrazec.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dpenney/Desktop/GNL/obrazec.c > CMakeFiles/GNL.dir/obrazec.c.i

CMakeFiles/GNL.dir/obrazec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GNL.dir/obrazec.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dpenney/Desktop/GNL/obrazec.c -o CMakeFiles/GNL.dir/obrazec.c.s

# Object files for target GNL
GNL_OBJECTS = \
"CMakeFiles/GNL.dir/obrazec.c.o"

# External object files for target GNL
GNL_EXTERNAL_OBJECTS =

GNL: CMakeFiles/GNL.dir/obrazec.c.o
GNL: CMakeFiles/GNL.dir/build.make
GNL: CMakeFiles/GNL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dpenney/Desktop/GNL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable GNL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GNL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GNL.dir/build: GNL

.PHONY : CMakeFiles/GNL.dir/build

CMakeFiles/GNL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GNL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GNL.dir/clean

CMakeFiles/GNL.dir/depend:
	cd /Users/dpenney/Desktop/GNL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dpenney/Desktop/GNL /Users/dpenney/Desktop/GNL /Users/dpenney/Desktop/GNL/cmake-build-debug /Users/dpenney/Desktop/GNL/cmake-build-debug /Users/dpenney/Desktop/GNL/cmake-build-debug/CMakeFiles/GNL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GNL.dir/depend
