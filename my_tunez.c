#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct song_node {
  char name[256];
  char artist[256]; 
  struct song_node *next;
};

void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *, char n[], char a[]);
struct song_node * node_index(struct song_node * p, int index);
struct song_node * insert(struct song_node *p, char n[], char a[]);
void insert_help(struct song_node *, char n[256], char a[256]);
struct song_node * free_list(struct song_node *p);
struct song_node * find_song(char artist[], char song[]);
struct song_node * find_artist(char artist[]);
struct song_node * random_song(struct song_node *);
void remove_song(struct song_node *);
struct song_node * insert_index(struct song_node *p, char n[256], char a[256], int index);


//struct song_node * insert_front(struct song_node *, char
void print_list(struct song_node *p){
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


//inserts node in order 
struct song_node * insert(struct song_node *p, char n[256], char a[256]){
  if(!p){
    return insert_front(p, n, a);
  }
  int counter = 0;
  while(p){
    if ((strcmp(p->artist, a) == 0 ) || (strcmp(p->artist,a) < 0)){
    counter +=1;
    p= p->next;
  }
  }
  /*while(p->next || (strcmp(p->artist, a) < 0)){
    counter += 1;
    p = p->next;
    }*/
  return insert_index(p, n, a, counter);
  /*struct song_node *front = p;
  while(p->next){
    if(strcmp(p->artist,a) == 0){
      if(strcmp(p->name, n) < 0){
	insert_help(p, n, a);
      }
    }
    if(strcmp(p->artist,a)<0){
	insert_help(p, n, a);
      }
    }
    p=p->next;
  insert_help(p,n,a);
  return front;*/
  
}

struct song_node * insert_index(struct song_node *p, char n[256], char a[256], int index){
  struct song_node *newbie= malloc(sizeof(struct song_node));
  strcpy(newbie->artist, a);
  strcpy(newbie->name, n);
  //get prev
  struct song_node *prev = node_index(p, index-1);
  struct song_node *nexto = node_index(p, index + 1);
  prev->next = newbie;
  newbie->next = nexto;
  return p;
}
  
  
/*void insert_help(struct song_node *p, char n[256], char a[256]){
  struct song_node *newbie= malloc(sizeof(struct song_node));
  newbie->next = p->next;
  strcpy(newbie->name,n);
  strcpy(newbie->artist,a);
  p->next = newbie;
  }*/
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

struct song_node * find_song(char artist[], char song[]){
  return 0;
}

struct song_node * find_artist(char artist[]){
  return 0;
}

struct song_node * random_song(struct song_node * song){
  return 0;
}

void remove_song(struct song_node * song){
}

int main(int argc, char *argv[]){
  struct song_node *yay = 0;
  printf("starting\n");
  yay=insert_front(yay, "woo", "hoo");
  yay= insert_front(yay, "How Far I'll Go", "Auli'i Cravalho");
  yay= insert(yay, "Single Ladies", "Beyonce" );
  // yay = insert(yay, "Countdown", "Beyonce");
  print_list(yay);
  printf("finishing\n");
  return 0;
}

