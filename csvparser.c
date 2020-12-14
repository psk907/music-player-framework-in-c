//csv parser
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

Song *createSong(const char *title, const char *album, const int year, const double duration)
{
	songptr temp = malloc(sizeof(Song));
	strcpy(temp->title, title);
	// strcpy(temp->artist, artist);
	strcpy(temp->album, album);
	temp->year = year;
	temp->duration = duration;
	return temp;
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
		song_pool[i-1] = createSong(songname, album, 2000, duration);
		i++;
	}
	printf("%d songs added.\n\n", i);
	fclose(file);
}

int main()
{
	printf("START\n\n");
	readFromCSV();
	printf("Read from file complete\n");
	for (int i = 0; i < MAX_SONG_POOL && song_pool[i] != NULL; i++)
	{
		printf("%s \n", song_pool[i]->title);
		free(song_pool[i]);
	}

	printf("\n\nEND");
	return 0;
}