#ifndef BST_H_
#define BST_H_

typedef struct node_ {
    int data;
    struct node_ *left;
    struct node_ *right;
} BST;

BST* build_balanced_tree(int a[], int low, int high);
BST* delete_node(BST* root, int data);
BST* min(BST* root);
BST* mirror(BST* root);
void print(BST* root);
void padding(char ch, int n);
void structure(BST* root, int level); 
#endif
