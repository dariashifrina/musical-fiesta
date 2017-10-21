#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "my_tunez.h"
#include "linked_list.h"



int main(){
printf("~addings songs\n");
add_song("Dancing Queen", "ABBA");
add_song("Mamma Mia", "ABBA");
add_song("Countdown"," Beyonce");
add_song("Single Ladies", "Beyonce");
add_song("If I Were A Boy", "Beyonce");
add_song("Flawless", "Beyonce");
add_song("Umbrella", "Rihanna");
add_song("The Scientist", "Coldplay");
add_song("All Night", "Chance the Rapper");
add_song("POWER", "Kanye West");
add_song("Disturbia", "Rihanna");
add_song("Poker Face", "Lady Gaga");
add_song("The Sweet Escape", "Gwen Stefani");
add_song("Champion", "Kanye West");
add_song("What Makes You Beautiful", "One Direction");
add_song("Just The Way You Are","Bruno Mars");

printf("testing finding songs:\n");
printf("Pointer to Dancing Queen: %p\n",find_songz("Dancing Queen", "ABBA"));

printf("testing finding artists: \n");
printf("Pointer to Beyonce: %p\n", find_artistz("Beyonce"));

printf("TESTNG PRINT LIBRARY: \n");
print_library();
printf("DONE PRINTING LIBRARY\n\n");

printf("testing print all of songs under letter T:\n");
print_song('T');
printf("testing print all of songs under letter D:\n");
print_song('D');

printf("testing print all of artist's songs:\n");
print_artist("Beyonce");
	  
printf("testing shuffle:\n");
shuffle();

printf("testing remove song:\n");
delete_song("Countdown", "Beyonce");
print_library();

printf("testing remove all:\n");
delete_all();
print_library();

}
