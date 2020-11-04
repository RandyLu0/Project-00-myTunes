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

int len(struct playlist* s){
    int n = 0;
    while(s){
        n++;
        s = s->next;
    }
    return n;
}

struct playlist* shuffle(struct playlist* s){
    int mod = len(s);
    srand(time(NULL));
    int r = rand() % mod;
    struct playlist* p = s;
    while(r){
        r--;
        p = p->next;
    }
    return p;
}

struct playlist* remove_song(struct playlist* s, char* n, char* a){
    struct playlist *h = s;
    if(!(strcmp(s->artist,a) || strcmp(s->name,n))){
        h = s->next;
        return h;
    }
    while(s->next){
        if(!(strcmp(s->next->artist,a) || strcmp(s->next->name,n))){
            s->next = s->next->next;
            return h;
        }
        s = s->next;
    }
    return h;
}
struct playlist* free_playlist(struct playlist* s){
    struct playlist *h;
    while(h){
        h = s->next;
        free(s);
        s = h;
    }
    return h;
}