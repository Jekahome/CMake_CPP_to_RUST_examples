# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/my_project_fake_dyn_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_project_fake_dyn_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_project_fake_dyn_lib.dir/flags.make

CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.o: CMakeFiles/my_project_fake_dyn_lib.dir/flags.make
CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.o: ../lib/my_shared_dynamic_lib/sLibrary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.o -c /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/lib/my_shared_dynamic_lib/sLibrary.cpp

CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/lib/my_shared_dynamic_lib/sLibrary.cpp > CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.i

CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/lib/my_shared_dynamic_lib/sLibrary.cpp -o CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.s

# Object files for target my_project_fake_dyn_lib
my_project_fake_dyn_lib_OBJECTS = \
"CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.o"

# External object files for target my_project_fake_dyn_lib
my_project_fake_dyn_lib_EXTERNAL_OBJECTS =

libmy_project_fake_dyn_lib.so: CMakeFiles/my_project_fake_dyn_lib.dir/lib/my_shared_dynamic_lib/sLibrary.cpp.o
libmy_project_fake_dyn_lib.so: CMakeFiles/my_project_fake_dyn_lib.dir/build.make
libmy_project_fake_dyn_lib.so: CMakeFiles/my_project_fake_dyn_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmy_project_fake_dyn_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_project_fake_dyn_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_project_fake_dyn_lib.dir/build: libmy_project_fake_dyn_lib.so

.PHONY : CMakeFiles/my_project_fake_dyn_lib.dir/build

CMakeFiles/my_project_fake_dyn_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_project_fake_dyn_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_project_fake_dyn_lib.dir/clean

CMakeFiles/my_project_fake_dyn_lib.dir/depend:
	cd /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/build /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/build /media/jeka/PROJECTS/Develop/esp32/learn_cmake/project_cpp/build/CMakeFiles/my_project_fake_dyn_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_project_fake_dyn_lib.dir/depend

