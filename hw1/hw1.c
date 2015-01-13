#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 20
#define PLAYLIST_LEN 20
typedef struct {
    char artist[STRING_LEN];
    char title[STRING_LEN];
    char album[STRING_LEN];
    int rating;
} Song;


int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles);
int is_member(Song playlist[], int len, char* title);
void sort(Song playlist[], int len);
int do_swap(Song first, Song second);
void print(Song playlist[], int len);

/**
 * Example call
 *
 * ./a.out input1.txt input2.txt
 *
 * There can be any number of input files
 *  
 *
 * ./a.out input1.txt input2.txt . . . input1000.txt
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Incorrect number of command line arguments\n");
        printf("Correct usage: %s <input 1> <input 2> . . . <input n>\n", argv[0]);
        return -1;
    }
    
    Song playlist[PLAYLIST_LEN];

    int len = build_playlist(playlist, argv + 1, argc -1);

    if (len == -1) {
        printf("Invalid input: multiple songs with the same title\n");
        return 0;
    }

    sort(playlist, len);
    print(playlist, len);

    return 0;
}

/* Possible points : 15
 *
 * Param playlist  : An empty array of song structs
 * Param inputFile : An array of strings, each one representing one input file
 * Param numInputFiles : The number of files in the inputFile array
 *
 * return The length of the input file or -1 if the function fails
 *
 * This method should read the songs from each file into the playlist array. 
 * If there are more than PLAYLIST_LEN number of songs then only the the first 
 * PLAYLIST_LEN number of songs should be read in. This method will call the 
 * is_member function on each song. The playlist cannot hold duplicates and if
 * it discovers two songs with the same title then it should error out and 
 * return -1.
 *
 * IMPORTANT : Input files do not have their length at the top
 *  ex) 
 *
 * Beatles AbbeyRoad Because 10
 * Beatles Anthology1 Shout 12
 * . . . 
 */
int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles) {
    //for each input file 
    int i=0, linecount=0; //linecount stores total number of newlines among numInputFiles files.
    for(i=0; i<numInputFiles; i++)
    {
	int newlc=0; //stores newline count in any given file
	FILE *file = fopen(inputFiles[i], "r"); //open file ro
	if(file == NULL) { printf("Error bad file name\n"); return -1; } //check for bad filepath arg
	//count number of lines in file
	int c;
	while((c=fgetc(file)) != EOF) 
	{
		if(c=='\n') newlc++;
	}
	//reached eof so we have to close the file
	fclose(file); //close to re-open
	//add newlc to total linecount and make sure it doesn't exceed PLAYLIST_LEN
	if((linecount + newlc) > PLAYLIST_LEN)
	{
		newlc = (PLAYLIST_LEN - linecount); //if it exceeds PLAYLIST_LEN then only read new entries up until that length and break; 
	}
	//reopen file
	file = fopen(inputFiles[i], "r");
	if(file == NULL) { printf("Error bad file name\n"); return -1; }
	int j=0;
	for(j=linecount; j<(linecount+newlc); j++) //for loop to iterate struct array
	{
		Song songtmp; //temp struct to hold values
		fscanf(file, "%s %s %s %d", songtmp.artist, songtmp.album, songtmp.title, &songtmp.rating); //store values temporarily
		if(is_member(playlist, linecount, songtmp.title)) 
		 
			return -1; //duplicate song entry 
		else
			playlist[j] = songtmp; //store new song in playlist

	}
	fclose(file); //close file
	linecount += newlc; //add new total lines to linecount
    }
    return linecount; //return num of entries imported into playlist
}

/* Possible points : 10
 *
 * Param playlist : An array of songs
 * Param len : The number of songs in the param array
 * Param title : The title of a song
 *
 * return 1 if the title is already in the playlist array 0 otherwise
 */
int is_member(Song playlist[], int len, char* title) {
	int i=0;
    	for(i=0; i<len; i++) //for each title in array
    	{
		if((strcmp(title, playlist[i].title) == 0)) //strcmp returns 0 if strs are the same
		{
			return 1;
		}
	}
	return 0; //no matches
}
 
/* Possible points : 10
 *
 * Param playlist : a list of songs
 * Param len : the number of songs in the playlist array
 *
 * Sorts the playlist based off of artist, then album, and then title.
 * The do_swap method should be used to determine if two songs should be swapped
 */
void sort(Song playlist[], int len) { 
	int pass=0;
   	for(pass=1; pass<len; pass++)
   	{
		int i=0;
		for(i=0; i<(len-1); i++)
		{
			if(do_swap(playlist[i], playlist[i+1]))
			{
				Song temp = playlist[i];
				playlist[i] = playlist[i+1];
				playlist[i+1] = temp;
			}
		}
	}
}


/* Possible points : 10
 *
 * Param first : A song
 * Param second : A different song
 *
 * return 1 if the the songs should be swapped, 0 otherwise
 */
//uses strcmp to determine if Song first should be swapped with song second. 
int do_swap(Song first, Song second) { 
   //sort based on artist, album, then title
   int strc = strcmp(first.artist, second.artist); //first is [i] and second is [i+1] so we can just check if [i]>[i+1]   
   if(strc == 0) //if same artist
   {
	   //compare albums
	   strc = strcmp(first.album, second.album);
	   if(strc == 0) //if same album
	   {
		   //compare track titles
		   strc = strcmp(first.title, second.title);
		   //titles should never be equal because it is checked in build_playlist() by is_member()
		   if(strc > 0) //track comparison	
		   	{ return 1; } //if track first > track second; do swap   
		   else 
		   	{ return 0; }//first<second; no swap
	   }
	   else {
		   if(strc > 0) //otherwise albums are not the same
		   	{ return 1; }//if album of Song first is > song second then swap
	   	   else 
		   	{ return 0; }//album of first < second; don't swap
	   	}
   }
   else {
	   if(strc > 0) //artist compare
	   	{ return 1; } //artist first > artist second
   	   else 
		{ return 0; }
	}
}


/* Possible points : 5
 *
 * Param playlist : An array of songs
 * Param len : The number of songs in the playlist array
 * Prints out the sorted playlist
 * artists should have a padding of 10, abum a padding of 12, 
 * title a padding of 10 and rating a padding of 4
 */

void print(Song playlist[], int len) { 
	printf("Artist\tTitle\tAlbum\tRating\n");
	int i=0;
	for(i=0; i<len; i++)
	{
		printf("%10s\t%10s\t%12s\t%4d\n", playlist[i].artist, playlist[i].title, playlist[i].album, playlist[i].rating);
	}
}
