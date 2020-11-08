#ifndef PLAYLISTARRAY_H
#define PLAYLISTARRAY_H

struct playlist;

struct playlist* add_playlist(struct playlist ** lib, char*n , char *a);
struct playlist* search_song(struct playlist** lib, char* n, char* a);
struct playlist* search_artist(struct playlist** lib, char* a);

void print_alpha(struct playlist ** lib, char letter);
void print_artist(struct playlist ** lib, char* a);
void print_library(struct playlist ** lib);
void shuffle(struct playlist ** lib);
void delete(struct playlist ** lib, char* n, char* a);
void clear(struct playlist ** lib);

#endif
