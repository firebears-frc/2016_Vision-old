# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_SOURCE_DIR = /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0

# Utility rule file for pch_Generate_opencv_objdetect.

# Include the progress variables for this target.
include modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/progress.make

modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect: modules/objdetect/precomp.hpp.gch/opencv_objdetect_RELEASE.gch


modules/objdetect/precomp.hpp.gch/opencv_objdetect_RELEASE.gch: modules/objdetect/src/precomp.hpp
modules/objdetect/precomp.hpp.gch/opencv_objdetect_RELEASE.gch: modules/objdetect/precomp.hpp
modules/objdetect/precomp.hpp.gch/opencv_objdetect_RELEASE.gch: lib/libopencv_objdetect_pch_dephelp.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating precomp.hpp.gch/opencv_objdetect_RELEASE.gch"
	cd /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect && /usr/bin/cmake -E make_directory /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/precomp.hpp.gch
	cd /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG -isystem"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/3rdparty/include/opencl/1.2" -isystem"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0" -isystem"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/3rdparty/include/opencl/1.2" -isystem"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/include" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/src" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/hal/include" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/core/include" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/imgproc/include" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/ml/include" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/imgcodecs/include" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/videoio/include" -I"/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/highgui/include" -D__OPENCV_BUILD=1 -fPIC -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -x c++-header -o /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/precomp.hpp.gch/opencv_objdetect_RELEASE.gch /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/precomp.hpp

modules/objdetect/precomp.hpp: modules/objdetect/src/precomp.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating precomp.hpp"
	cd /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect && /usr/bin/cmake -E copy /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/src/precomp.hpp /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/precomp.hpp

pch_Generate_opencv_objdetect: modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect
pch_Generate_opencv_objdetect: modules/objdetect/precomp.hpp.gch/opencv_objdetect_RELEASE.gch
pch_Generate_opencv_objdetect: modules/objdetect/precomp.hpp
pch_Generate_opencv_objdetect: modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/build.make

.PHONY : pch_Generate_opencv_objdetect

# Rule to build all files generated by this target.
modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/build: pch_Generate_opencv_objdetect

.PHONY : modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/build

modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/clean:
	cd /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_objdetect.dir/cmake_clean.cmake
.PHONY : modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/clean

modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/depend:
	cd /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0 /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0 /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect /home/jeron/prg/examples/opencv_with_jll/deps/opencv-3.0.0/modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/objdetect/CMakeFiles/pch_Generate_opencv_objdetect.dir/depend

