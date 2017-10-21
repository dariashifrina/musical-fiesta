#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
  char name[256];
  char artist[256]; 
  struct song_node *next;
};

void print_listz(struct song_node *);
struct song_node * insert_front(struct song_node *, char n[256], char a[256]);
struct song_node * node_index(struct song_node * p, int index);
struct song_node * insert(struct song_node *p, char n[], char a[]);
void insert_help(struct song_node *, char n[256], char a[256]);
struct song_node * free_list(struct song_node *p);
struct song_node * find_song(struct song_node *p, char artist[], char song[]);
struct song_node * find_artist(struct song_node *p, char artist[]);
struct song_node * random_song(struct song_node *);
struct song_node * remove_songz(struct song_node *,struct song_node * song);
struct song_node * insert_index(struct song_node *p, char n[256], char a[256], int index);
//returns size of song_node
int list_size(struct song_node *p){
  struct song_node * copy = p;
  int counter = 0;
  while(copy){
    counter +=1;
    copy = copy->next;

  }
  return counter;
}

//struct song_node * insert_front(struct song_node *, char
void print_listz(struct song_node *p){
  while(p){
    printf("Song: %s Artist: %s\n", p->name, p->artist);
    p= p->next;
  }
  printf("\n");
}
//prints the entire list

//returns node to index
struct song_node * node_index(struct song_node *p, int index){
  int counter = 0;
  for(; counter < index; counter++){
    p = p -> next;
  }
  return p;
}

struct song_node * insert_front(struct song_node *p, char n[256], char a[256]){
  struct song_node *newbie = malloc(sizeof(struct song_node));
  strcpy(newbie->name, n);
  //printf("%s", newbie->name);
  strcpy(newbie->artist,a);
  //printf("inserting this artist front: %s", newbie->artist);
  newbie->next = p;
  return newbie;
}
//helper functions
int compare_artists(char a[256], struct song_node *p){
  return strcmp(a, p->artist);
}
int compare_names(char n[256], struct song_node *p){
  return strcmp(n, p->name);
}

//inserts node in order 
struct song_node * insert(struct song_node *p, char n[256], char a[256]){
  struct song_node * head = p;
  struct song_node * newbie = malloc(sizeof(struct song_node));
  strcpy(newbie->name, n);
  strcpy(newbie->artist,a);
  if(!p || (compare_artists(a,p)<0) || ((compare_artists(a, p) < 0) && ((compare_names(n, p)) < 0))){
    return insert_front(p, n, a);
  }
  while(p){
    // if artist are the same, name goes before
    if(p->next && compare_artists(a,p) && strcmp(n,p->next->name)<0 && !strcmp(a,p->next->artist)){
      newbie->next = p->next;
       p->next=newbie;
       return head;
    }
      // if the artist are the same, name goes after
    if (!(strcmp(a, p->artist))){
	if(strcmp(n, p->name) > 0){
	  newbie->next = p->next;
	  p->next=newbie;
	  return head;
	}
    }
    else{
      if((strcmp(a,p->artist)>0) && (!p->next ||strcmp(a,p->next->artist)<0)){
	newbie->next = p->next;
	p->next=newbie;
	return head;
      }
      p=p->next;
    }
  }
    newbie->next = p->next;
    p->next=newbie;
    return head;
}
    
	
    
  
       
// inserts node alphabetically
struct song_node * free_list(struct song_node *p){
  struct song_node *f = p;
  while(p->next){
    struct song_node *temp;
    temp = p->next->next;
    free(p->next);
    p->next=temp;
  }
  return f;
}

struct song_node * find_song(struct song_node* p, char artist[], char song[]){
  struct song_node *ret = malloc(sizeof(struct song_node));
  while(p){
    if(compare_names(song, p) == 0){
      ret = p;
      return ret;
    }
    p= p->next;
  }
  return NULL;
}
int find_song_index(struct song_node *p, char song[], char artist[]){
  int count=0;
  while(p){
    if(compare_names(song, p) == 0){
      return count;
    }
    count++;
    p=p->next;
  }
  return 0;
}

    

struct song_node * find_artist(struct song_node*p, char artist[]){
  struct song_node *ret = malloc(sizeof(struct song_node));
  while(p){
    if(compare_artists(artist, p) == 0){
      ret = p;
      return ret;
    }
    p= p-> next;
  }
  return 0;
}

struct song_node * random_song(struct song_node * song){
  srand(time(NULL));
  int wow = rand() % list_size(song);
  struct song_node * randomsong = node_index(song, wow);
  return randomsong;
}

struct song_node * remove_songz(struct song_node * current, struct song_node *song){
  if (current == song) {  
    current = current->next;
  }
  else{
    while (current != NULL) {
      if (current->next == song) {
	current->next = song->next;
      }
      current = current->next;
    }
  }
  song = NULL;
  free(song);
  return current;
}

void free_all(struct song_node *p) {
  struct song_node *temp;
  struct song_node *current = p;
  while (current) {
    temp = current->next;
    free(current);
    current = 0;
    current = temp;
  }
}
