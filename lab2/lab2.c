// Zachary Rump
// ZRRM74/12337948
// 9/12/2014
// LAB E
// Lab 2
// Lab Code: "Black Tie"

#include <stdio.h>
//#include <string.h>

typedef struct { 
	char title[20];
	char author[20];
	int rating;
} Book;

#define MAX_LIBRARY_SIZE 30

//prototypes
int populate_array(Book library[], char *input);
void sort(Book library[], int length);
int binary_search(Book library[], int low, int high, int key);
void print(Book library[], int length, int key);
//bonus 
void author_sort(Book library[], int length);
void print_authsort(Book library[], int length); //so that the rating search result doesn't show up when printing the author_sorted version

int main(int argc, char *argv[]) {
	//main takes name of input file
	if(argc<2) //no input file provided
	{ printf("Not enough arguments \n"); return -1; }
	else 
	{
		Book book_array[MAX_LIBRARY_SIZE]; //declare array
		int length = populate_array(book_array, argv[1]); //populate array w/ data from input file, ignore any extraneous args. 
		//check for bad input argument
		if(length < 0) return -1;
		sort(book_array, length); //sort array for use w/ binary search
		//Read in "key" from user 
		printf("Enter a rating to search for: ");
		int key=0;
		scanf("%d", &key); 
		//binary search w/ key
		int key_index = binary_search(book_array, 0, length, key);
		//print library 
		print(book_array, length, key_index);
		//bonus
		printf("\n------ Bonus ------\n");
		author_sort(book_array, length);
		print_authsort(book_array, length);
		return 0;
	}	
}

int populate_array(Book library[], char *input) {
	//open input file and read contents into library array
	FILE *file = fopen(input, "r"); //open input file readonly
	if(file == NULL) { printf("Error opening file\n"); return -1; } //check for NULL ptr
	//first line in file is the library size
	int length=0;
	fscanf(file, "%d", &length);
	if(length > MAX_LIBRARY_SIZE) { length = MAX_LIBRARY_SIZE; }
	//read each line into array
	int i=0;
	for(i=0; i<length; i++)
	{
		fscanf(file, "%s", &library[i].title); //first title
		fscanf(file, "%s", &library[i].author); //second author
		fscanf(file, "%d", &library[i].rating); //third rating
	}
	//return number of books imported
	return length;
}

void sort(Book library[], int length) {
	Book book_temp;
	int pass=0;
	for(pass=1; pass<length; pass++) 
	{
		int i=0;
		for(i=0; i<(length-1); i++)
		{
			//sort in ascending order based on rating
			if(library[i+1].rating < library[i].rating) 
			{
				book_temp = library[i];
				library[i] = library[i+1];
				library[i+1] = book_temp;
			}
		}
	}
}

int binary_search(Book library[], int low, int high, int key) {
		if(low > high) return -1; //key not found
		//find midpoint
		int mid = (low + high)/2;
		if(library[mid].rating == key) 
		{
			return mid; //key found, return index
		}
		else if(key > library[mid].rating) 
		{
			return binary_search(library, mid+1, high, key);
		}
		else if(key < library[mid].rating)
		{
			return binary_search(library, low, mid-1, key);
		}
}	


void print(Book library[], int length, int key) {
	printf("\n");
	int i=0;
	for(i=0; i<length; i++)
	{
		if(i==key) printf("***"); //Mark the movie searched for if found
		printf("%s %s %d\n", library[i].title, library[i].author, library[i].rating);
	}
}

void print_authsort(Book library[], int length)
{
	printf("\n");
	int i=0;
	for(i=0; i<length; i++)
	{
		printf("%s %s %d\n", library[i].title, library[i].author, library[i].rating);
	}
}

void author_sort(Book library[], int length) { //sorts in alphabetical order (Uppercase first) by author and then title if same author
	Book book_temp;
	int pass=0;
	for(pass=1; pass<length; pass++)
	{
		int i=0;
		for(i=0; i<(length-1); i++)
		{
			int strc = strcmp(library[i].author, library[i+1].author);
			if(strc == 0)
			{ //same author sort by title
				if(strcmp(library[i].title, library[i+1].title) > 0)
				{
					//move str[i] down and str[i+1] up
					book_temp = library[i];
					library[i] = library[i+1];
					library[i+1] = book_temp;
				}
			} 
			else if(strc > 0) 
			{ //str[i] should be after str[i+1]
			 	book_temp = library[i]; //store val temporarily
			  	library[i] = library[i+1]; //move i+1 forward (up)
			 	library[i+1] = book_temp; //move stored value down
			}
		 }
	}
}


