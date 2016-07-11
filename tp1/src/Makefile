all: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	g++ -c -Wno-return-local-addr -o $@ $^

clean:
	rm -f *.o
