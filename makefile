all: main.o myTunes.o 
	gcc -o program main.o myTunes.o 
main.o: main.c myTunes.h
	gcc -c main.c 
myTunes.o: myTunes.c myTunes.h
	gcc -c myTunes.c 
run:
	./program
clean:
	-rm *.o

