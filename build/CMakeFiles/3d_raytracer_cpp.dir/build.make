# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\franc\Documents\Personal_Projects\3DRayTracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build

# Include any dependencies generated for this target.
include CMakeFiles/3d_raytracer_cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/3d_raytracer_cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/3d_raytracer_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3d_raytracer_cpp.dir/flags.make

CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/flags.make
CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/includes_CXX.rsp
CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj: C:/Users/franc/Documents/Personal_Projects/3DRayTracer/src/main.cpp
CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj -MF CMakeFiles\3d_raytracer_cpp.dir\src\main.cpp.obj.d -o CMakeFiles\3d_raytracer_cpp.dir\src\main.cpp.obj -c C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\main.cpp

CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\main.cpp > CMakeFiles\3d_raytracer_cpp.dir\src\main.cpp.i

CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\main.cpp -o CMakeFiles\3d_raytracer_cpp.dir\src\main.cpp.s

CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/flags.make
CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/includes_CXX.rsp
CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj: C:/Users/franc/Documents/Personal_Projects/3DRayTracer/src/math.cpp
CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj -MF CMakeFiles\3d_raytracer_cpp.dir\src\math.cpp.obj.d -o CMakeFiles\3d_raytracer_cpp.dir\src\math.cpp.obj -c C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\math.cpp

CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\math.cpp > CMakeFiles\3d_raytracer_cpp.dir\src\math.cpp.i

CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\math.cpp -o CMakeFiles\3d_raytracer_cpp.dir\src\math.cpp.s

CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/flags.make
CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/includes_CXX.rsp
CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj: C:/Users/franc/Documents/Personal_Projects/3DRayTracer/src/canvas.cpp
CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj -MF CMakeFiles\3d_raytracer_cpp.dir\src\canvas.cpp.obj.d -o CMakeFiles\3d_raytracer_cpp.dir\src\canvas.cpp.obj -c C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\canvas.cpp

CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\canvas.cpp > CMakeFiles\3d_raytracer_cpp.dir\src\canvas.cpp.i

CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\canvas.cpp -o CMakeFiles\3d_raytracer_cpp.dir\src\canvas.cpp.s

CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/flags.make
CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/includes_CXX.rsp
CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj: C:/Users/franc/Documents/Personal_Projects/3DRayTracer/src/ray.cpp
CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj: CMakeFiles/3d_raytracer_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj -MF CMakeFiles\3d_raytracer_cpp.dir\src\ray.cpp.obj.d -o CMakeFiles\3d_raytracer_cpp.dir\src\ray.cpp.obj -c C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\ray.cpp

CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\ray.cpp > CMakeFiles\3d_raytracer_cpp.dir\src\ray.cpp.i

CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\3DRayTracer\src\ray.cpp -o CMakeFiles\3d_raytracer_cpp.dir\src\ray.cpp.s

# Object files for target 3d_raytracer_cpp
3d_raytracer_cpp_OBJECTS = \
"CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj" \
"CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj" \
"CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj" \
"CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj"

# External object files for target 3d_raytracer_cpp
3d_raytracer_cpp_EXTERNAL_OBJECTS =

3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/src/main.cpp.obj
3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/src/math.cpp.obj
3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/src/canvas.cpp.obj
3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/src/ray.cpp.obj
3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/build.make
3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/linkLibs.rsp
3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/objects1.rsp
3d_raytracer_cpp.exe: CMakeFiles/3d_raytracer_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable 3d_raytracer_cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3d_raytracer_cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3d_raytracer_cpp.dir/build: 3d_raytracer_cpp.exe
.PHONY : CMakeFiles/3d_raytracer_cpp.dir/build

CMakeFiles/3d_raytracer_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3d_raytracer_cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3d_raytracer_cpp.dir/clean

CMakeFiles/3d_raytracer_cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\franc\Documents\Personal_Projects\3DRayTracer C:\Users\franc\Documents\Personal_Projects\3DRayTracer C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build C:\Users\franc\Documents\Personal_Projects\3DRayTracer\build\CMakeFiles\3d_raytracer_cpp.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/3d_raytracer_cpp.dir/depend

