#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 20

// Data Structure for an individual song [ FINAL ]
typedef struct _Song {
    char title[MAX_STRING_SIZE], artist[MAX_STRING_SIZE],album[MAX_STRING_SIZE];
    short int year;
    double duration;
    struct Song *prevTrack;
    struct Song *nextTrack;
} Song ;


Song* createSong (const char* title){
    //,const char* artist,const char* album,const int year,const double duration
    Song* temp = malloc(sizeof(Song));
    strcpy(temp->title, title); 
    return temp;
}

int main(){
    Song *song= createSong("Heyya");
    printf("%s",song->title);
    printf("Bye world");
    free(song);
    return 0;
}