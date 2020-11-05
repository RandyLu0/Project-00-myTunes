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

struct playlist* insert_front(struct playlist *s, char* n, char* a){

        struct playlist * nu = new_playlist(n,a);
        nu->next=s;

        return nu;
}

struct playlist* insert_end(struct playlist* s, char* n, char* a){

        struct playlist *first=s;

        struct playlist * nu = new_playlist(n,a);

        while(1){
                if(s->next==NULL){
                        s->next=nu;
                        break;
                }
                else
                        s=s->next;
        }

        return first;
}

struct playlist* insert_alpha(struct playlist * s, char *n, char*a){
        struct playlist * nu = new_playlist(n,a);

        if(s==NULL){
                s=nu;
                return nu;
        }

        if(strcmp(nu->artist, s->artist)<0){
                nu->next = s;
                return nu;
        }

        struct playlist * first = s;
        struct playlist * previous = NULL;
        while(1){
                if((s->next==NULL) && (strcmp(nu->artist,s->artist)!=0)){
                        s->next= nu;
                        return first;
                }
                if(strcmp(nu->artist,s->artist)>0 && strcmp(nu->artist,s->next->artist)<0){
                        nu->next = s->next;
                        s->next= nu;
                        return first;
                }

                if(strcmp(nu->artist,s->artist)==0){

                        if((strcmp(nu->name,s->name)<0) && (previous !=NULL)){
                                nu->next=s;
                                previous->next=nu;
                                return first;
                        }
                        if((strcmp(nu->name,s->name)<0) && (previous == NULL)){
                                nu->next=s;
                                return nu;
                        }
                        while(1){
                                if(s->next==NULL){
                                        s->next=nu;
                                        return first;
                                }
                                if(strcmp(s->next->artist,nu->artist)!=0){
                                        nu->next=s->next;
                                        s->next=nu;
                                        return first;
                                }
                                if(strcmp(nu->name,s->name)>0 && strcmp(nu->name,s->next->name)<0){
                                        nu->next=s->next;
                                        s->next=nu;
                                        return first;
                                }
                                previous=s;
                                s=s->next;
                        }
                }
                previous=s;
                s=s->next;
        }

        return first;
}

