#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
char * find_song(struct song_node *p, char artist[], char song[]);
char * find_artist(struct song_node *p, char artist[]);
char * random_song(struct song_node *);
void remove_song(struct song_node *, char song[], char artist[]);
struct song_node * insert_index(struct song_node *p, char n[256], char a[256], int index);
//returns size of song_node
int list_size(struct song_node *p){
  struct song_node * copy = p;
  int counter = 0;
  while(copy){
    counter +=1;
    copy = copy->next;
    printf("%d", counter);
  }
  return counter;
}

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

char * find_song(struct song_node* p, char song[], char artist[]){
  struct song_node *ret = malloc(sizeof(struct song_node));
  while(p){
    if(compare_names(song, p) == 0){
      ret = p;
      return ret->name;
    }
    p= p->next;
  }
  return 0;
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

    

char * find_artist(struct song_node*p, char artist[]){
  struct song_node *ret = malloc(sizeof(struct song_node));
  while(p){
    if(compare_artists(artist, p) == 0){
      ret = p;
      return ret->artist;
    }
    p= p-> next;
  }
  return 0;
}

char * random_song(struct song_node * song){
  srand(time(NULL));
  int wow = rand() * list_size(song);
  // printf("%d", list_size(song));
  struct song_node * randomsong = node_index(song, wow);
  return randomsong->name;
}

void remove_song(struct song_node * p, char song[],char artist[]){
  int i = find_song_index(p,song,artist);
  struct song_node * before = node_index(p,i-1);
  struct song_node * after = node_index(p, i+1);
  before->next=after;
  
  
}

