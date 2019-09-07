#include <stdio.h>

struct Tree;

void tree_print(struct Tree* root, size_t depth);

struct Tree *create_tree(int data, struct Tree *left, struct Tree* right);