.PHONY: all, objects, clean

all: simulador

simulador: objects
	g++ *.o -g -std=gnu++1y -o simulador

objects: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp %.h
	g++ -c -g -std=gnu++1y -o $@ $<

clean:
	rm -f *.o simulador
