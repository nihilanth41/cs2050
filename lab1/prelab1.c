#include <stdio.h>

#define MAX_ARG_LEN 20

//global array to store numbers
int numbers [MAX_ARG_LEN]; 

//struct ex
/*
typedef struct {
	

} structName

dereference struct -> shortcut

*/
//vs

//struct structName { };


//prototypes
int read_numbers_from_file(void);
float average(int length);
int find_max(int length);
void print_numbers(int length);

int main(void) {

	int length = read_numbers_from_file();
	print_numbers(length);
	float avg = average(length);
	int max = find_max(length);

	printf("The average of the list is %f\n", avg);
	printf("The largest number in the list is %d\n", max);

	return 0;
}

 int read_numbers_from_file(void) {
	//open file named data.txt readonly
	FILE *file = fopen("data.txt", "r");

	if(file==NULL)	return 0; //failed to open file	
	//first number of file is the number of numbers in the file.
	int size=0;
	fscanf(file, "%d", &size);
	int i;
	for(i=0; i<size; i++)
	{
		fscanf(file, "%d", &numbers[i]); //read each number into the array
	}
	fclose(file);
	return size;
}

float average(int length) {
	float avg = 0;
	int i;
	for(i=0; i<length; i++)
	{
		avg += numbers[i];
	}
	avg /= length;
	return avg;
}

int find_max(int length) {
	//assume no negative numbers
	int max = -1;
	int i=0;
	for(i=0; i<length; i++)
	{
		if(numbers[i] > max)
		{ 
			max = numbers[i];
		}
	}
	return max;
}

void print_numbers(int length) {
	int i=0;
	for(i=0; i<length; i++)
	{
		printf("%d\n", numbers[i]);
	}
	return;
}



