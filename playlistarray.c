#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "playlistarray.h"
#include "playlist.h"
#include <string.h>


// a-z 97-122
// A-Z 65-90
struct playlist* add_playlist(struct playlist ** lib, char* n, char* a){

        char first_letter =((lib[0])->artist)[0];
        int i=-1;

        if(first_letter-'a' >= 0 && first_letter-'a' <= 25){
                i = first_letter-'a';
        }
        else
                if(first_letter-'A' >= 0 && first_letter-'A' <= 25){
                        i = first_letter-'A';
                }
        else
                i=27;

        return insert_alpha(lib[i],n,a);

}

struct playlist* search_song(struct playlist ** lib, char* n, char* a){

        char first_letter =((lib[0])->artist)[0];
        int i=-1;

        if(first_letter-'a' >= 0 && first_letter-'a' <= 25){
                i = first_letter-'a';
        }
        else
                if(first_letter-'A' >= 0 && first_letter-'A' <= 25){
                        i = first_letter-'A';
                }
        else
                i=27;

        struct playlist* node = lib[i];
        while(1){
                if(strcmp(node->name,n)==0 && strcmp(node->artist,a)==0){
                        return node;
                }
                node=node->next;
        }

        return NULL;
}


struct playlist* search_artist(struct playlist ** lib, char* a){


        char first_letter =((lib[0])->artist)[0];
        int i=-1;

        if(first_letter-'a' >= 0 && first_letter-'a' <= 25){
                i = first_letter-'a';
        }
        else
                if(first_letter-'A' >= 0 && first_letter-'A' <= 25){
                        i = first_letter-'A';
                }
        else
                i=27;

        struct playlist* node = lib[i];
        while(1){
                if(strcmp(node->artist,a)==0){
                        return node;
                }
                node=node->next;
        }

        return NULL;
}

void print_alpha(struct playlist ** lib, char letter){
  printf("%c list\n", letter);
  int i;
  for (i = 0; ((lib[i])->artist)[0] - letter <= 0; i++){
    if (((lib[i])->artist)[0] == letter)
      printf("%s: %s | ", lib[i]->artist, lib[i]->name);
  }
  printf("none found\n");
}

void print_artist(struct playlist ** lib, char* a){
  printf("looking for [%s]", a);
  struct playlist ** list = lib;
  int i;
  for (i = 0; ((list[i])->artist) - a <= 0 ; i++){
    if (strcmp((list[i])->artist, a) == 0)
      printf("artist found! %s: %s | ", list[i]->artist, lib[i]->name);
  }
  printf("artist not found\n");
}

void print_library(struct playlist ** lib){
  char first_letter = ((lib[0])->artist)[0];
  printf("%c list\n", first_letter);
  print_alpha(lib, first_letter);

  int i;
  for (i = 1; lib[i]; i++){
    if (((lib[i])->artist)[0] > ((lib[i-1])->artist)[0]){
      printf("%c list\n", ((lib[i])->artist)[0]);
      print_alpha(lib,((lib[i])->artist)[0]);
    }
  }
}
