#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "playlist.h"
typedef struct playlist* p;

int main(){ 
    srand(time(NULL));
    
  /*   struct playlist* song1 = NULL;
    song1 = insert_front(song1, "Let's Fly","Disney");
    song1 = insert_front(song1, "What","Child");
    song1 = insert_end(song1, "Crazy Crazy","SHS");
    song1 = insert_end(song1, "Popping","Child");
 */
/*     printf("TEST 1\n");
    print_list(song1);
    free_playlist(song1); */

    struct playlist* song2 = NULL;
    song2 = insert_alpha(song2, "Imperfect","Child");
    song2 = insert_alpha(song2, "DNA and RNA","SHS");
    song2 = insert_alpha(song2, "Happy Birthday","Home");
    song2 = insert_alpha(song2, "Let's Fly","Disney");
    song2 = insert_alpha(song2, "What","Child");
    song2 = insert_alpha(song2, "New World","USA");
    song2 = insert_alpha(song2, "Why not ABC","XYZ");
    song2 = insert_alpha(song2, "Crazy Crazy","SHS");
    song2 = insert_alpha(song2, "Popping","Child");
    printf(" TEST 2\n");
    print_list(song2);
    free_playlist(song2);

    return 0;
}
