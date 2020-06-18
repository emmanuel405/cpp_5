#!make -f

CXX=g++
# CXXFLAGS=-std=c++03

HEADERS=range.hpp accumulate.hpp filterfalse.hpp compress.hpp
OBJECTS=

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) --compile $< -o $@

clean:
	rm -f *.o demo test a.out