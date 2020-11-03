struct playlist{
  char name[100];
  char artist[100];
  struct playlist *next;
};

struct playlist* new_playlist(char* n, char* a);
struct playlist* insert_front(struct playlist* s, char* n, char* a);
struct playlist* insert_end(struct playlist* s, char* n, char* a);
struct playlist* insert_alpha(struct playlist* s, char* n, char* a);
void print(struct playlist* s);
struct playlist* find_song(struct playlist* s, char* n, char* a);
struct playlist* find_artist(struct playlist* s, char* a);
struct playlist* random(struct playlist* s);
struct playlist* remove(struct playlist* s, char* n, char* a);
struct playlist* free_playlist(struct playlist* s);
