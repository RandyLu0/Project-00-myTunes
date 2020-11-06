#ifndef PLAYLIST_H
#define PLAYLIST_H
 
struct playlist{
  char name[100];
  char artist[100];
  struct playlist *next;
};

void print_item(struct playlist *);
void print_list(struct playlist *);

struct playlist* new_playlist(char* n, char* a);
struct playlist* insert_front(struct playlist* s, char* n, char* a);
struct playlist* insert_end(struct playlist* s, char* n, char* a);
struct playlist* insert_alpha(struct playlist* s, char* n, char* a);
struct playlist* find_song(struct playlist* s, char* n, char* a);
struct playlist* find_artist(struct playlist* s, char* a);
struct playlist* ran(struct playlist* s);
struct playlist* remove_song(struct playlist* s, char* n, char* a);
struct playlist* free_playlist(struct playlist* s);

int len(struct playlist* s);

#endif
