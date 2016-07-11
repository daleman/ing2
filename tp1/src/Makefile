all: objects
	g++ *.o -g -Wall -Wextra -o simulador

objects: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	g++ -c -g -Wall -Wextra -o $@ $^

clean:
	rm -f *.o simulador
