.PHONY: all, objects, clean

all: simulador

simulador: objects
	g++ *.o -g -o simulador

objects: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	g++ -c -g -o $@ $^

clean:
	rm -f *.o simulador
