#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_ {
    int data;
    struct node_ *left;
    struct node_ *right;
} BST;

/**
 * param a: an int array
 * param low: the lowest valid indice in the array
 * param high: the highest valid indice in the array
 *
 * return: the root of a balanced BST
 *
 * This function should build a balanced bst from a sorted array. 
 * Hint: This function should look similar to binary search. 
 *
 * NOTES: Balanced BST tries to keep height as small as possible. 
 * Therefore we want to find the middle value of the array and make that the root of the tree
 */
BST* build_balanced_tree(int a[], int low, int high) {
	//base case
	if(low > high)
		return NULL;
	//get middle element and make it the root of the tree
	int midpoint = (low + high)/2;
	BST *bstRoot = malloc(sizeof(BST));
	assert(bstRoot != NULL);
	bstRoot->data = a[midpoint];
	//construct left tree recurisvely
	bstRoot->left = build_balanced_tree(a, low, midpoint-1);
	//construct right tree recursively
	bstRoot->right = build_balanced_tree(a, midpoint+1, high);
	return bstRoot;
}
	
    
void padding(char ch, int n) {
    int i;

    for (i = 0; i < n; ++i) {
        putchar(ch);
    }
}

void structure(BST* root, int level) {
    int i;

    if (root == NULL) {
        padding('\t', level);
        puts("~");
    } else {
        structure(root->right, level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        structure(root->left, level+1);
    }
}

int main(void) {
    
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    BST* root = build_balanced_tree(a, 0, 8);
    
    structure(root, 0);

    assert(root != NULL);
    assert(root->data == 5);
    assert(root->left != NULL);
    assert(root->left->data == 2);
    assert(root->left->left->data == 1);
    assert(root->left->left->left == NULL);
    assert(root->left->left->right == NULL);
    assert(root->left->right != NULL);
    assert(root->left->right->data == 3);
    assert(root->left->right->left == NULL);
    assert(root->left->right->right != NULL);
    assert(root->left->right->right->data == 4);
    assert(root->left->right->right->left == NULL);
    assert(root->left->right->right->right == NULL);
    
    assert(root->right != NULL);
    assert(root->right->data == 7);
    assert(root->right->left != NULL);
    assert(root->right->left->data == 6);
    assert(root->right->left->right == NULL);
    assert(root->right->left->left == NULL);
    assert(root->right->right != NULL);
    assert(root->right->right->data == 8);
    assert(root->right->right->left == NULL);
    assert(root->right->right->right != NULL);
    assert(root->right->right->right->data == 9);
    assert(root->right->right->right->left == NULL);
    assert(root->right->right->right->right == NULL);
    assert(root->right->right->left == NULL);

    printf("Yay!\n");

    return 0;
}
