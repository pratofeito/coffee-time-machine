# Linux targets

linux: build-linux link-linux

linux-run: build-linux link-linux run-linux


build-linux:
	g++ -I libs/sfml-linux/include -c src/main.cpp -o build/main.o

link-linux:
	g++ build/main.o -o main -L libs/sfml-linux/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

run-linux:
	./main


# Windows targets

win: build-win link-win

win-run: build-win link-win run-win


build-win:
	g++ -I libs/sfml-win/include -c src/main.cpp -o build/main.o

link-win:
	g++ build/main.o -o libs/sfml-win/bin/main.exe -L libs/sfml-win/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

run-win:
	libs/sfml-win/bin/main.exe
