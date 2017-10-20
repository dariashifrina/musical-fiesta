#include <stdio.h>
#include "my_tunez.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node * library[26];
void crt_lib(){
  int counter = 0;
  for(;counter<26;counter++){
    library[counter] = NULL;
  }
}

void add_song(struct song_node *);
struct song_node * find_songz(struct song_node *, char song[], char artist[]);
struct song_node * find_artistz(struct song_node *, char artist[]);
void print_song(char a);
void print_artist(char artist[]);
void print_library();
void shuffle();
void delete_song(char song[]);
void delete_all();

int letter_converter(char* a){
  return (int)(a - 65);
}

//void add_song(struct song_node * song){
// int place = (int)(
// }
struct song_node * find_songz(struct song_node * songnode, char song[], char artist[]){
  return 0;
}

int main(){
  printf("%c", letter_converter("B"));
}

