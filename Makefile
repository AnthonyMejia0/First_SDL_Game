debug:
	g++ -c src/*.cpp -std=c++14 -I include && g++ *o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main

clean:
	rm -f *.o bin/debug/main