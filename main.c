#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "song_nodes.h"

int main(int argc, char *argv[]){
  struct song_node *yay = 0;
  printf("starting\n");
  yay=insert_front(yay, "woo", "hoo");
  yay= insert_front(yay, "How Far I'll Go", "Auli'i Cravalho");
  yay= insert(yay, "Single Ladies", "Beyonce" );
  yay = insert(yay, "Countdown", "Beyonce");
  print_list(yay);
  printf("testing to see if single ladies can be found: %p\n", find_song(yay, "Single Ladies", "Beyonce"));
  printf("testing to see if beyonce can be found: %p\n", find_artist(yay,"Beyonce"));
  //printf("%d", list_size(yay));
  printf("testing random song pointer: %p\n", random_song(yay));
  printf("finishing\n");
  return 0;
}
