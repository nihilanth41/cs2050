#ifndef SET_H_
#define SET_H_

typedef struct node_ { 
	int data; 
	struct node_* next;
} Set;

//prototypes
Set *set_insert(Set *set, int data);
Set *set_remove(Set *set, int data);
Set *set_intersection(Set *first, Set *second);
void print_set(Set *list);
void free_set(Set *list);

#endif
