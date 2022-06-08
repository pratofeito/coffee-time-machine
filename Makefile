all: build link

build:
	g++ -c src/main.cpp -o build/main.o

link:
	g++ build/main.o -o main -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

