#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include <string.h>

struct playlist* new_playlist(char* n, char* a){
    struct playlist *pl;
    pl = malloc(sizeof(struct playlist));
    strcpy(pl->name, n);
    strcpy(pl->artist, a);
    pl->next = NULL;
    return pl;
}

void print(struct playlist* s){
  while (s){
    printf("\"%s\" - %s\n", s->name, s->artist);
    s = s->next;
  }
}

struct playlist* find_song(struct playlist* s, char* n, char* a){
  struct playlist* find = s;
  while (find != NULL){
    if (strcmp(find->name, n) == 0 && strcmp(find->artist, a) == 0)
      return find;
    find = find->next;
  }
  return NULL;
}

struct playlist* find_artist(struct playlist* s, char* a){
  struct playlist* find = s;
  while (find != NULL){
    if (strcmp(find->artist, a) == 0)
      return find;
    find = find->next;
  }
  return NULL;
}
