#include <stdio.h>
//#include "my_tunez.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node * library[26];
void crt_lib(){
  int counter = 0;
  for(;counter<26;counter++){
    library[counter] = malloc(sizeof(struct song_node));
    library[counter] = NULL;
}
}

void add_song(char * song, char * artist);
struct song_node * find_songz(char song[], char artist[]);
struct song_node * find_artistz(char artist[]);
void print_song(char);
void print_artist(char artist[]);
void print_library();
void shuffle();
void delete_song(char song[],char artist[]);
void delete_all();

int letter_converter(char a){
  // char a = *b;
  if(a == 'A'){
    return 0;
  }
  if(a == 'B'){
    return 1;
  }
  if(a == 'C'){
    return 2;
  }
  if(a == 'D'){
    return 3;
  }
  if(a == 'E'){
    return 4;
  }
   if(a == 'F'){
    return 5;
  }
  if(a == 'G'){
    return 6;
  }
  if(a == 'H'){
    return 7;
  }
  if(a == 'I'){
    return 8;
  }
  if(a == 'J'){
    return 9;
  }
   if(a == 'K'){
    return 10;
  }
  if(a == 'L'){
    return 11;
  }
  if(a == 'M'){
    return 12;
  }
  if(a == 'N'){
    return 13;
  }
  if(a == 'O'){
    return 14;
  }
   if(a == 'P'){
    return 15;
  }
  if(a == 'Q'){
    return 16;
  }
  if(a == 'R'){
    return 17;
  }
  if(a == 'S'){
    return 18;
  }
  if(a == 'T'){
    return 19;
  }
   if(a == 'U'){
    return 20;
  }
  if(a == 'V'){
    return 21;
  }
  if(a == 'W'){
    return 22;
  }
  if(a == 'X'){
    return 23;
  }
  if(a == 'Y'){
    return 24;
  }
   if(a == 'Z'){
    return 25;
  }
}

void add_song(char * song, char * artist){
  int place = letter_converter(song[0]);
  library[place] = insert(library[place], song, artist);
  //struct song_node * column = library[place];
  //insert(column, 
    }

struct song_node * find_songz(char song[], char artist[]){
  int i;
  for(i = 0; i<26; i++){
    if(find_song(library[i], artist, song) != NULL){
      return find_song(library[i], artist, song);
}
}
  return NULL;
}

struct song_node * find_artistz(char artist[]){
  int i;
  for(i = 0; i<26; i++){
    if(find_artist(library[i], artist) != NULL){
      return find_artist(library[i], artist);
    }
  }
  return NULL;
}

void print_song(char a){
  print_listz(library[letter_converter(a)]);
}

void print_artist(char artist[]){
  // print_listz(find_artistz(artist));
  printf("Songs by %s\n",artist);
  int i;
  for(i = 0; i<26; i++){
    if(find_artist(library[i], artist) != NULL){
      printf("%s\n", find_artist(library[i], artist));
    }
  }
  /*struct song_node *current = library[letter_converter(artist[0])];
    if (current) {
      while (current -> next) {
	if (strcmp(current->artist,artist) == 0) {
	  printf("%s - %s\n",current->artist,current->name);
	}
	current = current->next;
      }
      if (strcmp(current->artist,artist) == 0) {
	printf("%s - %s\n",current->artist,current->name);
      }
      }*/
}
void print_library(){
  for(int i=0;i<26;i++){
    print_listz(library[i]);
  }
}
void shuffle(){
  printf("Shuffling:\n");
  for(int i=0; i<5; i++){
    srand(time(NULL) *i);
    int num = 26;
    while (num==26 || library[num] == NULL) {
      num = rand() % 26;
    }
    struct song_node *randomnode = NULL;
    while (randomnode == NULL) {
      randomnode = random_song(library[num]);
    }
    printf("%s - %s\n",randomnode->artist,randomnode->name);
}
  }

  
void delete_song(char song[],char artist[]){
  int i;
  for(i = 0; i<26; i++){
    if(find_song(library[i], artist, song) != NULL){
      struct song_node *remnode = find_song(library[i], artist, song);
      library[i] = remove_songz(library[i], remnode);
    }
  }
}

void delete_all() {
  int i;
  for (int i = 0; i < 26; i++) {
    free_all(library[i]);
    library[i] = 0;
  }
}
		  

