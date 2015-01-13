typedef struct node_ {
    int data;
    struct node_* next;
}Set;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
 * This prelab you will implement a linkedlist that
 * represents a mathematical set; ie no duplicates
 *
 * When inserting into the set, you must first confirm that the
 * data is not currently in the set. If it is not, then it should be 
 * inserted into the head of the list. Otherwise, the head of the set
 * should be returned unchanged. 
 */
Set* insert(Set* set, int data);

int main(void) {

    Set* set = NULL;

    set = insert(set, 1);

    assert(set != NULL);
    assert(set->data == 1);
    
    set = insert(set, 2);

    assert(set->data == 2);
    
    set = insert(set, 1);

    assert(set->data == 2);
    assert(set->next->data == 1);
    assert(set->next->next == NULL);

    printf("You have completed the prelab\n");
}
