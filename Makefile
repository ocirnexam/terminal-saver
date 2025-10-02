terminal-saver: build/main.o build/scene.o
	mkdir -p build
	cp src/sprites.dat build/sprites.dat
	gcc -o build/terminal-saver build/main.o build/scene.o
	chmod +x build/terminal-saver

build/main.o: src/main.c
	mkdir -p build
	gcc -c src/main.c -o build/main.o

build/scene.o: src/scene/scene.c
	gcc -c src/scene/scene.c -o build/scene.o

clean:
	rm -rf build

install: build/terminal-saver
	mkdir -p /usr/share/terminal-saver
	cp build/terminal-saver /bin/terminal-saver
	cp src/sprites.dat /usr/share/terminal-saver/sprites.dat
	