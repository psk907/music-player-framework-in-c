void add_to_pl(){
    int song_number = 0;
    printf("\nSelect a song to add from the list below");
    for (i = 0; i < 10 && song_pool[i] != NULL; i++)
    {
        printf("\n song no:%d,name:%s \n", (i + 1), song_pool[i]->title); // pool=array of song structures
        
    }
    printf("\nchoose a song number\n");
    scanf("%d", song_number);
    if (song_number > 0 && song_number <= 100)
    node_ptr temp = (node_ptr)malloc(sizeof(PlaylistNode));
    {
        if(header_node == NULL){
            
            temp->song = song_pool[song_number - 1];
            temp->prev_song = NULL;
            temp->next_song = NULL;
            header_node = temp;
            tail_node =temp->next_song; 
        }
            
            else if(header_node->next_song == NULL)
            {
                temp->song = song_pool[song_number - 1];
                header_node->next_song = temp;
                temp->prev_song =head;
                temp->next_song = NULL;
                
                
            }
        
            
        
        else{
            temp->song = song_pool[song_number - 1];
            tail_node=temp;
            temp->prev_song = tail_node;
            temp->next_song = NULL;
            tail_node=NULL;
            
            
        }
    }
}
void delete_playlist()
{
  while (header_node)
    {
      node_ptr current = header_node;
      while (current != NULL)
	{
	  node_ptr next = current->next_song;
	  free (current);
	  current = next;
	}
      header_node = NULL;
      printf ("the playlist was successfully deleted");
    }
  printf ("playlist does not exist, can't delete");

}
shuffle_pl(){
    split_pl()
        
{
        node_ptr slow, fast,header_node2;
        
        if(header_node->next_song==NULL) /*only one element*/
                return 0;
 
        slow=fast=header_node;
 
        while(fast->next_song!=NULL && fast->next_song->next_song!=NULL)
        {
                slow = slow->next_song;
                fast = fast->next_song->next_song;
        }
        header_node2 = slow->next_song;
        header_node2->prev_song=NULL;
        slow->link = NULL;
}

interleave()//partially works for even no of songs
{
     node_ptr current_node1,current_node2;
     for(current_node2=header_node2;header_node2->next_song !=0;header_node2=current_node2)
     {
         for(current_node1=header_node;header_node->next_song !=0;header_node=current_node1)
	 {
             current_node1=header_node->next_song;
             header_node->next_song=header_node2->next_song;
             header_node2->next_song=header_node;
             header_node->prev_song=header_node2;
             current_node2=header_node;
		 // display  the playlist if u want
          }
         
     }
    
}
printf("shuffled successfully");
    }
