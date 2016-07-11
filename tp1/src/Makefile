all: objects
	g++ *.o -o simulador

objects: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	g++ -c -Wno-return-local-addr -o $@ $^

clean:
	rm -f *.o simulador
