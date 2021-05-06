all: compile link erase run

obj: link erase run

compile:
	g++ -c *.cpp

link:
	g++ *.o -o game -lsfml-graphics -lsfml-window -lsfml-system

erase:
	rm -f *.o

run:
	./game
	rm -f game