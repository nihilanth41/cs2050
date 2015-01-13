//Zachary Rump
//12337948
//ZRRM74 
//August 29 2014
//Lab section E
//Lab code: Coffee
#include <stdio.h>

typedef struct {
	char title [20];
	int yearReleased;
	int sales;
	int ticketsSold;
} Movie;

#define MAX_ARR_LEN 20

Movie movie_catalog [MAX_ARR_LEN];

//prototypes
//lab 1
int populate_movie_catalog(void);
float average_ticket_price(int length);
int find_highest_grossing_movie(int length);
void print_catalog(int length);
//bonus
void sort(int length);

int main(void) {

	int length = populate_movie_catalog(); 
	if(length == -1) { printf("Error opening file\n"); return -1; } //check for null pointer 
	printf("List of Movies:\n");
	print_catalog(length);
	printf("\nAverage Ticket Price: %.2f\n", average_ticket_price(length));
	int high_gross_index = find_highest_grossing_movie(length);
	printf("Highest Grossing Movie: %s\n", movie_catalog[high_gross_index].title);
	
	//bonus
	printf("\n\n---------- Bonus ----------\n\n");
	sort(length);
	print_catalog(length);

	return 0;
}

int populate_movie_catalog(void) {
	//takes no args, returns number of movies loaded into movie catalog array
	//open file named data.txt readonly
	FILE *file = fopen("data.txt", "r");
	if(file==NULL)	return -1; //failed to open file	
	//first number of file is the number of movies in the file.
	int size=0; 
	fscanf(file, "%d", &size); //store number of movies in size
	if(size > MAX_ARR_LEN) { size = MAX_ARR_LEN; } //bounds checking
	int i=0;
	for(i=0; i<size; i++) 
	{
		fscanf(file, "%s", &movie_catalog[i].title); //first item is the movie title
		fscanf(file, "%d", &movie_catalog[i].yearReleased); //second item is the year released
		fscanf(file, "%d", &movie_catalog[i].sales); //third item is gross sales amount
		fscanf(file, "%d", &movie_catalog[i].ticketsSold); //number of tickets sold
	}
	fclose(file);
	return size;
}

float average_ticket_price(int length) {
	//takes length of movie_catalog array and returns average ticket price of all movies
	float avg_ticket_price = 0;
	int sales = 0;
	int i=0;
	for(i=0; i<length; i++)
	{
		float price = ((float)movie_catalog[i].sales)/((float)movie_catalog[i].ticketsSold); //get average price for each movie
		//float price = ((float)movie_catalog[i].sales)/movie_catalog[i].ticketsSold;
		//avg_ticket_price += price; //add the average for each movie to the total average 
		avg_ticket_price += price;
	}
	avg_ticket_price /= length; //divide by the number of movies in the catalog to find the average of all movies
	return avg_ticket_price;
}

int find_highest_grossing_movie(int length) {
	//takes length of movie_catalog array and returns the index of highest grossing movie in the movie catalog array
	int max_sales_index=-1, max_sales_amnt=0;
	int i=0;
	for(i=0; i<length; i++)
	{
		if(movie_catalog[i].sales>max_sales_amnt) 
		{ 
			max_sales_amnt = movie_catalog[i].sales; //record the highest amnt
			max_sales_index = i; //record index of highest amnt
		}
	}
	return max_sales_index; //return -1 if sales are not >=0 
}

void print_catalog(int length) {
	int i=0;
	for(i=0; i<length; i++)
	{
		printf("%s : %d\n", movie_catalog[i].title, movie_catalog[i].yearReleased);
	}
	return;
}

void sort(int length) { 
	Movie movie_temp; //struct variable to temporarily hold values
	int pass=0;
	for(pass=1; pass<length; pass++) { 
		int i;
		for(i=0; i<(length-1); i++)
		{
			if(movie_catalog[i].yearReleased > movie_catalog[i+1].yearReleased) { //sort in ascending order
				movie_temp = movie_catalog[i]; //store struct at current index 
				movie_catalog[i] = movie_catalog[i+1]; //move smaller value to the front
				movie_catalog[i+1] = movie_temp; //re-place stored value in i+1
			}
		}
	}
}

				
