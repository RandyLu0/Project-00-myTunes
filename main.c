#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "playlist.h"
#include "playlistarray.h"

int main(){ 
	srand(time(NULL));
/* 
   	struct playlist* s;
    struct playlist* s2 = NULL;
    s2 = insert_front(s2, "imperfect","child");
    s2 = insert_alpha(s2, "dna and rna","shs");
    s2 = insert_alpha(s2, "happy birthday","home");
    s2 = insert_alpha(s2, "let's fly","disney");
    s2 = insert_alpha(s2, "what","child");
    s2 = insert_alpha(s2, "new world","usa");
    s2 = insert_alpha(s2, "why not abc","xyz");
    s2 = insert_alpha(s2, "crazy crazy","shs");
    s2 = insert_end(s2, "popping","child");
    printf("LINKED LIST TESTS\n");
    printf("\nprinting list:\n");
    print_list(s2);
    printf("\nprinting node:\n");
    print_item(s2);
    printf("\n\ntesting find_song:\n");
    s = find_song(s2,"new world","usa");
    printf("looking for new world: usa\n");
    print_list(s);
    printf("looking for song not in the playlist:\n");
    s = find_song(s2,"NULL","NULL");
    print_list(s);
    printf("\ntesting find_artist:\n");
    s = find_artist(s2,"child");
    printf("looking for child:\n");
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
    s = remove_song(s2,"crazy crazy","shs");
    printf("removing shs: crazy crazy\n");
    print_list(s);
    s = remove_song(s2,"NULL","NULL");
    printf("removing song not in the playlist:\n");
    print_list(s);
    printf("\ntesting free_list:\n");
    s2 = free_playlist(s2);
    printf("freeing list...\n");
    printf("printing list after freed:\n");
    print_list(s2); */

    struct playlist** lib = init();

    struct playlist* s1 = NULL;
    struct playlist* s4 = NULL;
    struct playlist* s5 = NULL;
    
    s4 = insert_alpha(s4, "imperfect","child");
    s1 = insert_alpha(s1, "dna and rna","abs");
    s1 = insert_alpha(s1, "happy birthday","aome");
    s5 = insert_alpha(s5, "let's fly","disney");
    s4 = insert_alpha(s4, "what","child");
    s1 = insert_alpha(s1, "new world","abs");
    s1 = insert_alpha(s1, "why not abc","abs");
    s1 = insert_alpha(s1, "crazy crazy","abs");
    s4 = insert_alpha(s4, "popping","child");
    lib[0]= s1;
    lib[0] = add_playlist(lib,"apple on the tree","aaa");
    lib[0] = add_playlist(lib,"bob the cat","amazon");
    lib[2] = s4;
    lib[3] = s5;
    printf("\nLIBRARY TESTS\n");
	printf("\ntesting print for alphabetical order:\n");
    printf("printing all entries under 'a':\n");
    print_alpha(lib,'a');
	printf("\nprinting all entries under 'b':\n");
	print_alpha(lib,'b');
	printf("\ntesting print for artists:\n");
	printf("printing for abs:\n");
	print_artist(lib,"abs");
	printf("\nprinting for artist not in the library:\n");
	print_artist(lib,"NULL");
	printf("\ntesting print for library:\n");
	print_library(lib);
	printf("\n\ntesting search_artist:\n");
	printf("searching for abs:\n");
	struct playlist* art = search_artist(lib,"abs");
	print_list(art);
	printf("searching for artist not in library:\n");
	art = search_artist(lib,"NULL");
	print_list(art);
	printf("\ntesting search_song:\n");
	printf("searching for bob the cat: amazon\n");
	struct playlist* song = search_song(lib,"bob the cat","amazon");
	print_item(song);
	printf("searching for song not in library:\n");
	song = search_song(lib,"NULL","NULL");
	print_item(song);

	printf("\ntesting delete:\n");
	printf("deleting apples on the tree: aaa\n");
	delete(lib,"apple on the tree","aaa");
	print_library(lib);
	printf("\ndeleting song not in the library:\n");
    delete(lib,"NULL","NULL");
	print_library(lib);
	printf("\n\ntesting shuffle:\n");
    shuffle(lib);
	printf("shuffling again\n");
	shuffle(lib);
	printf("testing clear:\n");
	printf("clearing library...\n");
    clear(lib);
	printf("printing library after cleared:\n");
	print_library(lib);

    return 0;
}
