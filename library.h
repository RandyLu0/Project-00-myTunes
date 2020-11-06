#ifndef LIBRARY_H
#define LIBRARY_H

struct playlist{
  char name[100];
  char artist[100];
  struct playlist* next;
};

struct playlist* new_playlist(char* n, char* a);
struct playlist* add_playlist(struct playlist* old, struct* playlist new);
struct playlist* search_song(struct playlist* s, char* n, char* a);
struct playlist* search_artist(struct playlist* s, char* a);
void print_alpha(struct playlist* s, char* letter);
void print_artist(struct playlist* s, char* a);
void print_library(struct playlist* s);
void shuffle(struct playlist* s);
void delete(struct playlist* s, char* s, char* a);
void clear(struct playlist* s);

#endif
