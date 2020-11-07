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

struct playlist* search_song(struct playlist* s, char* n, char* a);



struct playlist* search_artist(struct playlist* s, char* a);
