# Music Player Framework in C

Music player Framework in C is a simple and efficient architecture that models the core functionality of modern day music player software such as Windows Media Player, VLC Media Player and Google Play Music.

The framework is capable of reading and engaging with locally stored song data which symbolize audio file formats such as MP3, AAC and OBB Vorbis. Designed purely in the C programming language, this framework is a demonstration of the versatility of early-day programming languages and features an elegant yet simple UI that's a tribute to the UNIX based systems of the 80's, enveloping the implementation that has been written to handle various levels of runtime exceptions.

### Literature Survey
The idea of implementing data structures in a music player was influenced by a  research paper titled - “New Implementation of Digital Jukebox in Data Structure By Using C++ Programming Language”, published by Manigandan Raamanathan from the Asia Pacific University, Malaysia. The paper was published by the International Journal of Advanced Research in Science and Engineering in Vol. No.6, Issue No.4 April 2017.The paper demonstrates an implementation of a “Digital Jukebox” using linked lists, queues and stacks in C++.

We have recreated the experience of  a simple music player that allows users to load a pool of songs from local storage and play tracks, create playlists and interact with it in a simple manner. The linked list data structure allows us to scrub through the entire playlist as per user’s instructions. To obtain a collection of songs we used the Spotify Developers API to save a CSV file of upto 100 songs’ metadata which we parse in our application to simulate the loading of songs from local storage. Our application features a simple menu based interface that allows all users to navigate with ease.

### Screenshots
<img src="https://github.com/psk907/music-player-framework-in-c/blob/master/screenshots/Menu.PNG?raw=true" height="250" />
(MAIN MENU)
<br />
<img src="https://github.com/psk907/music-player-framework-in-c/blob/master/screenshots/Songs_List.PNG?raw=true" height="250" />
(SONGS LIST)
<br />
<img src="https://github.com/psk907/music-player-framework-in-c/blob/master/screenshots/Create_Song.PNG?raw=true" height="220" />
(ADD A NEW SONG)
<br />
<img src="https://github.com/psk907/music-player-framework-in-c/blob/master/screenshots/Detailed_Overview.PNG?raw=true" height="200" />
(MORE INFO ABOUT SONG)
<br />
<img src="https://github.com/psk907/music-player-framework-in-c/blob/master/screenshots/Playlist.PNG?raw=true" height="200" />
(PLAYLIST)
<br />
<br/>
### Testing Instructions

1. Download the .zip of the repository(Click here) to your computer and extract it.
2. Unzip Working_Demo.zip to a new folder.
3. Run demo.exe (Windows) or demo.out (through terminal on Linux/MacOS).

Note:
 - You can find the source code in main.c
 - The sample dataset is in raw_data.csv



### TEAM
- #### Suraj Kumar
- #### Trishi Reddy
- #### Sharath H

