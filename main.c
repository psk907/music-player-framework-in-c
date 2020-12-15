#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 20

// Data Structure for an individual song [ FINAL ]
typedef struct _Song {
    char title[MAX_STRING_SIZE],album[MAX_STRING_SIZE];
    short int year;
    double duration;
    struct Song *prevTrack;
    struct Song *nextTrack;
} Song ;

typedef struct Song *songptr ;


// head points to the last song in the playlist(queue)
Song* first = NULL;

// tail points to the first song in the playlist(queue)
Song* last = NULL; 

//Function to to check if the playlist is empty
bool isEmpty(){
    return first==NULL;
}

// nowPlaying points to the song currently playing
Song* nowPlaying = NULL;

Song* createSong (const char* title ,const char* album,const int year,const double duration){
    Song* temp = malloc(sizeof(Song));
    strcpy(temp->title, title);  
    strcpy(temp->album, album);
    temp->year=year;
    temp->duration=duration; 
    return temp;
}
 songptr song_pool [100];
 
 void printSong(struct song**pool)
             {   
              int i;
              for( i = 0 ; i < 10 ; i++ )
              printf("%-40s    %-40s\n",pool[i]->title, pool[i]->album, pool[i]->year, pool[i]->duration);
             }

            
int main(){
    char userChoice='0' ;
    switch (userChoice)
    {
    case 1 : {
            struct Song  **pool = (struct Song**)malloc(100 * sizeof(struct Song*)); 
             int insert_index=0;
             
             for( insert_index = 0 ; insert_index < 100 ; insert_index++ )
            {
             printf("Enter the details of song %d\n", insert_index+1);
             char title[40], album[40];
             int year; 
             double duration; 
             scanf("Tittle: \n Album: %s%s",title, album);
             scanf("Year: %i",&year);
             scanf("Duration: %lf",&duration);
             createSong (title, album,year, duration);
             printf("\n");
             }
             
             
            break;

             }
    
    case 2 :{
            
             }     
             break;

    default:
       
              break;
    }

    printf("MENU");
    

}