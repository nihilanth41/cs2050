//Zachary Rump
//ZRRM74
//Lab Code: Turkey
//LAB E
//LAB10 11/21/2014
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"

#define SIZE_MAX 100

void sort(int[], int);

int main(int argc, char **argv) {
	//read in 1 file
	if(argc < 3)
	{
		printf("Not enough arguments\n");
		printf("Usage is ./runner <filename> <number>\n");
		return -1;
	}
	char *filename = argv[1]; 
	int number = atoi(argv[2]);
	//first line of file is length
	FILE* fp = fopen(filename, "r");
	assert(fp != NULL);
	//record size of file
	int flen = 0;
	fscanf(fp, "%d", &flen);
	int a[SIZE_MAX]; 
	int i=0;
	for(i=0; i<flen; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	//close file
	fclose(fp);
	//make sure array is sorted
	sort(a, flen);
	//build a bst w/ numbers
	BST* bstPtr = build_balanced_tree(a, a[0], a[flen-1]);	
	//print bst
	print(bstPtr);
	//remove specified number
	bstPtr = delete_node(bstPtr, number);
	printf("\n");
	//print bst again
	printf("Tree without %d\n", number);
	print(bstPtr);
	//bonus part
	printf("\nBonus\n");
	print(mirror(bstPtr));
	return 0;
}

//function to sort array in ascending order
void sort(int a[], int len) {
	int pass;
	for(pass=1; pass<len; pass++)
	{
		int i;
		for(i=0; i<(len-1); i++)
		{
			if(a[i] > a[i+1])
			{
				int t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
			}
		}
	}
}
		

	
