#include "note.h"
#include "linked_list.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Binary_tree {
public:
    Note *root;

    Binary_tree(int first_val);

    int add(int d);

    void remove(int d);

    int get_height();

    void show_bt();

private:
    L_list *ll;

    int recursion_add(Note *el, int data);

    void go_through_for_remove(Note *el);

};

#endif
