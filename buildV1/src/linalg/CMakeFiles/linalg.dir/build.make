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
include src/linalg/CMakeFiles/linalg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/linalg/CMakeFiles/linalg.dir/compiler_depend.make

# Include the progress variables for this target.
include src/linalg/CMakeFiles/linalg.dir/progress.make

# Include the compile flags for this target's objects.
include src/linalg/CMakeFiles/linalg.dir/flags.make

src/linalg/CMakeFiles/linalg.dir/band_matrix.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/band_matrix.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/band_matrix.c
src/linalg/CMakeFiles/linalg.dir/band_matrix.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/linalg/CMakeFiles/linalg.dir/band_matrix.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/band_matrix.c.o -MF CMakeFiles/linalg.dir/band_matrix.c.o.d -o CMakeFiles/linalg.dir/band_matrix.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/band_matrix.c

src/linalg/CMakeFiles/linalg.dir/band_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/band_matrix.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/band_matrix.c > CMakeFiles/linalg.dir/band_matrix.c.i

src/linalg/CMakeFiles/linalg.dir/band_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/band_matrix.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/band_matrix.c -o CMakeFiles/linalg.dir/band_matrix.c.s

src/linalg/CMakeFiles/linalg.dir/dpstrf.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/dpstrf.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/dpstrf.c
src/linalg/CMakeFiles/linalg.dir/dpstrf.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/linalg/CMakeFiles/linalg.dir/dpstrf.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/dpstrf.c.o -MF CMakeFiles/linalg.dir/dpstrf.c.o.d -o CMakeFiles/linalg.dir/dpstrf.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/dpstrf.c

src/linalg/CMakeFiles/linalg.dir/dpstrf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/dpstrf.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/dpstrf.c > CMakeFiles/linalg.dir/dpstrf.c.i

src/linalg/CMakeFiles/linalg.dir/dpstrf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/dpstrf.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/dpstrf.c -o CMakeFiles/linalg.dir/dpstrf.c.s

src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/lapack-wrap.c
src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.o -MF CMakeFiles/linalg.dir/lapack-wrap.c.o.d -o CMakeFiles/linalg.dir/lapack-wrap.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/lapack-wrap.c

src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/lapack-wrap.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/lapack-wrap.c > CMakeFiles/linalg.dir/lapack-wrap.c.i

src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/lapack-wrap.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/lapack-wrap.c -o CMakeFiles/linalg.dir/lapack-wrap.c.s

src/linalg/CMakeFiles/linalg.dir/matrix.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/matrix.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/matrix.c
src/linalg/CMakeFiles/linalg.dir/matrix.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/linalg/CMakeFiles/linalg.dir/matrix.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/matrix.c.o -MF CMakeFiles/linalg.dir/matrix.c.o.d -o CMakeFiles/linalg.dir/matrix.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/matrix.c

src/linalg/CMakeFiles/linalg.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/matrix.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/matrix.c > CMakeFiles/linalg.dir/matrix.c.i

src/linalg/CMakeFiles/linalg.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/matrix.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/matrix.c -o CMakeFiles/linalg.dir/matrix.c.s

src/linalg/CMakeFiles/linalg.dir/perm.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/perm.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/perm.c
src/linalg/CMakeFiles/linalg.dir/perm.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/linalg/CMakeFiles/linalg.dir/perm.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/perm.c.o -MF CMakeFiles/linalg.dir/perm.c.o.d -o CMakeFiles/linalg.dir/perm.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/perm.c

src/linalg/CMakeFiles/linalg.dir/perm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/perm.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/perm.c > CMakeFiles/linalg.dir/perm.c.i

src/linalg/CMakeFiles/linalg.dir/perm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/perm.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/perm.c -o CMakeFiles/linalg.dir/perm.c.s

src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/solver_iterativ.c
src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.o -MF CMakeFiles/linalg.dir/solver_iterativ.c.o.d -o CMakeFiles/linalg.dir/solver_iterativ.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/solver_iterativ.c

src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/solver_iterativ.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/solver_iterativ.c > CMakeFiles/linalg.dir/solver_iterativ.c.i

src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/solver_iterativ.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/solver_iterativ.c -o CMakeFiles/linalg.dir/solver_iterativ.c.s

src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/sp_matrix.c
src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.o -MF CMakeFiles/linalg.dir/sp_matrix.c.o.d -o CMakeFiles/linalg.dir/sp_matrix.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/sp_matrix.c

src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/sp_matrix.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/sp_matrix.c > CMakeFiles/linalg.dir/sp_matrix.c.i

src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/sp_matrix.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/sp_matrix.c -o CMakeFiles/linalg.dir/sp_matrix.c.s

src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/tridiag_matrix.c
src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.o -MF CMakeFiles/linalg.dir/tridiag_matrix.c.o.d -o CMakeFiles/linalg.dir/tridiag_matrix.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/tridiag_matrix.c

src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/tridiag_matrix.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/tridiag_matrix.c > CMakeFiles/linalg.dir/tridiag_matrix.c.i

src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/tridiag_matrix.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/tridiag_matrix.c -o CMakeFiles/linalg.dir/tridiag_matrix.c.s

src/linalg/CMakeFiles/linalg.dir/vector.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/vector.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector.c
src/linalg/CMakeFiles/linalg.dir/vector.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/linalg/CMakeFiles/linalg.dir/vector.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/vector.c.o -MF CMakeFiles/linalg.dir/vector.c.o.d -o CMakeFiles/linalg.dir/vector.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector.c

src/linalg/CMakeFiles/linalg.dir/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/vector.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector.c > CMakeFiles/linalg.dir/vector.c.i

src/linalg/CMakeFiles/linalg.dir/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/vector.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector.c -o CMakeFiles/linalg.dir/vector.c.s

src/linalg/CMakeFiles/linalg.dir/vector_complex.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/vector_complex.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_complex.c
src/linalg/CMakeFiles/linalg.dir/vector_complex.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/linalg/CMakeFiles/linalg.dir/vector_complex.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/vector_complex.c.o -MF CMakeFiles/linalg.dir/vector_complex.c.o.d -o CMakeFiles/linalg.dir/vector_complex.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_complex.c

src/linalg/CMakeFiles/linalg.dir/vector_complex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/vector_complex.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_complex.c > CMakeFiles/linalg.dir/vector_complex.c.i

src/linalg/CMakeFiles/linalg.dir/vector_complex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/vector_complex.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_complex.c -o CMakeFiles/linalg.dir/vector_complex.c.s

src/linalg/CMakeFiles/linalg.dir/vector_double.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/vector_double.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_double.c
src/linalg/CMakeFiles/linalg.dir/vector_double.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/linalg/CMakeFiles/linalg.dir/vector_double.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/vector_double.c.o -MF CMakeFiles/linalg.dir/vector_double.c.o.d -o CMakeFiles/linalg.dir/vector_double.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_double.c

src/linalg/CMakeFiles/linalg.dir/vector_double.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/vector_double.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_double.c > CMakeFiles/linalg.dir/vector_double.c.i

src/linalg/CMakeFiles/linalg.dir/vector_double.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/vector_double.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/vector_double.c -o CMakeFiles/linalg.dir/vector_double.c.s

src/linalg/CMakeFiles/linalg.dir/zpstrf.c.o: src/linalg/CMakeFiles/linalg.dir/flags.make
src/linalg/CMakeFiles/linalg.dir/zpstrf.c.o: /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/zpstrf.c
src/linalg/CMakeFiles/linalg.dir/zpstrf.c.o: src/linalg/CMakeFiles/linalg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/linalg/CMakeFiles/linalg.dir/zpstrf.c.o"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/linalg/CMakeFiles/linalg.dir/zpstrf.c.o -MF CMakeFiles/linalg.dir/zpstrf.c.o.d -o CMakeFiles/linalg.dir/zpstrf.c.o -c /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/zpstrf.c

src/linalg/CMakeFiles/linalg.dir/zpstrf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linalg.dir/zpstrf.c.i"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/zpstrf.c > CMakeFiles/linalg.dir/zpstrf.c.i

src/linalg/CMakeFiles/linalg.dir/zpstrf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linalg.dir/zpstrf.c.s"
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg/zpstrf.c -o CMakeFiles/linalg.dir/zpstrf.c.s

linalg: src/linalg/CMakeFiles/linalg.dir/band_matrix.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/dpstrf.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/lapack-wrap.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/matrix.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/perm.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/solver_iterativ.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/sp_matrix.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/tridiag_matrix.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/vector.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/vector_complex.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/vector_double.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/zpstrf.c.o
linalg: src/linalg/CMakeFiles/linalg.dir/build.make
.PHONY : linalg

# Rule to build all files generated by this target.
src/linalg/CMakeFiles/linalg.dir/build: linalg
.PHONY : src/linalg/CMakeFiles/linalg.dir/build

src/linalg/CMakeFiles/linalg.dir/clean:
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg && $(CMAKE_COMMAND) -P CMakeFiles/linalg.dir/cmake_clean.cmake
.PHONY : src/linalg/CMakeFiles/linalg.dir/clean

src/linalg/CMakeFiles/linalg.dir/depend:
	cd /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/src/linalg /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg /mnt/c/Users/user/Desktop/3eme_Annee/Projet_de_couverture_de_produits_derives/code/pnl/build/src/linalg/CMakeFiles/linalg.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/linalg/CMakeFiles/linalg.dir/depend

