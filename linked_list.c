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

void add_song(char * song, char * artist);
struct song_node * find_songz(char song[], char artist[]);
struct song_node * find_artistz(char artist[]);
void print_song(char artist[]);
void print_artist(char artist[]);
void print_library();
void shuffle();
void delete_song(char song[]);
void delete_all();

int letter_converter(char a){
  if(a == 'A'){
    return 1;
  }
  if(a == 'B'){
    return 2;
  }
  if(a == 'C'){
    return 3;
  }
  if(a == 'D'){
    return 4;
  }
  if(a == 'E'){
    return 5;
  }
   if(a == 'F'){
    return 6;
  }
  if(a == 'G'){
    return 7;
  }
  if(a == 'H'){
    return 8;
  }
  if(a == 'I'){
    return 9;
  }
  if(a == 'J'){
    return 10;
  }
   if(a == 'K'){
    return 11;
  }
  if(a == 'L'){
    return 12;
  }
  if(a == 'M'){
    return 13;
  }
  if(a == 'N'){
    return 14;
  }
  if(a == 'O'){
    return 15;
  }
   if(a == 'P'){
    return 16;
  }
  if(a == 'Q'){
    return 17;
  }
  if(a == 'R'){
    return 18;
  }
  if(a == 'S'){
    return 19;
  }
  if(a == 'T'){
    return 20;
  }
   if(a == 'U'){
    return 21;
  }
  if(a == 'V'){
    return 22;
  }
  if(a == 'W'){
    return 23;
  }
  if(a == 'X'){
    return 24;
  }
  if(a == 'Y'){
    return 25;
  }
   if(a == 'Z'){
    return 26;
  }
}

void add_song(char * song, char * artist){
  int place = letter_converter(song[0]);
  library[place] = insert(library[place], song, artist);
  //struct song_node * column = library[place];
  //insert(column, 
    }
struct song_node * find_songz(char song[], char artist[]){
  int place = letter_converter(song[0]);
  return find_song(library[place], artist, song);
}
struct song_node * find_artistz(char artist[]){
  int place = letter_converter(artist[0]);
  return find_artist(library[place], artist);
}

void print_song(char artist[]){
}
int main(){
  printf("%d\n", letter_converter('B'));
}

