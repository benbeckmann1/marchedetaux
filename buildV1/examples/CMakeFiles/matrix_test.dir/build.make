# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1413/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1413/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/matrix_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/matrix_test.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/matrix_test.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/matrix_test.dir/flags.make

examples/CMakeFiles/matrix_test.dir/matrix_test.c.o: examples/CMakeFiles/matrix_test.dir/flags.make
examples/CMakeFiles/matrix_test.dir/matrix_test.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/matrix_test.c
examples/CMakeFiles/matrix_test.dir/matrix_test.c.o: examples/CMakeFiles/matrix_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/matrix_test.dir/matrix_test.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/matrix_test.dir/matrix_test.c.o -MF CMakeFiles/matrix_test.dir/matrix_test.c.o.d -o CMakeFiles/matrix_test.dir/matrix_test.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/matrix_test.c

examples/CMakeFiles/matrix_test.dir/matrix_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/matrix_test.dir/matrix_test.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/matrix_test.c > CMakeFiles/matrix_test.dir/matrix_test.c.i

examples/CMakeFiles/matrix_test.dir/matrix_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/matrix_test.dir/matrix_test.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/matrix_test.c -o CMakeFiles/matrix_test.dir/matrix_test.c.s

examples/CMakeFiles/matrix_test.dir/tests_utils.c.o: examples/CMakeFiles/matrix_test.dir/flags.make
examples/CMakeFiles/matrix_test.dir/tests_utils.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/tests_utils.c
examples/CMakeFiles/matrix_test.dir/tests_utils.c.o: examples/CMakeFiles/matrix_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/matrix_test.dir/tests_utils.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/matrix_test.dir/tests_utils.c.o -MF CMakeFiles/matrix_test.dir/tests_utils.c.o.d -o CMakeFiles/matrix_test.dir/tests_utils.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/tests_utils.c

examples/CMakeFiles/matrix_test.dir/tests_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/matrix_test.dir/tests_utils.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/tests_utils.c > CMakeFiles/matrix_test.dir/tests_utils.c.i

examples/CMakeFiles/matrix_test.dir/tests_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/matrix_test.dir/tests_utils.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples/tests_utils.c -o CMakeFiles/matrix_test.dir/tests_utils.c.s

# Object files for target matrix_test
matrix_test_OBJECTS = \
"CMakeFiles/matrix_test.dir/matrix_test.c.o" \
"CMakeFiles/matrix_test.dir/tests_utils.c.o"

# External object files for target matrix_test
matrix_test_EXTERNAL_OBJECTS =

examples/matrix_test: examples/CMakeFiles/matrix_test.dir/matrix_test.c.o
examples/matrix_test: examples/CMakeFiles/matrix_test.dir/tests_utils.c.o
examples/matrix_test: examples/CMakeFiles/matrix_test.dir/build.make
examples/matrix_test: src/libpnl.so.1.15.0
examples/matrix_test: /usr/lib/x86_64-linux-gnu/libblas.so
examples/matrix_test: /usr/lib/x86_64-linux-gnu/liblapack.so
examples/matrix_test: /usr/lib/x86_64-linux-gnu/libblas.so
examples/matrix_test: /usr/lib/x86_64-linux-gnu/liblapack.so
examples/matrix_test: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
examples/matrix_test: examples/CMakeFiles/matrix_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable matrix_test"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/matrix_test.dir/build: examples/matrix_test
.PHONY : examples/CMakeFiles/matrix_test.dir/build

examples/CMakeFiles/matrix_test.dir/clean:
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/matrix_test.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/matrix_test.dir/clean

examples/CMakeFiles/matrix_test.dir/depend:
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/examples /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/examples/CMakeFiles/matrix_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/matrix_test.dir/depend

