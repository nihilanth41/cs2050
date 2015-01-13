//Zachary Rump
//ZRRM74
//LAB 9
//Lab E
//Lab Code: LEGO
//11/7/2014
//RUNNER.C
#include "bst.h"

int main(int argc, char **argv) {
	//takes 2 input arguments
	if(argc < 3)
	{
		printf("Not enough arguments.\n");
		printf("Usage is ./runner <filename> <number> [<bonus>]\n");
		return EXIT_FAILURE;
	}
	//variables to hold input args
	char *filename = argv[1];
	int match_data = atoi(argv[2]);
			
	//declare BST ptr
	BST *bst = NULL;
	
	//open file
	FILE *fp = fopen(filename, "r");
	assert(fp != NULL); //do we have memory?
	
	//read each number out of input file
	char buf[100];
	while(fgets(buf, 100, fp) != NULL)
	{
		//convert string to integer 
		int data = atoi(buf);
		//insert integer into BST and set bst equal to the head node
		bst = insert(bst, data);
	}
	//close file
	fclose(fp);
	
	//print out BST
	print(bst);
	printf("\n");
	
	//search for int arg to main in BST 
	BST *match_node = find(bst, match_data);
	if(match_node == NULL)
		printf("%d was not found\n", match_data);
	else
		printf("%d was found\n", match_data);

	//bonus part
	if(argc > 3)
	{
		int nearest_int = atoi(argv[3]);
		BST *closestTree = nearest_to(bst, nearest_int);
		printf("%d is the closest number to %d\n", closestTree->data, nearest_int);
	}
	//destroy BST
	destroy_tree(bst);
	bst = NULL;

	return EXIT_SUCCESS;
}


