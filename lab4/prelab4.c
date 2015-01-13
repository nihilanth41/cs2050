#include <assert.h>
#include <stdio.h>

int magic_numbers(int array[], int low, int high);

int main(void) {

    //This array has a magic number array1[2] == 2
    int array1[] = {-1, 0, 2, 4, 7, 9, 10};
    assert(magic_numbers(array1, 0, 6) == 2);

    //This array does not have a magic nubmer
    int array2[] = {-1, 0, 3, 4, 7, 9, 10};
    assert(magic_numbers(array2, 0, 6) == -1);

    printf("Congratulations! Your prelab works!\n");
    return 0;
}

/**
 * A magic number is any number in an array where its value is
 * equal to its indicie. For example; given the array 
 * {-1, 0, 2} the magic number is 2 because array[2] == 2. 
 * You should write a function that finds a magic number in 
 * a sorted array faster than linear time. This means that you
 * should not simply write a for loop and look at each value in
 * the array, you must be more clever. This function can be written
 * to find a magic number in an array of length n in time proportional
 * to log(n). 
 *
 * Param array An array of integers sorted in ascending order
 * Param low   The lowest indicie in the array to search 
 * Param high  The highest indicie in the array to search
 *
 * Return The magic number or -1 if one is not found
 */
int magic_numbers(int array[], int low, int high) {
	//array passed to function is already sorted
	//use binary search to check each number. 
	while(low<=high) { //for each element
		const int midpoint = (low+high)/2; //find the midpoint of low/high
		if(array[midpoint]==midpoint) //magic number found 
			return midpoint;
		else if(array[midpoint]<midpoint) //value < midpoint, search upper subset for higher value
			return magic_numbers(array, midpoint+1, high); 
		else if(array[midpoint]>midpoint) //value > midpoint, search lower subset for smaller value
			return magic_numbers(array, low, midpoint-1);
	}
	return -1; //magic number not found 
}



