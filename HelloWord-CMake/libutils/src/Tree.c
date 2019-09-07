#include <libutils/Tree.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Three *left;
    struct Three *right;
};

void tree_print(struct Tree *root, size_t depth) {
    for (size_t i = 0; i < depth; ++i) {
        putchar(' ');
    }
    if (root) {
        printf("%d\n", root->data);
    } else {
        puts("NULL");
        return;
    }
    tree_print(root->left, depth + 1);
    tree_print(root->right, depth + 1);
}


struct Tree *create_tree(int data, struct Tree *left, struct Tree* right) {
    struct Tree* tree = malloc(sizeof(struct Tree));
    tree->data = data;
    tree->right = right;
    tree->left = left;
}