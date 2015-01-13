//Zachary Rump
//ZRRM74
//Lab code: HAT
//RUNNER.C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "set.h"


//prototypes
Set *create_set(char *file);

int main(int argc, char **argv) {
	//input args are 2 input files & a number
	if(argc<4) 
	{
		printf("Error: not enough arguments.\nUsage: ./runner <input file 1> <input file 2> <number>\n"); return -1; 
	}
	char *file1 = (argv[1]);
	char *file2 = (argv[2]);
	int number = atoi(argv[3]);
	//use each file to build 2 sets
	Set *set1 = create_set(file1);
	print_set(set1);
	//alloc set 2
	Set *set2 = create_set(file2);
	//print set 2
	print_set(set2);
	//compute intersection
	Set *union_set = NULL; 
	union_set = set_intersection(set1, set2);
	//print intersection
	print_set(union_set);
	//remove input arg number from intersection 
	union_set = set_remove(union_set, number);
	//print updated intersection
	print_set(union_set);
	//free memory for all sets
//	free(file1);
//	free(file2);
	free_set(set1);
	free_set(set2);
//	free_set(union_set);
	//return
	return 0;
}

Set *create_set(char *filename) {
	//alloc set 1
	Set *set = NULL; 
	//open file 1
	FILE *file = fopen(filename, "r");
	assert(file != NULL);
	//build set 1
	while(!feof(file))
	{
		static int n=0;
		fscanf(file, "%d", &n);
		set = set_insert(set, n);
	}
	fclose(file);
	return set; 
}
