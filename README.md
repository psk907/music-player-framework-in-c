# DSC Research Project

## TEAM
- #### Suraj Kumar
- #### Trishi Reddy
- #### Sharath H

## STUFF TO DO
Let's start with one empty array , where all Songs will be stored and an empty playlist (queue) .initialize the array( call it  pool ) with 100 empty memory locations using malloc , and create sone int insert_index = 0

In our menu, let the first option be 
1) create a song:
    - Take song details from user.
    - store them in pool[insert_index] 
    - Increment insert_index 
    - Ask if user wants to add to playlist, and do so accordingly
2) Show all songs
   - It'll print all songs in the pool
We'll 

3) Create/clear the playlist   
   - it'll show create if isEmpty()   , delete otherwise

4) Add song to playlist
    -  it'll show all songs in the pool 
    - prompt to enter song number 
    - that song will be added to the end of our queue 
    - How ? By setting it's 
         - nextSong = NULL
        - prevSong = end
        - end = address of this song u chose
    - ```
        if(isEmpty()) {
            nowPlaying = the song we just added  ,
            first = the song we just added 
        } 
        ```
    - So basically if playlist's empty and we add a song , It'll be the first and last song

5) Show Now Playing
   - show the details of the song which nowPlaying pointer is pointing to.

6) TBD