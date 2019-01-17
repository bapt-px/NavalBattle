cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(Battleship)

# Crée des variables avec les fichiers à compiler
set(SRCS
    main.c
    fct/fct.c
	Game/Game.c
	Ship/Ship.c
	Board/Board.C
	IA/IA.c
    )
    
set(HEADERS
	fct/fct.h
	Game/Game.h
	Ship/Ship.h
	Ship/Position.h
	Board/Board.h
	IA/IA.h
	)

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(Battleship ${SRCS} ${HEADERS})