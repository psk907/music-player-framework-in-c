#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SONG_POOL 100
#define MAX_STRING_SIZE 50

// Data Structure for an individual song [ FINAL ]
typedef struct Song *songptr ;
typedef struct Song {
    char title[MAX_STRING_SIZE],album[MAX_STRING_SIZE],uri[MAX_STRING_SIZE];
    short int year;
    double duration;
} Song ;

songptr song_pool[MAX_SONG_POOL];
//playlist stuff from here
typedef struct PlaylistNode *node_ptr;
typedef struct PlaylistNode
{
    int song_num;                // so that it can be deleted
    songptr song;
    node_ptr prev_song;
    node_ptr next_song;
} PlaylistNode;

node_ptr header_node = NULL, now_playing= NULL;

//Function to to check if the song pool is empty
bool is_pool_empty(){
    return song_pool[0]==NULL;
}

bool does_playlist_exist(){
    return !(header_node==NULL);
}

Song* createSong (const char* title ,const char* album,const int year,const double duration,const char* uri){
    Song* temp = malloc(sizeof(Song));
    strcpy(temp->title, title);  
    strcpy(temp->album, album);
    strcpy(temp->uri,uri);
    temp->year=year;
    temp->duration=duration; 
    return temp;
}
<<<<<<< HEAD
 songptr song_pool [100];
 
 /*void printSong(struct song**pool)
             {   
              int i;
              for( i = 0 ; i < 10 ; i++ )
              printf("%-40s    %-40s\n",pool[i]->title, pool[i]->album, pool[i]->year, pool[i]->duration);
             }*/

            
int main(){
    int userChoice ;
    scanf("%i"&userChoice);
=======

void create_playlist()
{
    int song_number, i, s;
    
    node_ptr temp = (node_ptr) malloc(sizeof(PlaylistNode));

    printf("\nSelect a song to add from the list below");
    for (i = 0; i < 10 && song_pool[i]!=NULL; i++) {
        printf("\n song no:%d,name:%s \n", song_number, song_pool[i]->title); // pool=array of song structures
    }

    printf("\nchoose a song number\n");
    scanf("%d", song_number);
    if (song_number > 0 && song_number <= 100)
    {
        temp->song = song_pool[song_number - 1];
        temp->prev_song = NULL;
        temp->next_song = NULL;
        header_node = temp;
    }
}

void readFromCSV()
{
	FILE *file = fopen("rawdata.csv", "r");
	if (file == NULL)
	{
		perror("Unable to open file");
		exit(1);
	}

	char line[1000];
	int i = 0;
	while (fgets(line, sizeof(line), file))
	{
		  
		char *token;
		token = strtok(line, ","); //tokenizes current line
		//printf("%s",token);
		char songname[MAX_STRING_SIZE];
		strcpy(songname, token);
		if (token != NULL)
		{ //reads through the tokenized line
			token = strtok(NULL, ",");
		}
		char releaseDate[MAX_STRING_SIZE];
		strcpy(releaseDate, token);
		if (token != NULL)
		{ //reads through the tokenized line
			token = strtok(NULL, ",");
		}
		char durationm[MAX_STRING_SIZE];
		strcpy(durationm, token);
		if (token != NULL)
		{ //reads through the tokenized line
			token = strtok(NULL, ",");
		}
		double duration = atoi(durationm) / 60.0;
		char id[MAX_STRING_SIZE];
		strcpy(id, token);
		if (token != NULL)
		{ //reads through the tokenized line
			token = strtok(NULL, ",");
		}
		char album[MAX_STRING_SIZE];
		strcpy(album, token);
		if (token != NULL)
		{ //reads through the tokenized line
			token = strtok(NULL, ",");
		}
		char uri[MAX_STRING_SIZE];
		strcpy(uri, token);
		if (token != NULL)
		{ //reads through the tokenized line
			token = strtok(NULL, ",");
		}
		//printf("Song read : %s  %s\n",songname,durationm);
		if (i == 0)
		{
			i++;
			continue;
		}
		song_pool[i-1] = createSong(songname, album, atoi(strstr(releaseDate,releaseDate+4)), duration,uri);
		i++;
	}
	printf("%d Songs added.\n\n", i);
	fclose(file);
}



            
int main(){
    char userChoice = '0';
    readFromCSV();
>>>>>>> e973bf298e766b67f47d36a5212aa2c5f281c2d7
    switch (userChoice)
    {
    case 1 : {
            struct Song  **pool = (struct Song**)malloc(100 * sizeof(struct Song*)); 
             int insert_index=0;
<<<<<<< HEAD
             
=======
             songptr song_pool [MAX_SONG_POOL];
>>>>>>> e973bf298e766b67f47d36a5212aa2c5f281c2d7
             for( insert_index = 0 ; insert_index < 100 ; insert_index++ )
            {
             printf("Enter the details of song %d\n", insert_index+1);
             char title[MAX_STRING_SIZE], album[MAX_STRING_SIZE];
             int year; 
             double duration; 
             scanf("Tittle: \n Album: %s%s",title, album);
             scanf("Year: %i",&year);
             scanf("Duration: %lf",&duration);
<<<<<<< HEAD
             createSong (title, album,year, duration);
=======
             song_pool[insert_index] = createSong (title, album, year, duration,"uri");
>>>>>>> e973bf298e766b67f47d36a5212aa2c5f281c2d7
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
    printf("\nRead from file complete\n");
	for (int i = 0; i < MAX_SONG_POOL && song_pool[i] != NULL; i++)
	{
		//printf("%s \n", song_pool[i]->title);
		free(song_pool[i]);
	}
    printf("Pool Memory freed\n");
	printf("\n\nEND");
	return 0;
    

}