.PHONY: all clean

all: main.o Sort.o
	$(CXX) $(CXXFLAGS) -o lab4problem1 Sort.o main.o

main.o: main.cpp

Sort.o: Sort.cpp Sort.h

clean:
	rm -f main.o Sort.o
	rm -f lab4problem1
