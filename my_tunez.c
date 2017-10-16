#include <stdio.h>
struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
};
void print_list(struct song_node *p){
  while(p->next){ 
    printf("%d \n", p->next->data);
    p=p->next;
  }
}
  

struct song_node * insert_front(struct song_node *p, char n[256], char a[256]){
  struct song_node *newbie = malloc(sizeof(struct song_node));
  newbie->name = n;
  newbie->artist = a;
  newbie->next = p;
  return newbie;
}
struct song_node * insert(struct song_node *p, char n[256], char a[256]){
  while(p->next){
    if(strmp(p->next->name,n)<0){
     struct song_node *newbie= malloc(sizeof(struct song_node));
     newbie->name = n;
     newbie=atist = a;
     newbie->next = p->next;
     p->next = newbie;
     return newbie;
    }
    p=p_next;
  }
  return 0;
}
      
  

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
