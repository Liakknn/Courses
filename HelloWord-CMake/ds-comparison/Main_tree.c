#include <libutils/Tree.h>
#include <libutils/List.h>

int main() {

    struct Tree *root = NULL;
    root = tree_insert(root, 1);
    root = tree_insert(root, 5);
    root = tree_insert(root, 9);
    root = tree_insert(root, 2);
    root = tree_insert(root, 3);
    root = tree_insert(root, 4);
    tree_print(root, 0);
    //tree_free(root);
}