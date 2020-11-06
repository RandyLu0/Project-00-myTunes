#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "playlist.h"
typedef struct playlist* p;

int main(){ 
    srand(time(NULL));
    p s;
    struct playlist* s2 = NULL;
    s2 = insert_front(s2, "Imperfect","Child");
    s2 = insert_alpha(s2, "DNA and RNA","SHS");
    s2 = insert_alpha(s2, "Happy Birthday","Home");
    s2 = insert_alpha(s2, "Let's Fly","Disney");
    s2 = insert_alpha(s2, "What","Child");
    s2 = insert_alpha(s2, "New World","USA");
    s2 = insert_alpha(s2, "Why not ABC","XYZ");
    s2 = insert_alpha(s2, "Crazy Crazy","SHS");
    s2 = insert_end(s2, "Popping","Child");
    printf("LINKED LIST TESTS\n");
    printf("\n");
    printf("printing list:\n");
    print_list(s2);
    printf("\n");
    printf("printing node:\n");
    print_item(s2);
    printf("\n");
    printf("\n");    
    printf("testing find_song:\n");
    s = find_song(s2,"New World","USA");
    printf("looking for New World: USA\n");
    print_list(s);
    printf("looking for song not in the playlist:\n");
    s = find_song(s2,"NULL","NULL");
    print_list(s);
    printf("\n");
    printf("testing find_artist:\n");
    s = find_artist(s2,"Child");
    printf("looking for Child:\n");
    print_list(s);
    printf("looking for artist not in the playlist:\n");
    s = find_artist(s2,"NULL");
    print_list(s);
    printf("\n");
    printf("testing random:\n");
    s = ran(s2);
    print_list(s);
    printf("testing again:\n");
    s = ran(s2);
    print_list(s);
    printf("\n");
    printf("testing remove:\n");
    s = remove_song(s2,"Crazy Crazy","SHS");
    printf("removing SHS: Crazy Crazy\n");
    print_list(s);
    s = remove_song(s2,"NULL","NULL");
    printf("removing song not in the playlist:\n");
    print_list(s);
    printf("\n");
    printf("testing free_list:\n");
    s2 = free_playlist(s2);
    printf("freeing list...\n");
    printf("printing list after freed:\n");
    print_list(s2);
    printf("\n");
    printf("LIBRARY TESTS\n");

    return 0;
}
