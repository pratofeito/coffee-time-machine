win: build-win link-win run-win

build-win:
	g++ -I libs/sfml-win/include -c src/main.cpp -o build/main.o

link-win:
	g++ build/main.o -o libs/sfml-win/bin/main.exe -L libs/sfml-win/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

run-win:
	libs/sfml-win/bin/main.exe
