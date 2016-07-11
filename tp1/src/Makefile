all: objects
	g++ *.o -std=gnu++14 -o simulador

objects: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	g++ -c -Wno-return-local-addr -std=gnu++14 -o $@ $^

clean:
	rm -f *.o simulador
