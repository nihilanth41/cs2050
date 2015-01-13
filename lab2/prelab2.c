#include <stdio.h>

int binary_search(int list[], int low, int high, int key);
int test(int expected, int real, char* msg);

/**
 * For this prelab you need to implement the binary search algorithm below. I 
 * have provided a template to fill out. Please do not modify main, it has been 
 * written to test your completed function. If running your program outputs 
 * 'All tests passed' then you are finished, otherwise it will give you a clue as 
 * to what is incorrect. It is strongly recomended that you attempt to implement 
 * the binary_search function recursively. 
 */
int main(void) {
	
	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	
	int failed_tests = 0;
	
	failed_tests += test(4, binary_search(list, 0, 9, 5), "Failed to find the midpoint");
	failed_tests += test(1, binary_search(list, 0, 9, 2), "Failed to find a number in the bottom half of the array");
	failed_tests += test(8, binary_search(list, 0, 9, 9), "Failed to find a number in the top half of the array");
	failed_tests += test(-1, binary_search(list, 0, 9, 100), "Found a number that does not exist");
	
	if (failed_tests == 0) {
		printf("All tests passed\n");
	} else {
		printf("%d %s failed\n", failed_tests, failed_tests == 1 ? "test" : "tests");
	}
}

int test(int expected, int real, char* msg) {
	if (expected == real) {
		return 0;
	}
	
	printf("Expected value: %d\nReal value: %d\n%s\n", expected, real, msg);
	return 1;
}

/**
 * Searchs for a value in a sorted list using the binary search algorithm
 * Param list : A list of integers in ascending sorted order
 * Param low : The lowest indicy in the provided list
 * Param high : The highest indicy in the provided list
 * Param key : The key to be searched for in the provided list
 * Return : The indicy of the key in the list, -1 if the key was not found 
 */
int binary_search(int list[], int low, int high, int key) {
	//TODO
	//list is already sorted in ascending order
	//split array into two by finding midpoint index
	int midpoint = (low + high)/2; 
	//determine whether key is in upper or lower sub-set
	while(low <= high) //?
	{
		if(list[midpoint] > key) 
		{
			return binary_search(list, low, midpoint-1, key); //recursive call to binary search for lower subset
		}
		else if(list[midpoint] < key)
		{
			return binary_search(list, midpoint+1, high,  key); //recursive call to binary search for upper subset
		}
		else if(list[midpoint] == key) //index found
		{ 
			return midpoint; 
		}
	}
	return -1; //key not found and low == high
}


