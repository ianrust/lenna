# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/ian/Documents/lenna

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ian/Documents/lenna

# Include any dependencies generated for this target.
include CMakeFiles/lenna.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lenna.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lenna.dir/flags.make

CMakeFiles/lenna.dir/lennify.cpp.o: CMakeFiles/lenna.dir/flags.make
CMakeFiles/lenna.dir/lennify.cpp.o: lennify.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ian/Documents/lenna/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lenna.dir/lennify.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lenna.dir/lennify.cpp.o -c /home/ian/Documents/lenna/lennify.cpp

CMakeFiles/lenna.dir/lennify.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lenna.dir/lennify.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ian/Documents/lenna/lennify.cpp > CMakeFiles/lenna.dir/lennify.cpp.i

CMakeFiles/lenna.dir/lennify.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lenna.dir/lennify.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ian/Documents/lenna/lennify.cpp -o CMakeFiles/lenna.dir/lennify.cpp.s

CMakeFiles/lenna.dir/lennify.cpp.o.requires:
.PHONY : CMakeFiles/lenna.dir/lennify.cpp.o.requires

CMakeFiles/lenna.dir/lennify.cpp.o.provides: CMakeFiles/lenna.dir/lennify.cpp.o.requires
	$(MAKE) -f CMakeFiles/lenna.dir/build.make CMakeFiles/lenna.dir/lennify.cpp.o.provides.build
.PHONY : CMakeFiles/lenna.dir/lennify.cpp.o.provides

CMakeFiles/lenna.dir/lennify.cpp.o.provides.build: CMakeFiles/lenna.dir/lennify.cpp.o

# Object files for target lenna
lenna_OBJECTS = \
"CMakeFiles/lenna.dir/lennify.cpp.o"

# External object files for target lenna
lenna_EXTERNAL_OBJECTS =

lenna: CMakeFiles/lenna.dir/lennify.cpp.o
lenna: CMakeFiles/lenna.dir/build.make
lenna: /usr/local/lib/libopencv_videostab.so.2.4.8
lenna: /usr/local/lib/libopencv_video.so.2.4.8
lenna: /usr/local/lib/libopencv_ts.a
lenna: /usr/local/lib/libopencv_superres.so.2.4.8
lenna: /usr/local/lib/libopencv_stitching.so.2.4.8
lenna: /usr/local/lib/libopencv_photo.so.2.4.8
lenna: /usr/local/lib/libopencv_ocl.so.2.4.8
lenna: /usr/local/lib/libopencv_objdetect.so.2.4.8
lenna: /usr/local/lib/libopencv_nonfree.so.2.4.8
lenna: /usr/local/lib/libopencv_ml.so.2.4.8
lenna: /usr/local/lib/libopencv_legacy.so.2.4.8
lenna: /usr/local/lib/libopencv_imgproc.so.2.4.8
lenna: /usr/local/lib/libopencv_highgui.so.2.4.8
lenna: /usr/local/lib/libopencv_gpu.so.2.4.8
lenna: /usr/local/lib/libopencv_flann.so.2.4.8
lenna: /usr/local/lib/libopencv_features2d.so.2.4.8
lenna: /usr/local/lib/libopencv_core.so.2.4.8
lenna: /usr/local/lib/libopencv_contrib.so.2.4.8
lenna: /usr/local/lib/libopencv_calib3d.so.2.4.8
lenna: /usr/lib/i386-linux-gnu/libGLU.so
lenna: /usr/lib/i386-linux-gnu/libGL.so
lenna: /usr/lib/i386-linux-gnu/libSM.so
lenna: /usr/lib/i386-linux-gnu/libICE.so
lenna: /usr/lib/i386-linux-gnu/libX11.so
lenna: /usr/lib/i386-linux-gnu/libXext.so
lenna: /usr/local/lib/libopencv_nonfree.so.2.4.8
lenna: /usr/local/lib/libopencv_ocl.so.2.4.8
lenna: /usr/local/lib/libopencv_gpu.so.2.4.8
lenna: /usr/local/lib/libopencv_photo.so.2.4.8
lenna: /usr/local/lib/libopencv_objdetect.so.2.4.8
lenna: /usr/local/lib/libopencv_legacy.so.2.4.8
lenna: /usr/local/lib/libopencv_video.so.2.4.8
lenna: /usr/local/lib/libopencv_ml.so.2.4.8
lenna: /usr/local/lib/libopencv_calib3d.so.2.4.8
lenna: /usr/local/lib/libopencv_features2d.so.2.4.8
lenna: /usr/local/lib/libopencv_highgui.so.2.4.8
lenna: /usr/local/lib/libopencv_imgproc.so.2.4.8
lenna: /usr/local/lib/libopencv_flann.so.2.4.8
lenna: /usr/local/lib/libopencv_core.so.2.4.8
lenna: CMakeFiles/lenna.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lenna"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lenna.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lenna.dir/build: lenna
.PHONY : CMakeFiles/lenna.dir/build

CMakeFiles/lenna.dir/requires: CMakeFiles/lenna.dir/lennify.cpp.o.requires
.PHONY : CMakeFiles/lenna.dir/requires

CMakeFiles/lenna.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lenna.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lenna.dir/clean

CMakeFiles/lenna.dir/depend:
	cd /home/ian/Documents/lenna && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ian/Documents/lenna /home/ian/Documents/lenna /home/ian/Documents/lenna /home/ian/Documents/lenna /home/ian/Documents/lenna/CMakeFiles/lenna.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lenna.dir/depend

