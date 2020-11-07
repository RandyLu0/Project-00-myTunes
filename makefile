all: main.o playlist.o playlistarray.o
        gcc -o program main.o playlist.o playlistarray.o

main.o: main.c playlist.h
        gcc -c main.c

playlist.o: playlist.c playlist.h
        gcc -c playlist.c

playlistarray.o: playlistarray.c playlistarray.h
        gcc -c playlistarray.c
run:
        ./program
clean:
        -rm *.o
