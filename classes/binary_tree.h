#include "note.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Binary_tree {
public:
    Note *root;

    Binary_tree(int first_val);

    int add(int data);

    void remove(int data);

    int get_max_len();

    void show_bt();

private:
    int recursion_add(Note *el, int data);
};

#endif
