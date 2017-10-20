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
void delete_song(char song[],char artist[]);
void delete_all();

int letter_converter(char a){
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
  int place = letter_converter(artist[0]);
  return find_song(library[place], artist, song);
}
struct song_node * find_artistz(char artist[]){
  int place = letter_converter(artist[0]);
  return find_artist(library[place], artist);
}

void print_song(char letter){
  print_list(library[letter_converter(letter)]);
}

void print_artist(char[]artist){
  print_list(find_artistz);
}
void print_library(){
  for(int i=0;i<26;i++){
    print_list(library[i]);
  }
}
void shuffle(){
  for(int i=0; i>26; i++){
    printf("%s\n",randomsong(library[i]));
  }
  
  void delete_song(char song[],char artist[]){
    remove_song(find_songz(song,artist));
  }
  void delete_all(){
    for(int i=0;i<26;i++){
      free_list(library[i]);
    }
  }
		  
int main(){
  printf("%d\n", letter_converter('B'));
}

