#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SONG_POOL 100
#define MAX_STRING_SIZE 75

// Data Structure for an individual song [ FINAL ]
typedef struct Song *songptr;
typedef struct Song
{
    char title[MAX_STRING_SIZE], album[MAX_STRING_SIZE], uri[MAX_STRING_SIZE], id[MAX_STRING_SIZE];
    short int year;
    double duration;
} Song;

songptr song_pool[MAX_SONG_POOL];
int pool_insert_index = 0;

//playlist stuff from here
typedef struct PlaylistNode *node_ptr;
typedef struct PlaylistNode
{
    int song_num; // so that it can be deleted
    songptr song;
    node_ptr prev_song;
    node_ptr next_song;
} PlaylistNode;

node_ptr header_node = NULL, now_playing = NULL,node_ptr tail_node = NULL;

//Function to to check if the song pool is empty
bool is_pool_empty()
{
    return song_pool[0] == NULL;
}

bool does_playlist_exist()
{
    return !(header_node == NULL);
}

Song *createSong(const char *title, const char *album, const short int year, const double duration, const char *uri, const char *id)
{
    Song *temp = malloc(sizeof(Song));
    strcpy(temp->title, title);
    strcpy(temp->album, album);
    //strcpy(temp->uri, uri);
    strcpy(temp->id, id);
    temp->year = year;
    temp->duration = duration;
    pool_insert_index++;
    return temp;
}

void create_playlist()
{
    int song_number = 0, i = 0;

    node_ptr temp = (node_ptr)malloc(sizeof(PlaylistNode));

    printf("\nSelect a song to add from the list below");
    for (i = 0; i < 10 && song_pool[i] != NULL; i++)
    {
        printf("\n song no:%d,name:%s \n", (i + 1), song_pool[i]->title); // pool=array of song structures
    }

    printf("\nchoose a song number\n");
    scanf("%d", song_number);
    if (song_number > 0 && song_number <= 100)
    {
        temp->song = song_pool[song_number - 1];
        temp->prev_song = NULL;
        temp->next_song = NULL;
        header_node = temp;
        tail_node =temp->next_song ;
    }
}

void readFromCSV()
{
    FILE *file = fopen("rawdata.csv", "r");
    char line[1000];
    int i = 0;

    if (file == NULL)
    {
        perror("******\nUnable to load songs from data source");
        printf("Please check if rawdata.csv exists at the root directory of the application.\n");
        printf("You can still enter songs manually.\n******\n");
        printf("Error Message");
    }
    else
    {
        char songtitle[MAX_STRING_SIZE];
        char releaseDate[MAX_STRING_SIZE];
        int durationms;
        double duration = 0.0;
        char id[MAX_STRING_SIZE];
        char album[MAX_STRING_SIZE];
        char uri[MAX_STRING_SIZE];
        int year;
        while (fgets(line, sizeof(line), file) && pool_insert_index < MAX_SONG_POOL)
        {
            char *token;
            token = strtok(line, ","); //tokenizes current line with delimiter ',' and returns the first substring
            if (token == NULL)
                continue;
            strcpy(songtitle, token);
            token = strtok(NULL, ","); // get the next token
            strncpy(releaseDate, token + 1, 4);
            sscanf(releaseDate, "%d", &year);
            token = strtok(NULL, ",");
            char temp[MAX_STRING_SIZE];
            strncpy(temp, token + 1, 6);
            sscanf(temp, "%d", &durationms);
            duration = durationms / 60000.0;
            token = strtok(NULL, ","); // get the next token
            strcpy(id, token);
            token = strtok(NULL, ","); // get the next token
            strcpy(album, token);
            token = strtok(NULL, ","); // get the next token
            strcpy(uri, token);
            token = strtok(NULL, ","); // get the next token
            //printf("Song read : %s  %s\n",songname,durationm);
            if (i == 0)
            {
                i++;
                continue;
            }
            song_pool[i - 1] = createSong(songtitle, album, year, duration, "uri", id);
            i++;
        }
    }

    printf("%d Songs added.\n\n", i);
    fclose(file);
}

void user_song_input()
{
    short int add_another = 1;
    char songname[MAX_STRING_SIZE];
    short int year;
    int durationms;
    char id[MAX_STRING_SIZE];
    char album[MAX_STRING_SIZE];
    char uri[MAX_STRING_SIZE] = "uri";
    double duration = 0.0;

    while (add_another && pool_insert_index < MAX_SONG_POOL)
    {
        printf("\nEnter the details of the song you want to create.\n");
        printf("Title: \n");
        scanf("%s", songname);
        printf("Album: ");
        scanf("%s", album);
        printf("Year of release: ");
        scanf("%d", &year);
        printf("Duration(in s): ");
        scanf("%d", &durationms);
        duration = durationms / 60;
        song_pool[pool_insert_index] = createSong(songname, album, year, duration, "uri", "id");
        printf("\n%s has been created.\n\n", songname);
        printf("\nDo you want to create another song? (Enter 1 for yes and 0 for no)");
        scanf("%d", &add_another);
    }
}

void main_menu()
{
    printf("MENU\n");
    printf("0. Show options again\n");
    printf("1. Create a new song\n");
    printf("2. Display all available songs\n");
    printf("3. Create a playlist\n");
    printf("4. Add a song to the playlist\n");
    printf("-1. Exit music player\n");
}

void show_all_songs()
{
    for (int i = 0; i < MAX_SONG_POOL && song_pool[i] != NULL; i++)
        printf("%-1d %-3s %-3s %-3d %0.2lfmin\n", (i + 1), song_pool[i]->title, song_pool[i]->album, song_pool[i]->year, song_pool[i]->duration);
}

int main()
{
    short int userChoice = 0;
    char *terminate = "X";
    int wrong_choice_count = 0;
    readFromCSV();
    while (userChoice != -1)
    {
        switch (userChoice)
        {
        case 0:
        { //Show menu options
            main_menu();
            break;
        }
        case 1:
        {
            if (pool_insert_index >= MAX_SONG_POOL)
            {
                printf("Cannot add more songs.\n");
            }

            user_song_input();
            break;
        }
        case 2:
        {
            show_all_songs();
            break;
        }
        case 3:
            {
            create_playlist();
            printf(" playlist was successfully created"/n);
            break;
            }
        case 4:
            {
            add_to_pl();
            printf("  song was successfully Added to the playlist\n");
            break;
            }
                 
        default:
        {
            wrong_choice_count++;
            break;
        }
        }
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
    }
    for (int i = 0; i < MAX_SONG_POOL && song_pool[i] != NULL; i++)
        free(song_pool[i]);

    printf("\nPool Memory freed\n");
    printf("\n\nEND");
    return 0;
}
