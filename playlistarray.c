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
                if(node->next==NULL)
                        break;
                else
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
                if(node->next==NULL)
                        break;
                else
                        node=node->next;
        }

        return NULL;
}

void print_alpha(struct playlist ** lib, char letter){
  printf("%c list\n", letter);
  int index = letter - 'a';
  struct playlist * find = lib[index];
  if (!find)
    printf("none found\n");
  else while (find){
    printf("%s: %s | ", find->artist, find->name);
    find = find->next;
  }
}

void print_artist(struct playlist ** lib, char* a){
  printf("looking for [%s]", a);
  struct playlist * find = lib[a[0] - 'a'];
  int count = 0;
  while(find){
    if (strcmp(find->artist, a) == 0){
      printf(" %s: %s | ", find->artist, find->name);
      count++;
    }
  find = find->next;
  }
  if (count == 0)
    printf("artist not found\n");
}

void print_library(struct playlist ** lib){
  int i;
  for (i = 0; i < 27; i++){
    if (lib[i]){
      print_alpha(lib, (lib[i]->artist)[0]);
	  printf("\n");
	}
  }
  
}

void clear(struct playlist** lib){
	int i;
	for(i = 0; i < 27; i++){
		lib[i] = free_playlist(lib[i]);
    }
} 

void delete(struct playlist ** lib, char* n, char* a){
	int i;
	for(i = 0; i < 27; i++){
		if(lib[i]){
			remove_song(lib[i],n,a);
		}
	}
} 

void shuffle(struct playlist** lib){
	int i;
	struct playlist* shuff;
	for(i = 0; i < 27; i++){
		if(lib[i]){
			shuff = ran(lib[i]);
			print_list(shuff);
		}
	}
}
struct playlist** init(){
	struct playlist** lib;
	lib = calloc(27,sizeof(struct playlist));
	int i;
	for(i = 0; i < 27; i++){
		lib[i] = NULL;
	}
	return lib;
}
