#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "playlist.h"
#include "playlistarray.h"
typedef struct playlist* p;

int main(){ 
    srand(time(NULL));

   /*  p s;
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
    printf("\nprinting list:\n");
    print_list(s2);
    printf("\nprinting node:\n");
    print_item(s2);
    printf("\n\ntesting find_song:\n");
    s = find_song(s2,"New World","USA");
    printf("looking for New World: USA\n");
    print_list(s);
    printf("looking for song not in the playlist:\n");
    s = find_song(s2,"NULL","NULL");
    print_list(s);
    printf("\ntesting find_artist:\n");
    s = find_artist(s2,"Child");
    printf("looking for Child:\n");
    print_list(s);
    printf("looking for artist not in the playlist:\n");
    s = find_artist(s2,"NULL");
    print_list(s);
    printf("\ntesting random:\n");
    s = ran(s2);
    print_list(s);
    printf("testing again:\n");
    s = ran(s2);
    print_list(s);
    printf("\ntesting remove:\n");
    s = remove_song(s2,"Crazy Crazy","SHS");
    printf("removing SHS: Crazy Crazy\n");
    print_list(s);
    s = remove_song(s2,"NULL","NULL");
    printf("removing song not in the playlist:\n");
    print_list(s);
    printf("\ntesting free_list:\n");
    s2 = free_playlist(s2);
    printf("freeing list...\n");
    printf("printing list after freed:\n");
    print_list(s2);
 */
    struct playlist** lib = init();

    struct playlist* s1 = NULL;
    s1 = insert_alpha(s1, "Imperfect","Ahild");
    s1 = insert_alpha(s1, "DNA and RNA","Abs");
    s1 = insert_alpha(s1, "Happy Birthday","Aome");
    s1 = insert_alpha(s1, "Let's Fly","Aisney");
    s1 = insert_alpha(s1, "What","Ahild");
    s1 = insert_alpha(s1, "New World","Abs");
    s1 = insert_alpha(s1, "Why not ABC","Abs");
    s1 = insert_alpha(s1, "Crazy Crazy","Abs");
    s1 = insert_alpha(s1, "Popping","Ahild");
    lib[0]= s1;
    lib[0] = add_playlist(lib,"apple on the tree","AaA");
    lib[0] = add_playlist(lib,"Bob the Cat","Amazon");
    printf("\nLIBRARY TESTS\n");
    printf("printing all entries under 'a':\n");
    //print_alpha(lib,'a');
    
    
    /* struct playlist* found = search_song(lib,"apple on the tree","AaA");
    printf("\ntesting search_song:\n");
    printf("looking for apple on the tree: AaA\n");
    print_item(found);
 */
    
    delete(lib,"NULL","NULL");
    print_list(lib[0]);
    //delete(lib,"apple on the tree","AaA");
   //print_library(lib);
    shuffle(lib);
    clear(lib);
    //print_library(lib);

   /*  printf("looking for song not in library:\n");
    found = search_song(lib,"NULL","NULL"); */



    /* found = search_artist(lib,"Ndsdada");
    printf("\nTesting the search_artist function\n");
    //print_item(found); */
    
    return 0;
}
