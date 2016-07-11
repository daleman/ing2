all: objects
	g++ *.o -g -o simulador

objects: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	g++ -c -Wno-return-local-addr -g -o $@ $^

clean:
	rm -f *.o simulador
