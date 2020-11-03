all: main.o playlist.o 
	gcc -o program main.o playlist.o 
main.o: main.c playlist.h
	gcc -c main.c 
myTunes.o: playlist.c playlist.h
	gcc -c playlist.c 
run:
	./program
clean:
	-rm *.o

