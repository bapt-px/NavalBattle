# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1"

# Include any dependencies generated for this target.
include CMakeFiles/Battleship.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Battleship.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Battleship.dir/flags.make

CMakeFiles/Battleship.dir/main.c.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Battleship.dir/main.c.obj"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Battleship.dir\main.c.obj   -c "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\main.c"

CMakeFiles/Battleship.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Battleship.dir/main.c.i"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\main.c" > CMakeFiles\Battleship.dir\main.c.i

CMakeFiles/Battleship.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Battleship.dir/main.c.s"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\main.c" -o CMakeFiles\Battleship.dir\main.c.s

CMakeFiles/Battleship.dir/fct/fct.c.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/fct/fct.c.obj: ../fct/fct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Battleship.dir/fct/fct.c.obj"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Battleship.dir\fct\fct.c.obj   -c "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\fct\fct.c"

CMakeFiles/Battleship.dir/fct/fct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Battleship.dir/fct/fct.c.i"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\fct\fct.c" > CMakeFiles\Battleship.dir\fct\fct.c.i

CMakeFiles/Battleship.dir/fct/fct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Battleship.dir/fct/fct.c.s"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\fct\fct.c" -o CMakeFiles\Battleship.dir\fct\fct.c.s

CMakeFiles/Battleship.dir/Game/Game.c.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/Game/Game.c.obj: ../Game/Game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Battleship.dir/Game/Game.c.obj"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Battleship.dir\Game\Game.c.obj   -c "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Game\Game.c"

CMakeFiles/Battleship.dir/Game/Game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Battleship.dir/Game/Game.c.i"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Game\Game.c" > CMakeFiles\Battleship.dir\Game\Game.c.i

CMakeFiles/Battleship.dir/Game/Game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Battleship.dir/Game/Game.c.s"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Game\Game.c" -o CMakeFiles\Battleship.dir\Game\Game.c.s

CMakeFiles/Battleship.dir/Ship/Ship.c.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/Ship/Ship.c.obj: ../Ship/Ship.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Battleship.dir/Ship/Ship.c.obj"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Battleship.dir\Ship\Ship.c.obj   -c "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Ship\Ship.c"

CMakeFiles/Battleship.dir/Ship/Ship.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Battleship.dir/Ship/Ship.c.i"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Ship\Ship.c" > CMakeFiles\Battleship.dir\Ship\Ship.c.i

CMakeFiles/Battleship.dir/Ship/Ship.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Battleship.dir/Ship/Ship.c.s"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Ship\Ship.c" -o CMakeFiles\Battleship.dir\Ship\Ship.c.s

CMakeFiles/Battleship.dir/Board/Board.c.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/Board/Board.c.obj: ../Board/Board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Battleship.dir/Board/Board.c.obj"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Battleship.dir\Board\Board.c.obj   -c "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Board\Board.c"

CMakeFiles/Battleship.dir/Board/Board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Battleship.dir/Board/Board.c.i"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Board\Board.c" > CMakeFiles\Battleship.dir\Board\Board.c.i

CMakeFiles/Battleship.dir/Board/Board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Battleship.dir/Board/Board.c.s"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\Board\Board.c" -o CMakeFiles\Battleship.dir\Board\Board.c.s

CMakeFiles/Battleship.dir/IA/IA.c.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/IA/IA.c.obj: ../IA/IA.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Battleship.dir/IA/IA.c.obj"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Battleship.dir\IA\IA.c.obj   -c "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\IA\IA.c"

CMakeFiles/Battleship.dir/IA/IA.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Battleship.dir/IA/IA.c.i"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\IA\IA.c" > CMakeFiles\Battleship.dir\IA\IA.c.i

CMakeFiles/Battleship.dir/IA/IA.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Battleship.dir/IA/IA.c.s"
	C:\cygwin64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\IA\IA.c" -o CMakeFiles\Battleship.dir\IA\IA.c.s

# Object files for target Battleship
Battleship_OBJECTS = \
"CMakeFiles/Battleship.dir/main.c.obj" \
"CMakeFiles/Battleship.dir/fct/fct.c.obj" \
"CMakeFiles/Battleship.dir/Game/Game.c.obj" \
"CMakeFiles/Battleship.dir/Ship/Ship.c.obj" \
"CMakeFiles/Battleship.dir/Board/Board.c.obj" \
"CMakeFiles/Battleship.dir/IA/IA.c.obj"

# External object files for target Battleship
Battleship_EXTERNAL_OBJECTS =

Battleship.exe: CMakeFiles/Battleship.dir/main.c.obj
Battleship.exe: CMakeFiles/Battleship.dir/fct/fct.c.obj
Battleship.exe: CMakeFiles/Battleship.dir/Game/Game.c.obj
Battleship.exe: CMakeFiles/Battleship.dir/Ship/Ship.c.obj
Battleship.exe: CMakeFiles/Battleship.dir/Board/Board.c.obj
Battleship.exe: CMakeFiles/Battleship.dir/IA/IA.c.obj
Battleship.exe: CMakeFiles/Battleship.dir/build.make
Battleship.exe: CMakeFiles/Battleship.dir/objects1.rsp
Battleship.exe: CMakeFiles/Battleship.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Battleship.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Battleship.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Battleship.dir/build: Battleship.exe

.PHONY : CMakeFiles/Battleship.dir/build

CMakeFiles/Battleship.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Battleship.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Battleship.dir/clean

CMakeFiles/Battleship.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet" "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet" "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1" "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1" "C:\Users\Baptiste\Documents\Projet M1\System and network\Projet\build1\CMakeFiles\Battleship.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Battleship.dir/depend

