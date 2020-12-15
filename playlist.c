#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//code for support
#define MAX_STRING_SIZE 100
#define MAX_SONG_POOL 100

typedef struct _Song *songptr;
typedef struct _Song
{
	char title[MAX_STRING_SIZE], album[MAX_STRING_SIZE];
	short int year;
	double duration;
	songptr prevTrack;
	songptr nextTrack;
} Song;

Song *song_pool[MAX_SONG_POOL];



int main()
{

    int choice;
    printf("Enter your choice:\n");
    printf("Press 1 to create a new playlist.\n");
    printf("Press 2 to add a song to an existing playlist.\n");
    printf("Press 3 to delete a playlist.\n");
    scanf("%d", choice);
    switch (choice)
    {

    case 1:
    {

        create_playlist();
        printf("playlist was successfully created.\n");
        break;
    }
    case 2:
    {
        printf("\nchoose a playlist");
        break;
    }
    case 3:
    {
        printf("\nplaylist was successfully deleted");
        break;
    }
    }
}
