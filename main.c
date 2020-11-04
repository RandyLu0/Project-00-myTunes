#include <stdlib.h>
#include <stdio.h>
#include "playlist.h"
typedef struct playlist* p;
int main(){
    p p1 = new_playlist("Future","Life is Good");
    p1 = shuffle(p1);
    printf("%s\n",p1->name);
}
