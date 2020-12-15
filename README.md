# Data Structures in C Research Project
Music Playlists with LinkedLists

## FUNCTIONS
Let's start with an empty array called song_pool.
We shall store the songs extracted from our data set in the rawdata.csv file in this array.

In our menu, let the first option be 
1) create a song:
    - Take song details from user.
    - store them in pool[insert_index] 
    - Increment insert_index 
    - Ask if user wants to add to playlist, and do so accordingly
2) Show all songs
   - It'll print all songs in the pool
We'll 

3) Create/clear the playlist (Let's have only one playlist for now)   
   - ```
        if isEmpty()
            show create playlist option     
        otherwise
            show delete playlist option
        ```
4) Add song to playlist
    - Displays first 10 songs from the pool and then next 10 based on user choice
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

6) Shuffle Playlist
    - shuffle the given linkedlist
    - set nowPlaying to first item in the shuffled LL

7) Next/Prev Song
    - Change nowPlaying to next node or prev node
    - if nextNode or prev node is NULL, display relevant message.
    - Show the updated nowPlaying on screen.

8) Help
    - Display a nice hardcoded instruction sheet of all commands available

9) About
    - Show the team members, their GitHub URL's, this project's GitHub Repo and other details

X) Quit Music Player
    - ```
        for every song in song_pool[]:
            free(song)
        ```
    - free any other dynamically allocated resource
    - Display a thank you message
    

<hr />

## TEAM
- #### Suraj Kumar
- #### Trishi Reddy
- #### Sharath H

