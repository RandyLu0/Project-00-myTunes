#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "playlist.h"
#include "playlistarray.h"
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
	printf("\ntesting print for alphabetical order:\n");
    printf("printing all entries under 'a':\n");
    //print_alpha(lib,'a');
	printf("printing all entries under b:\n");
	//print_alpha(lib,'b');
	printf("\ntesting print for artists:\n");
	printf("printing for Abs:\n");
	//print_artist(lib,"Abs");
	printf("printing for artist not in the library:\n");
	//print_artist(lib,"NULL");
	printf("\ntesting print for library:\n");
	//print_library(lib);
	printf("\ntesting search_artist:\n");
	printf("searching for Abs:\n");
	struct playlist* art = search_artist(lib,"Abs");
	print_list(art);
	printf("searching for artist not in library:\n");
	art = search_artist(lib,"NULL");
	print_list(art);
	printf("\ntesting search_song:\n");
	printf("searching for Bob the Cat: Amazon\n");
	struct playlist* song = search_song(lib,"Bob the Cat","Amazon");
	print_item(song);
	printf("searching for song not in library:\n");
	song = search_song(lib,"NULL","NULL");
	print_item(song);

	printf("testing delete:\n");
	printf("deleting apples on the tree: AaA\n");
	delete(lib,"apple on the tree","AaA");
	//print_alpha(lib,'a');
	printf("\ndeleting song not in the library:\n");
    delete(lib,"NULL","NULL");
	//print_library(lib);
	printf("\ntesting shuffle:\n");
    shuffle(lib);
	printf("shuffling again\n");
	shuffle(lib);
	printf("\ntesting clear:\n");
	printf("clearing library...\n");
    clear(lib);
	printf("printing library after cleared:\n");
	//print_library(lib);

    return 0;
}
