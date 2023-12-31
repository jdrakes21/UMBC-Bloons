CXX = g++
CXXFLAGS = -Wall -g
OBJECTS = Game.o Bloon.o Monkey.o Basic.o Bomb.o Dart.o Boomerang.o
IODIR =../../proj4_IO

proj04: $(OBJECTS) proj4.cpp
	$(CXX) $(CXXFLAGS) $(OBJECTS) proj4.cpp -o proj04

Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Basic.o: Basic.cpp Basic.h Bloon.o
	$(CXX) $(CXXFLAGS) -c Basic.cpp

Bomb.o: Bomb.cpp Bomb.h Monkey.o
	$(CXX) $(CXXFLAGS) -c Bomb.cpp

Dart.o: Dart.cpp Dart.h Monkey.o
	$(CXX) $(CXXFLAGS) -c Dart.cpp

Boomerang.o: Boomerang.h Boomerang.cpp Monkey.o
	$(CXX) $(CXXFLAGS) -c Boomerang.cpp

Monkey.o: Monkey.cpp Monkey.h
	$(CXX) $(CXXFLAGS) -c Monkey.cpp

Bloon.o: Bloon.cpp Bloon.h
	$(CXX) $(CXXFLAGS) -c Bloon.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj04

val:
	valgrind ./proj04

debug:
	gdb gdbarg1 --args ./proj04

student:
	cp Bloon.h Basic.h Monkey.h Dart.h Boomerang.h Bomb.h Game.h proj4_sample1.txt proj4.cpp makefile ~/jdixon/pub/cs202/proj4
