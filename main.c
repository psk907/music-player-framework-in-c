#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 20

// Data Structure for an individual song [ FINAL ]
typedef struct _Song {
    char title[MAX_STRING_SIZE], artist[MAX_STRING_SIZE],album[MAX_STRING_SIZE];
    short int year;
    double duration;
    struct Song *prevTrack;
    struct Song *nextTrack;
} Song ;


// head points to the last song in the playlist(queue)
Song* head = NULL;

// tail points to the first song in the playlist(queue)
Song* tail = NULL; 

//Function to to check if the playlist is empty
bool isEmpty(){
    return head==NULL;
}

// nowPlaying points to the song currently playing
Song* nowPlaying = NULL;

Song* createSong (const char* title,const char* artist,const char* album,const int year,const double duration){
    Song* temp = malloc(sizeof(Song));
    strcpy(temp->title, title); 
    strcpy(temp->artist, artist); 
    strcpy(temp->album, album);
    temp->year=year;
    temp->duration=duration; 
    return temp;
}

int main(){
    char userChoice = '0';
    /* TODO : Write a menu based interface with options and in a loop 
        1. Add a new song to the playlist
            - take user inputs
            - call createSong
            -  assign it to a pointer
        X. End program
    */
    printf("MENU");
    
    Song *song= createSong("Dynamite","BST","Who knows?",2020,92);
    printf("%s",song->album);
    free(song);
    return 0;
}