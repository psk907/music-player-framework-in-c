#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRING_SIZE 20



 typedef struct playlist {
    int song_num;// so that it can be deleted
    char pname[MAX_STRING_SIZE]// playlist name
    struct playlist* prevptr;
    char song_name[MAX_STRING_SIZE] data; // name of song
    struct playlist* nextptr;
}*head,*tail,*namet;

int main() 
{ 
   
    int choice;
    printf("Enter your choice:\n");
    printf("Press 1 to create a new playlist.\n"); 
    printf("Press 2 to add a song to an existing playlist.\n"); 
    printf("Press 3 to delete a playlist.\n");
    scanf("%d",choice);
    switch (choice) { 
    
    case 1: {
        
        create_playlist();
        printf("playlist was successfully created.\n"); 
        break;
         
        
    }
    case 2:{
        printf("\nchoose a playlist");
        break;
    }
    case 3:{
        printf("\nplaylist was successfully deleted");
        break;
    }
    
            
           
    
