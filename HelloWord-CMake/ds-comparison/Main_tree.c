#include <libutils/Tree.h>

int main() {
    struct Tree* t1 = create_tree(1, NULL, NULL);
    struct Tree* t3 = create_tree(3, NULL, NULL);
    struct Tree* t2 = create_tree(2, t1, t3);
    struct Tree* t6 = create_tree(6, NULL, NULL);
    struct Tree* t5 = create_tree(5, NULL, t6);
    struct Tree* t4 = create_tree(4, t2, t5);
    tree_print(t4, 0);
}