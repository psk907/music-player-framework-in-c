
//NOT WORKING!!

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

