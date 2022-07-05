# Variables
CC=g++
CFLAGS=-std=c++11 -Wall

BUILD_DIR    = ./build
SRC_DIR    = ./src
INCLUDE_DIR  = ./include

# Linux targets

linux: build-linux link-linux

linux-run: build-linux link-linux run-linux


build-linux:
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/main.cpp -o build/main.o
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/game/state.cpp -o build/state.o
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/game/game-state.cpp -o build/game-state.o
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/game/game.cpp -D LINUX -o build/game.o
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/instances/instance.cpp -o build/instance.o
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/instances/player.cpp -o build/player.o
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/collision/collision.cpp -o build/collision.o
	${CC} ${CFLAGS} -I libs/sfml-linux/include -I include -c src/instances/wall.cpp -o build/wall.o

link-linux:
	${CC} ${CFLAGS} build/*.o -o main -Llibs/sfml-linux/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

run-linux:
		export LD_LIBRARY_PATH=libs/sfml-linux/lib && ./main	


# Windows targets

win: build-win link-win

win-run: build-win link-win run-win


build-win:
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/main.cpp -o build/main.o
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/game/state.cpp -o build/state.o
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/game/game-state.cpp -o build/game-state.o
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/game/game.cpp -o build/game.o
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/instances/instance.cpp -o build/instance.o
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/instances/player.cpp -o build/player.o
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/instances/wall.cpp -o build/wall.o
	${CC} ${CFLAGS} -I libs/sfml-win/include -I include -c src/collision/collision.cpp -o build/collision.o

link-win:
	${CC} ${CFLAGS} build/main.o build/game.o build/state.o build/game-state.o build/instance.o build/player.o build/Wall.o -o libs/sfml-win/bin/main.exe -L libs/sfml-win/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

run-win:
	libs/sfml-win/bin/main.exe
