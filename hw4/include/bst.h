#ifndef BST_H_
#define BST_H_

typedef struct BST_ {
    int data;
    struct BST_ *left;
    struct BST_ *right;
} BST;

BST* build_balanced_tree(int a[], int low, int high);
void print(BST* root);
void padding(char ch, int n);
void structure(BST* root, int level);
void destroy_tree(BST* root);
#endif
